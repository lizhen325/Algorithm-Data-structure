#include <iostream>

using namespace std;


class tree
{
private:
	char data;
	tree *rightptr, *leftptr;
public:
	tree(char newthing, tree *l, tree *r);
	~tree();
	char rootdata(){ return data;}
	tree *left(){ return leftptr; }
	tree *right(){ return rightptr;}
};

tree::tree(char newthing, tree *l, tree *r)
{
	data = newthing;
	leftptr = l;
	rightptr = r;
}

void inorder(tree *T)
{
	if (T == NULL) return;
	inorder(T->left());
	cout << T->rootdata() << ",";
	inorder(T->right());
}

void postorder(tree *T)
{
	if (T == NULL) return;
	postorder(T->left());
	postorder(T->right());
	cout << T->rootdata() << ",";
}
void preorder(tree *T)
{
	if (T == NULL) return;
	cout << T->rootdata() << ",";
	preorder(T->left());
	preorder(T->right());
}

struct Node
{
	tree *data;
	Node *next;
};

class stack
{
private:
	Node *listpointer;
public:
	stack();
	~stack();
	void push(tree *newhing);
	void pop();
	tree *top();
	bool isempty();
};
stack::stack()
{
	listpointer = NULL;
}
stack::~stack()
{

}
void stack::push(tree *newthing)
{
	Node *temp;
	temp = new Node;
	temp->data = newthing;
	temp->next = listpointer;
	listpointer = temp;
}
void stack::pop()
{
	Node *temp;
	temp = listpointer;
	if (listpointer != NULL)
		listpointer = listpointer->next;
	delete temp;
}
tree *stack::top()
{
	return listpointer->data;
}
bool stack::isempty()
{
	if (listpointer == NULL) return true;
	return false;
}
void preorder_stack(tree *T)
{
	stack S;
	tree *temp = T;
	if (temp != NULL)S.push(temp);
	while (S.isempty() == false){
		temp = S.top();
		S.pop();
		cout << temp->rootdata() << ",";
		if (temp->right() != NULL)
			S.push(temp->right());
		if (temp->left() != NULL)
			S.push(temp->left());
	}
}
void inorder_stack(tree *T)
{
	stack S;
	tree* temp = T;
	while (temp != NULL){
		while (temp != NULL){
			if (temp->right() != NULL) S.push(temp->right());
			S.push(temp);
			temp = temp->left();
		}
		temp = S.top();
		S.pop();
		while (S.isempty() == false && temp->right() == NULL){
			cout << temp->rootdata() << " ";
			temp = S.top();
			S.pop();
		}
		cout << temp->rootdata() << " ";
		if (S.isempty() == false){
			temp = S.top();
			S.pop();
		}
		else temp = NULL;
	}
}
void postorder_stacks(tree *T) {
	stack S;
	tree* temp1, *temp2;
	temp1 = T;
	temp2 = T;
	while (temp1 != NULL){
		while (temp1->left() != NULL){
			S.push(temp1);
			temp1 = temp1->left();
		}
		while (temp1->right() == NULL || temp1->right() == temp2){
			cout << temp1->rootdata() << " ";
			temp2 = temp1;
			if (S.isempty() == true) return;
			temp1 = S.top(); S.pop();
		}
		S.push(temp1);
		temp1 = temp1->right();
	}
}
tree *T1, *T2, *T3, *T4, *T5, *T6, *mytree;

int main()
{
	T1 = new tree ('F', NULL, NULL);
	T2 = new tree ('G', NULL, NULL);
	T3 = new tree ('C', T1, T2);
	T4 = new tree ('D', NULL, NULL);
	T5 = new tree ('E', NULL, NULL);
	T6 = new tree ('B', T4, T5);
	mytree = new tree ('A', T6, T3);
	cout << "InOrder : ";
	inorder(mytree);
	cout << endl;
	cout << "PostOrder : ";
	postorder(mytree);
	cout << endl;
	cout << "PreOrder : ";
	preorder(mytree);
	cout << endl;
	cout << "/////////////////////////////////////" << endl;
	cout << "using stack";
	cout << endl;
	cout << "preorder using stack: ";
	preorder_stack(mytree);
	cout << endl;
	cout << "inorder using stack: ";
	inorder_stack(mytree);
	cout << endl;
	cout << "postorder using stack : ";
	postorder_stacks(mytree);
	cout << endl;
	system("pause");
	return 0;
}