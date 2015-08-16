// a simple linked list
// add values, search value, and delete the node.

#include <iostream>

using namespace std;

struct Node {
	int number;
	float balance;
	Node *next;
};
void addnode(Node *&listpointer, int a, float b)
{
	Node *temp;
	temp = new Node;
	temp->number = a;
	temp->balance = b;
	temp->next = listpointer;
	listpointer = temp;
}
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
void search(Node *listpointer, int value)
{
	Node *temp;
	temp = listpointer;
	while (temp != NULL)
	{
		if (temp->number == value){
			cout << "the findng value is: " << temp->balance << endl;
			return;
		}
		temp = temp->next;
	}
	cout << "cannot find the value" << endl;
}
void remove(Node *&listpointer, int x)
{
	Node *current, *prev;
	current = listpointer;
	prev = NULL;
	while (current != NULL)
	{
		if (current->number == x) { break; }
		prev = current;
		current = current->next;
	}
	if (current == NULL) return;
	if (prev == NULL){
		listpointer = listpointer->next;
	}
	else{
		prev->next = current->next;
	}
	delete current;
}
int main()
{
	Node *A = NULL;
	addnode(A, 1, 1.5);
	addnode(A, 2, 2.5);
	search(A, 1);
	remove(A, 1);
	search(A, 1);
	printll(A);

	system("pause");
	return 0;
}