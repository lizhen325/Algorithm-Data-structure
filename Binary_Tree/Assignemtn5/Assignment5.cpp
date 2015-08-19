#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/* implement the Tree class tree.
/* the contents of the Tree nodes can be of type char, so they can store operators (+, *, / and -) as well as digits (0,1,2...9) */
/* all the RPN*.txt test files contain numbers with single digits */
class tree
{
private:
	char data;
	tree *leftptr, *rightptr;
public:
	tree(char newthing, tree *l, tree *r);
	~tree(){};
	char rootdata(){ return data; }
	tree *left(){ return leftptr; }
	tree *right(){ return rightptr; }
};
tree::tree(char newthing, tree *l, tree *r)
{
	data = newthing;
	leftptr = l;
	rightptr = r;
}
/* implement your stack here*/
 //remember that the content of the stack is of type Tree 
struct Node {
	tree* data;
	Node *next;
};

class Stack {
private:                         //the data differs from the array
	Node *listpointer;
public:                          //the functions (methods) are identical
	Stack();
	~Stack();
	void Push(tree* newthing);
	void Pop();
	tree* Top();
	bool isEmpty();
};

Stack::Stack() {
	// constructor
	listpointer = NULL;
}

Stack::~Stack() {
	// destructor

}

void Stack::Push(tree* newthing) {
	// place the new thing on top of the stack
	Node *temp;
	temp = new Node;             //same as add node to front of linked-list
	temp->data = newthing;
	temp->next = listpointer;    //NOTE: no overflow problem
	listpointer = temp;
}
void Stack::Pop() {
	// remove top item from the stack
	Node *p;
	p = listpointer;
	if (listpointer != NULL) {     //        check to avoid underflow
		listpointer = listpointer->next;
		delete p;                //always delete a TEMPORARY variable
	}
}

tree* Stack::Top() {
	// return the value of the top item
	return listpointer->data;
}

bool Stack::isEmpty() {
	// returns true if the stack is empty
	if (listpointer == NULL) {
		return true;
	}
	return false;
}
Stack S;
// in-fix notation
void inOrder_with_Stacks(tree *T) {
	//Stack S;
	tree* temp = T;
	while (temp != NULL){
		while (temp != NULL){
			if (temp->right() != NULL) S.Push(temp->right());
			S.Push(temp);
			temp = temp->left();
		}
		temp = S.Top();
		S.Pop();
		while (S.isEmpty() == false && temp->right() == NULL){
			cout << temp->rootdata() << " ";
			temp = S.Top();
			S.Pop();
		}
		cout << temp->rootdata() << " ";
		if (S.isEmpty() == false){
			temp = S.Top();
			S.Pop();
		}
		else temp = NULL;
	}
}
//post-fix notation
void postOrder_with_Stacks(tree *t) {
	Stack S;
	tree* temp1, *temp2;
	temp1 = t;
	temp2 = t;
	while (temp1 != NULL){
		while (temp1->left() != NULL){
			S.Push(temp1);
			temp1 = temp1->left();
		}
		while (temp1->right() == NULL || temp1->right() == temp2){
			cout << temp1->rootdata() << " ";
			temp2 = temp1;
			if (S.isEmpty() == true) return;
			temp1 = S.Top(); S.Pop();
		}
		S.Push(temp1);
		temp1 = temp1->right();
	}
	cout << endl;
}

int main(int argc, char** argv){//get filename from arguments
	tree *T1, *T2, *T;
	char digit;
	char oper;
	char expression[100];
	ifstream input_file;
	argv[1] = "C:/Users/zhenli/Desktop/159201/Assignments/5/RPN3.txt";
	input_file.open(argv[1]);
	if (!input_file.good()){
		cout << "cannot read file " << argv[1] << endl;
		exit(0);
	}
	/* both operator and digits are of type char */
	while (!input_file.eof())
	{
		while (input_file >> expression){
			if (isdigit(expression[0])){
				stringstream line(expression);
				line >> digit;
				cout << "reading number " << digit << endl;
					//modify deal with the Stack
					T = new tree(digit, NULL, NULL);
					S.Push(T);
			}
			else {
				stringstream line(expression);
				line >> oper;
				printf("reading an operator: %c \n", oper);
				//modify deal with the Stack
				T2 = S.Top();
				S.Pop();
				T1 = S.Top();
				S.Pop();
				T = new tree(oper,T1,T2);
				S.Push(T);
			}
		}	
	}
	S.Pop();
	//Now we can traverse the tree in a certain way and print the expression
	//in-order with parenthesis
	cout << "in-fix notation: ";
	inOrder_with_Stacks(T);
	cout << endl;
	//post-order
	cout << "post-fix notation: ";
	postOrder_with_Stacks(T);
	cout << endl;
	system("pause");
	return 0;
}

