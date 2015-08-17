//159201 assignment 1 skeleton
//You need to add your own AddNode and PrintLL functions, as well as an AddMatrices function
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
//#include <string>

using namespace std;

struct Node 
{
	float data;
	Node *next;
};
class stack
{
private:
	Node *listpointer;
public:
	stack();
	~stack();
	void push(float newthing);
	void pop();
	float top();
	bool isempty();
};

stack::stack()
{
	listpointer = NULL;
}

stack :: ~stack()
{

}
// addnode
void stack :: push(float newthing)
{
	Node *temp;
	temp = new Node;
	temp->data = newthing;
	temp->next = listpointer;
	listpointer = temp;
}
// delete node
void stack::pop()
{
	Node *temp;
	temp = listpointer;
	if (listpointer != NULL)
	{
		listpointer = listpointer->next;
		delete temp;
	}
}

float stack::top()
{
	return listpointer->data;
}

bool stack::isempty() 
{
	if (listpointer == NULL)
		return true;
	else
		return false;
}
int main()
{
	stack A;
	A.push(1.3);
	A.push(2.2);
	A.push(3.3);
	A.pop();
	if (A.isempty())
		cout << "empty" << endl;
	else{

		float x = A.top();
		cout << x << endl;
	}
	system("pause");
	return 0;
}