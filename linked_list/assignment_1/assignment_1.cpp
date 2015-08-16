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

struct Node {  //declaration
	int row;
	int column;
	int value;
	Node *next;
};
Node *A = NULL;  //declaration
Node *B = NULL;
Node *C = NULL;

void addnode(Node *&listpointer,int i, int j, int value)
{
	Node *temp;
	temp = new Node;
	temp->row = i;
	temp->column = j;
	temp->value = value;
	temp->next = listpointer;
	listpointer = temp;
}
int search(Node *listpointer, int row, int col)
{
	Node *temp;
	temp = listpointer;
	while (temp != NULL)
	{
		if ((temp->row == row) && (temp->column == col))
		{
			return temp->value;
		}
		temp = temp->next;
		
	}
	return 0;
}
void addmatrix(int row, int col)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int result = search(A, i, j) + search(B, i, j);
			if (result != 0) addnode(C, i, j, result);
		}
	}
}
void print(Node *&listpointer, int size)
{
	cout << "the result of Matrix is :" << endl;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			int result = search(listpointer, i, j);
			cout << result <<" ";
		}
		cout << endl;
	}
	cout << endl;
}
void read_matrix(Node* &a, char *file_name){
	//reads a matrix from a file
	int col = 0, row = 0, value = 0;
	ifstream input;
	input.open(file_name);
	if (!input.good()){
		cout << "Cannot open file " << file_name << endl;
		exit(0);
	}
	int c;
	string line;
	//reads the first line to get dimensions
	if (input.good()){
		getline(input, line);
		stringstream sline(line);
		sline >> row >> col;
		cout << "Matrix dimensions " << row << " " << col << endl;
	}
	//read matrix 
	for (int i = 0; i < row; ++i){
		if (input.good()) {
			getline(input, line);
			stringstream sline(line);
			for (int j = 0; j < col; ++j){
				sline >> value;
				if (value == 0) continue;
				//
				//Include your own add_node(a, i, j, value); function here
				addnode(a, i, j, value);
				
				//
				//The next line is for debbuging, it can be commented later
				cout << "Element at (" << i << " " << j << ") is different than zero and it is: " << value << " " << endl;
				//addmatrix(row, col);
			}
			//the next line is for debbuging purposes, it can be commented out later
			cout << endl;
		}
		
	}
	addmatrix(row, col);
	int size = (row + col)/2;
	print(C, size);
	input.close();
}

int main(int argc, char** argv)
{
	argv[1] = "C:/Users/zhenli/Desktop/159201/Assignments/1/matrix1.txt";
	argv[2] = "C:/Users/zhenli/Desktop/159201/Assignments/1/matrix2.txt";
	read_matrix(A, argv[1]);
	read_matrix(B, argv[2]);
	system("pause");
	return 0;
}
