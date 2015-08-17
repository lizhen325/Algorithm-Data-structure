#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale>
#include <sstream>

using namespace std;

/* implement your stack here */
struct Node 
{
	int data;
	Node *next;
};

class stack
{
private:
	Node *listpointer;
public:
	stack();
	~stack();
	void push(int newthing);
	void pop();
	int top();
	bool isempty();
};
//constructor
stack::stack()
{
	listpointer = NULL;
}
//desturctor
stack::~stack()
{

}
void stack::push(int newthing)
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
	{
		listpointer = listpointer->next;
		delete temp;
	}
}
int stack::top()
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
int main(int argc, char** argv){//get arguments from command line, i.e., yourexec filename
	int result, op1, op2, number, i;
	char oper;
	stack s;
	string expression;
	ifstream input_file;
	argv[1] = "C:/Users/zhenli/Desktop/159201/Assignments/2/RPN5.txt";
	/*if (argc != 2) {
		cout << "needs a filename as argument  " << endl;
		exit(0);
	}*/
	input_file.open(argv[1]);
	if (!input_file.good()){
		cout << "cannot read file " << argv[1] << endl;
		exit(0);
	}
	while (!input_file.eof()){
		getline(input_file, expression);
		if (isdigit(expression[0])){
			stringstream line(expression);
			line >> number;
			cout << "reading number " << number << endl;
			//modify here to deal with the Stack
			//PUSH number
			s.push(number);
		}
		else {
			if (expression[0] == '+' || expression[0] == '-' || expression[0] == '/' || expression[0] == '*') {
				stringstream line(expression);
				line >> oper;
				cout << "reading operator " << oper << endl;
				if (!s.isempty())
				{
					op2 = s.top();
					s.pop();
				}
				else
					cout << "too many operators" << endl;
				if (!s.isempty()){
					op1 = s.top();
					s.pop();
				}
				else
					cout << "too many operators" << endl;

				//compute result
				//PUSH result
				int result;
				if (oper == '+') result = op2 + op1;
				if (oper == '*') result = op2 * op1;
				if (oper == '/') result = op2 / op1;
				if (oper == '-') result = op2 - op1;
				s.push(result);
			}
		}
	}
	//finalanswer = TOP
	result = s.top();
	s.pop();
	if (!s.isempty())
	{
		cout << "too many operators";
	}
	else
		cout << result << endl;
	//the last element of the stack should be the final answer...
	system("pause");
	return 0;
}
