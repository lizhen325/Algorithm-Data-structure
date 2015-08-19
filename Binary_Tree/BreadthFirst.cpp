#include <iostream>
using namespace std;

/***************************************************************/
/*************** Tree class (Binary Tree) **********************/
/***************************************************************/

class Tree {
private:
	char data;
	Tree *leftptr, *rightptr;

public:
	Tree(char newthing, Tree* L, Tree* R);  // constructor with paramters
	~Tree() { }
	char RootData() { return data; }  // inline functions
	Tree* Left() { return leftptr; }
	Tree* Right() { return rightptr; }
};

Tree::Tree(char newthing, Tree* L, Tree* R) {
	data = newthing;
	leftptr = L;
	rightptr = R;
}


/***************************************************************/
/*************** Queue of Tree pointers ************************/
/***************************************************************/

struct Node {
	Tree* data;
	Node *next;
};

class Queue {
private:
	Node *front, *rear;

public:
	Queue();
	~Queue();
	void Join(Tree* newthing);
	void Leave();
	Tree* Front();
	bool isEmpty();
	void Print();
};


Queue::Queue() {
	// constructor
	front = NULL;  rear = NULL;
}

Queue::~Queue() {
	// destructor
}

void Queue::Join(Tree* newthing) {
	// place the new thing at the rear of the queue
	Node *temp;
	temp = new Node;
	temp->data = newthing;
	temp->next = NULL;
	if (rear != NULL) { rear->next = temp; }
	rear = temp;
	if (front == NULL) { front = temp; }
}


void Queue::Leave() {
	// remove the front item from the queue
	Node * temp;
	if (front == NULL) { return; }
	temp = front;
	front = front->next;
	if (front == NULL) { rear = NULL; }
	delete temp;
}

Tree* Queue::Front() {
	// return the value of the front item
	if (front != NULL) { return front->data; }
	return 0;
}

bool Queue::isEmpty() {
	// return true if the queue is empty
	if (front == NULL) { return true; }
	return false;
}


/***************************************************************/
/*************** Breadth-first traversal using Queues  ********/
/***************************************************************/

void Breadth_First(Tree* root){
	Queue Q;//a queue of Tree *
	Tree *temp;
	temp = root;
	if (temp != NULL){
		Q.Join(temp);
		while (Q.isEmpty() == false){
			temp = Q.Front();
			Q.Leave();
			cout << temp->RootData();
			if (temp->Left() != NULL){
				Q.Join(temp->Left());
			}
			if (temp->Right() != NULL){
				Q.Join(temp->Right());
			}
		}
	}
}


/******************* TREE *************************/

Tree *T1, *T2, *T3, *T4, *T5, *T6, *T7, *T8, *T9;
Tree *myTree;

int main() {

	T1 = new Tree('G', NULL, NULL);
	T2 = new Tree('D', NULL, T1);
	T3 = new Tree('B', T2, NULL);
	T4 = new Tree('I', NULL, NULL);
	T5 = new Tree('H', T4, NULL);
	T6 = new Tree('F', NULL, T5);
	T7 = new Tree('E', NULL, NULL);
	T8 = new Tree('C', T7, T6);
	myTree = new Tree('A', T3, T8);

	cout << "pringting tree per node level" << endl;
	Breadth_First(myTree);
	cout << endl;
	system("pause");
	return 0;

}
