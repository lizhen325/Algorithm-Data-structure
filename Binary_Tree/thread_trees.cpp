#include <iostream>

using namespace std;


class Tree {
private:
	char data;
	Tree *leftptr, *rightptr;
	bool lthread, rthread;  // two new variables
public:
	Tree(char newthing, Tree* L, Tree* R);  // constructor with paramters
	~Tree() { }
	char RootData() { return data; }  // inline functions
	Tree* Left() { return leftptr; }
	Tree* Right() { return rightptr; }
	bool IsEmpty();
	bool LeftThread() { return lthread; }  // two new methods
	bool RightThread() { return rthread; }
	void Threadbyhand(Tree* T, Tree* tprevious, Tree* tnext);
};

Tree::Tree(char newthing, Tree* L, Tree* R) {
	data = newthing;
	leftptr = L;
	rightptr = R;
	lthread = false;
	rthread = false;
}

void Tree::Threadbyhand(Tree* T, Tree* tprevious, Tree* tnext){
	//add the threads by hand
	if (T->leftptr == NULL) { T->leftptr = tprevious; T->lthread = true; }
	else{
		if (tprevious != NULL) { printf("ops, error in the thread \n"); exit(0); }
	}
	if (T->rightptr == NULL) { T->rightptr = tnext; T->rthread = true; }
	else{
		if (tnext != NULL){ printf("ops, error in the thread \n"); exit(0); }
	}
}

bool Tree::IsEmpty(void){
	if (leftptr == NULL && rightptr == NULL) return true;
	else return false;
}

Tree *NextNode(Tree *N) {
	Tree *temp;
	if (N->RightThread()) { return N->Right(); }
	temp = N->Right();
	while (temp->LeftThread() == false) {
		temp = temp->Left();
	}
	return temp;
}

void InOrder(Tree *T) {
	Tree *current;
	if (T->IsEmpty()) { return; }
	// first get current to the starting node
	current = T;
	while (current->LeftThread() == false) {
		current = current->Left();
	}
	cout << current->RootData() << endl;
	// now perform the in-order traversal
	while (current->Right() != current) {
		// *** visit the current node ***
		current = NextNode(current);
		cout << current->RootData() << endl;
	}
}

Tree *T1, *T2, *T3, *T4, *T5, *T6, *T7, *T8, *T9;
Tree *myTree;

int main() {
	//we just want to construct a tree by hand, so the threads are added by hand as well
	T1 = new Tree('C', NULL, NULL);
	T2 = new Tree('E', NULL, NULL);
	T3 = new Tree('H', NULL, NULL);
	T4 = new Tree('D', T1, T2);
	T5 = new Tree('I', T3, NULL);
	T6 = new Tree('A', NULL, NULL);
	T7 = new Tree('B', T6, T4);
	T8 = new Tree('G', NULL, T5);
	myTree = new Tree('F', T7, T8);
	//add the treads now
	T6->Threadbyhand(T6, T6, T7);//A,A,B
	T1->Threadbyhand(T1, T7, T4);//C,B,D
	T2->Threadbyhand(T2, T4, myTree);//E,D,F
	T8->Threadbyhand(T8, myTree, NULL);//G,F,NOT
	T3->Threadbyhand(T3, T8, T5);//H,G,I
	T5->Threadbyhand(T5, NULL, T5);//I,NOT,I

	cout << "inorder" << endl;
	InOrder(myTree);
	cout << endl;
	system("pause");
	return 0;
}
