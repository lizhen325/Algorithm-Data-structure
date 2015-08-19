#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale>
#include <sstream>

using namespace std;

struct Node 
{
	int data;
	Node *next;
};

class queue
{
private:
	Node *first, *rear;
public:
	queue();
	~queue();
	void join(int newthing);
	void leave();
	int front();
	bool isempty();
	void print();
};
queue::queue()
{
	first = NULL;
	rear = NULL;
}
queue::~queue()
{

}
void queue::join(int newthing)
{
	Node *temp;
	temp = new Node;
	temp->data = newthing;
	temp->next = NULL;
	if (rear != NULL)rear->next = temp;
	rear = temp;
	if (first == NULL) first = temp;
}
void queue::leave()
{
	Node *temp;
	if (first == NULL)return;
	temp = first;
	first = first->next;
	if (first == NULL)rear = NULL;
	delete temp;
}
int queue::front()
{
	return first->data;
}
bool queue::isempty()
{
	if (first == NULL) return true;
	return false;
}
void queue::print()
{
	if (first == NULL) return;
	Node *temp = first;
	while (temp != NULL)
	{
		cout << temp->data;
		temp = temp->next;
	}
	cout << endl;
}
int main(){
	queue A,B;
	A.join(1);
	A.join(2);
	A.join(3);
	A.join(4);
	A.join(5);
	cout << "A: ";
	A.print();
	cout << "transferring A to B" << endl;
	while (A.isempty() == false)
	{
		int temp = A.front();
		A.leave();
		B.join(temp);
		cout << "A:" << endl;
		A.print();
		cout << "B :" << endl;
		B.print();
	}
	system("pause");
	return 0;
}