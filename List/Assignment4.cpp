////////////////   159201   ///////////////////////////////////
//SAMPLE CODE FOR ASSIGNMENT 4 - Big Numbers
//2012 
//It is not the perfect. it does not work carry and two numbers with different digits


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

/////// PART A

template <class T>
class list
{
private:
	struct Node
	{
		T data;
		Node *next;
	};
	Node *front, *current;
public:
	list();
	~list();
	void add_to_front(T newthing);
	bool first_item(T &item);
	bool next_item(T &item);
	void reverse();
};
// constructor
template <class T>
list<T> ::list()
{
	front = NULL;
	current = NULL;
}
// destructor
template <class T>
list<T>::~list()
{

}
template <class T>
void list<T>::add_to_front(T newthing)
{
	Node *temp;
	temp = new Node;
	temp->data = newthing;
	temp->next = front;
	front = temp;
}
template <class T>
bool list<T>::first_item(T &item)
{
	if (front == NULL) return false;
	item = front->data;
	current = front;
	return true;
}
template <class T>
bool list<T>::next_item(T &item)
{
	current = current->next;
	if (current == NULL) return false;
	item = current->data;
	return true;
}
template <class T>
void list<T>::reverse()
{
	Node *temp1, *temp2;
	current = front->next;
	temp2 = front;
	while (current != NULL)
	{
		temp1 = current->next;
		current->next = front;
		front = current;
		current = temp1;
	}
	temp2->next = NULL;
}
/////// PART B
class BigNumber {
private:
	//complete here...
	//include here a List of integers, or shorts etc
	list <int> l;
	int x;
	bool ok;
	int partialres;
public:
	//complete here...
	//what methods do you need?  
	BigNumber();
	~BigNumber();
	void ReadFromString(string decstring);
	void PrintBigNumber();
	void AddBigNumbers(BigNumber B1, BigNumber B2);
};

BigNumber::BigNumber(){
	// anything here?

}

BigNumber::~BigNumber(){
	//you can keep that empty
}

void BigNumber::ReadFromString(string decstring) {
	//cout<< "testing string passing: "<< decstring << endl;
	//read a string, adding a new node per digit of the decimal string
	// To translate 'digits' to integers: myinteger=decstring[index]-48

	for (int i = 0; i < decstring.size(); i++) {
		if (decstring[i] != '\n' && decstring[i] != '\r'){
			int temp = decstring[i] - 48;
			cout << "Digit " << i << " is " << temp << endl;  //Comment this out for your final version
			//You need to use the AddtoFront()
				l.add_to_front(temp);
		}
	}
}

void BigNumber::PrintBigNumber() {
	//complete here, print the list (i.e., use FirstItem() and NextItem() )
	//remember that the print out may be inverted, depending on the order you enter the 'digits'
	l.reverse();
	x = 0;
	ok = l.first_item(x);
	while (ok)
	{
		cout << x;
		ok = l.next_item(x);
	}
}

void BigNumber::AddBigNumbers(BigNumber B1, BigNumber B2){
	//complete here.
	//use FirstItem(), NextItem() and AddNode()
	//to add two big numbers, what do you have to do? Be careful about the carry
	//Remember to add the last carry, the resulting number can have one more digit than B1 or B2
	int carry = 0;
	int x = 0;
	int digit1=0 ,digit2=0;
	bool ok1 = B1.l.first_item(digit1); 
	bool ok2 = B2.l.first_item(digit2); 
	while (ok1|| ok2 )
	{
		partialres = digit1 + digit2 + carry;
		l.add_to_front(partialres % 10);
		if (partialres <= 9) { carry = 0;}
		
		else {
			carry = int(partialres / 10);
		}

		if(ok1)	ok1 = B1.l.next_item(digit1);
		if (ok2) ok2 = B2.l.next_item(digit2);
		if(ok2 == false)
		 B2.l.add_to_front(digit1);
			
	}


	if (carry != 0) l.add_to_front(carry);//
}

/////// PART C

BigNumber B1, B2, RES;

int main(int argc, char ** argv) {
	string numberstring;
	int stringseq = 0;
	ifstream input_file;
	argv[1] = "C:/Users/zhenli/Desktop/159201/Assignments/4/samplenumbers1.txt";
	//if (argc == 2) 
	input_file.open(argv[1]);
	//else { cout << "cannot read the file " << argv[1] << endl; exit(0); }
	while (!input_file.eof()){
		getline(input_file, numberstring);
		if (!input_file.eof()){
			cout << "reading a big number from file:" << numberstring << endl;//Comment this out for your final version
			if (stringseq == 0){
				B1.ReadFromString(numberstring);
				stringseq = 1;
			}
			else B2.ReadFromString(numberstring);
		}
	}
	//print
	B1.PrintBigNumber();//PROBLEM: Is the printing inverted? How can you solve this problem? Before or after using AddBigNumbers()?
	cout << endl;
	cout << "+" << endl;
	B2.PrintBigNumber();
	cout << endl;
	cout << "=" << endl;
	////compute the addition
	RES.AddBigNumbers(B1, B2);
	////print the result
	RES.PrintBigNumber();
	cout << endl;
	system("pause");
	return 0;
}
