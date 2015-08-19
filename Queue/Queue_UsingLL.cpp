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
int main(){
	queue Q;
	Q.join(1);
	Q.join(2);
	Q.leave();
	if (Q.isempty())
		cout << "empty";
	else
		cout << Q.front() << endl;
	system("pause");
	return 0;
}