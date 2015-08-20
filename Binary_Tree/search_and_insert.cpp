#include <iostream>

using namespace std;

class tree
{
private:
	int data;
	tree *leftptr, *rightptr;
public:
	tree(int newthing, tree *l, tree *r);
	~tree();
	int rootdata(){ return data; }
	tree *left(){ return leftptr; }
	tree *right(){ return rightptr; }
	void insert(int item);
	void search(int item);
	bool Search(int item);
};
tree::tree(int newthing, tree *l, tree *r)
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
//insert iterative
void tree::insert(int item) {
	// BST must already contain at least one item
	// An iterative approach follow:
	tree *current = this;
	while (current != NULL){
		if (item > current->data) {  // move to the right
			if (current->rightptr == NULL) {
				current->rightptr = new tree(item, NULL, NULL);
				return;
			}
			else {
				//rightptr->Insert(item);
				current = current->rightptr;
			}
		}
		else {
			if (item < current->data) {  // move to the left
				if (current->leftptr == NULL) {
					current->leftptr = new tree(item, NULL, NULL);
					return;
				}
				else {
					//leftptr->Insert(item);
					current = current->leftptr;
				}
			}
			else {
				if (item == current->data) {  // should be unique
					printf("Error: key is not unique\n");
					exit(9);
				}
			}
		}
	}
}
//insert number
void tree::insert(int item)
{
	if (item > data)
	{
		if (rightptr == NULL)
			rightptr = new tree(item, NULL, NULL);
		else
			rightptr->insert(item);
	}
	else if (item < data)
	{
		if (leftptr == NULL)
			leftptr = new tree(item, NULL, NULL);
		else
			leftptr->insert(item);
	}
	else if (data == item)
		cout << "Error: key is not unique";
}
//search iterative
bool tree::Search(int item){
	tree *current = this;
	while (current != NULL){
		if (current->data == item) return true;
		else{
			if (item > current->data) {//move to the right
				current = current->rightptr;
			}
			else if (item < current->data) {//move to the left
				current = current->leftptr;
			}
		}
	}
	return false;//didn't find it

}
//search by number
void tree::search(int item)
{
	tree *T = NULL;
	if (item == data) cout << "found item in root";
	else
	{
		if (item > data) T = rightptr;
		if (item < data) T = leftptr;
		while (T != NULL)
		{
			if (T->data == item)
			{
				cout << "you are looing for " << T->data <<" is found in the tree" << endl;
				return;
			}
			else
			{
				if (item > T->data)
					T = T->right();
				else if (item < T->data)
					T = T->left();
			}
		}
		cout << "cannot find the value" << endl;
	}
}
//search by pointer
tree* SearchbyPointer(tree* T, int item){
	tree* temp;
	if (item > T->rootdata()) {  // move to the right
		if (T->right() == NULL) {
			return NULL;
		}
		else {
			temp = SearchbyPointer(T->right(), item);
			if (temp != NULL) return temp;//RECURSION
			else return NULL;
		}
	}
	else {
		if (item < T->rootdata()) {  // move to the left
			if (T->left() == NULL) {
				return NULL;
			}
			else {
				temp = SearchbyPointer(T->left(), item);
				if (temp != NULL) return temp;//RECURSION
				else return NULL;
			}
		}
		else {
			if (item == T->rootdata()) {
				//printf("FOUND\n");
				return T;
			}
		}
	}
}
//search largest value in a tree
int search_largest_value(tree *T)
{
	tree *current = T;
	if (current == NULL) return 0;
	while (current->right() != NULL)
		current = current->right();
	return current->rootdata();
}
tree *T1, *T2, *T3, *T4, *T5, *T6, *mytree;

int main()
{
	T1 = new tree(2, NULL, NULL);
	T2 = new tree(18, T1, NULL);
	T3 = new tree(22, NULL, NULL);
	T4 = new tree(87, NULL, NULL);
	T5 = new tree(46, T3, T4);
	mytree = new tree(20, T2, T5);
	cout << "inorder: " << endl;
	inorder(mytree);
	cout << endl;
	cout << "after inserting 5: " << endl;
	mytree->insert(5);
	inorder(mytree);
	cout << endl;
	mytree->search(5);
	cout << search_largest_value(mytree) << endl;
	system("pause");
	return 0;
}
