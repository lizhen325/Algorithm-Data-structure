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

class stack
{
private:
	float data[10];
	int index;
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
	index = -1;
}

stack :: ~stack()
{

}
void stack :: push(float newthing)
{
	index++;
	data[index] = newthing;
	cout << index << endl;
}

void stack::pop()
{
	if (index > -1)
		index--;
	cout << index << endl;
}

float stack::top()
{
	return data[index];
}

bool stack::isempty() 
{
	if (index < 0)
		return true;
	else
		return false;
}
int main()
{
	stack A;
	A.push(1.1);
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