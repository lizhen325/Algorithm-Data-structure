// concatenance and split two linked list
// search by key value and position to remove element and insert value after key value 

#include <iostream>

using namespace std;

struct Node {
	int number;
	float balance;
	Node *next;
};
// add value
void addnode(Node *&listpointer, int a, float b)
{
	Node *temp;
	temp = new Node;
	temp->number = a;
	temp->balance = b;
	temp->next = listpointer;
	listpointer = temp;
}
// print the values
void printll(Node *listpointer)
{
	Node *temp;
	temp = listpointer;
	while (temp != NULL)
	{
		cout << temp->number << "," << temp->balance << endl;
		temp = temp->next;
	}
}
// concatenace two linked list
void concatenance(Node *&listpointer1, Node *&listpointer2)
{
	Node *current, *prev;
	current = listpointer1;
	prev = NULL;
	while (current != NULL)
	{
		prev = current;
		current = current->next;
	}
	if (prev == NULL)
	{
		//listpointer1 is empty;
		prev = listpointer2;
	}
	else
		prev->next = listpointer2;
}
//search by position
Node *searchbypositon(Node *&listpointer, int x)
{
	Node *temp;
	temp = listpointer;
	int pos = 0;
	while (true)
	{
		if (temp == NULL) break;
		if (pos == x)
			return temp;
		temp = temp->next;
		pos++;
	}
	cout << x << endl;
	return NULL;
}
// split wih two linked list by searching position
bool split(Node *&listpointer1, Node *&listpointer2,int n)
{
	if (listpointer2 != NULL){
		return false;
	}
	Node *temp = searchbypositon(listpointer1, n);
	listpointer2 = temp->next;
	temp->next = NULL;
	return true;

}
// search by key
Node *searchbykey(Node *&listpointer, int key)
{
	Node *temp;
	temp = listpointer;
	while (true)
	{
		if (temp == NULL) break;
		if (temp->number == key){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}
// insert node after key value;
bool insertafterkey(Node *&listpointer, int a, float b, int key)
{
	Node *temp = NULL;
	temp = searchbykey(listpointer, key);
	if (temp != NULL)
	{
		Node *current = new Node;
		current->number = a;
		current->balance = b;
		current->next = temp->next;
		temp->next = current;
	}
	return true;
}
// remove by key
bool removebykey(Node *&listpointer, int key)
{
	Node *current, *prev;
	current = listpointer;
	prev = NULL;
	int n = 0;
	while (current != NULL)
	{
		n++;
		if (n == key) break;
		prev = current;
		current = current->next;
	}
	if (current == NULL) return false;
	if (prev == NULL) listpointer = listpointer->next;
	else prev->next = prev;
	delete current;
	return true;
}
int main()
{
	Node *A = NULL;
	Node *B = NULL;
	addnode(A, 1, 1.5);
	addnode(A, 2, 2.4);
	addnode(A, 3, 2.6);
	printll(A);
	cout << "the Node A: " << endl;
	split(A, B, 1);
	printll(A);
	cout << "split List " << endl;
	printll(B);
	cout << "concatenance two linked list: " << endl;
	concatenance(A, B);
	printll(A);
	cout << "insert by key" << endl;
	insertafterkey(A, 7, 1.3, 1);
	printll(A);
	cout << "remove nth element" << endl;
	removebykey(A, 1);
	printll(A);
	system("pause");
	return 0;
}