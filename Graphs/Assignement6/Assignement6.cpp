﻿// implement dijkstra algorithm with adjency list
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


/* Implement the Graph class  */
struct Node {
	char key;
	int distance;
	Node *next;
};

struct GraphNode{
	char key;
	Node *listpointer;
};
// a set of edges
void AddNode_to_Front(Node *&listpointer, char newkey, char newdistance)
{
	Node *temp;
	temp = new Node;
	temp->key = newkey;
	temp->distance = newdistance;
	temp->next = listpointer;
	listpointer = temp;
}

void printLLnodes(Node *&listpointer)
{
	Node *temp;
	temp = listpointer;
	while (temp != NULL)
	{
		cout << "to node " << temp->key << " distance is " << temp->distance << endl;
		temp = temp->next;
	}
}
class Graph
{
private:
	vector <GraphNode> adjlist;
public:
	Graph(){}
	~Graph(){ }
	void add_new_GraphNode(char newgraphnode);
	void add_new_edge_between_GraphNode(char A, char B, int distance);
	void print_all_new_GraphNode_cost();
	void dijksta();
};

//a set of nodes
void Graph::add_new_GraphNode(char newgraphnode)
{
	GraphNode temp;
	temp.key = newgraphnode;
	temp.listpointer = NULL;
	adjlist.push_back(temp);
}
void Graph::add_new_edge_between_GraphNode(char A, char B, int distance)
{
	int a;
	for (a = 0; a < adjlist.size(); ++a)
	{
		if (A == adjlist[a].key)
			break;
	}
	AddNode_to_Front(adjlist[a].listpointer, B, distance);
}

void Graph::print_all_new_GraphNode_cost()
{
	for (int a = 0; a < adjlist.size(); ++a)
	{
		cout << "from node " << adjlist[a].key << endl;
		printLLnodes(adjlist[a].listpointer);
	}

}

void Graph::dijksta()
{
	// V: adjlist[0].key  A,B,C  current node;
	// soucenode is adjlist[0].listpointer->key
	//adjlist[0].listpointer->key and adjlist[0].listpointer->distance c,5
	char current;
	char sourcenode;
	unsigned int *d = new unsigned int;
	char *s = new char;
	current = adjlist[0].key;
	sourcenode = adjlist[0].listpointer->key;
	//cout << adjlist[].listpointer->key << endl;
	d[sourcenode] = 0;
	s[sourcenode] = 'p';
	//current = sourcenode;
	for (int i = 0; i < adjlist.size(); ++i)
	{

		/*cout << adjlist[i].key << endl;
		cout << adjlist[i].listpointer->key << endl;
		cout << adjlist[i].listpointer->distance << endl;*/
		if (adjlist[i].key != adjlist[i].listpointer->key)
		{ 
			d[adjlist[i].key] = 0;
			s[adjlist[i].key] = 't';
		}
		while (s[adjlist[i].key] == 't')
		{
			for (int i = 1; i < adjlist.size(); ++i)
				d[adjlist[i].key] = min(d[adjlist[i].key], d[adjlist[i].key] + adjlist[i].listpointer->distance);
		}
		cout << d[adjlist[i].key] << endl;
		s[adjlist[i].key] = 'p';
	}
}
/* declare a new Graph */
Graph G;

int main(int argc, char** argv){//get filename from arguments
	//read an input text file
	GraphNode *H = new GraphNode;
	string expression;
	ifstream input_file;
	argv[1] = "C:/Users/zhenli/Desktop/159201/Assignments/6/graph1.txt";
	input_file.open(argv[1]);
	if (input_file.is_open() == false) { cout << "Could not read file: " << endl << argv[1] << endl; exit(0); }
	string token;
	while (!input_file.eof()){
		getline(input_file, expression);
		stringstream line(expression);
		if (input_file.eof()) break;
		if (expression[0] == '#') continue;//jump line, this is a line of comments
		char node_name;
		if (expression[0] == 'N' && expression[1] == 'o') {//read a Node name, single character
			getline(line, token, ' ');
			getline(line, token, ' ');
			node_name = (token.c_str())[0];
			cout << "Node " << node_name << endl;//Comment this out on the final version
			/* Insert nodes into the graph */
			G.add_new_GraphNode(node_name);
			/* */
		}
		else{
			char nodefrom;
			getline(line, token, ' ');
			nodefrom = (token.c_str())[0];
			cout << "From " << nodefrom;//Comment this out on the final version
			char nodeto;
			getline(line, token, ' ');
			nodeto = (token.c_str())[0];
			cout << " to " << nodeto; //Comment this out on the final version
			int cost;
			getline(line, token, ' ');
			//cost = stoi(token);//only works with option -std=c++11
			cost = atoi(token.c_str());//use this one if your compiler is not C++11
			cout << " costs " << cost << endl;//Comment this out on the final version
			/* Insert these edges into the graph */
			G.add_new_edge_between_GraphNode(nodefrom, nodeto, cost);
			/*  */
		}
	}
	
	/* After loading the graph from the text file in the while loop above, run your implementation of Dijkstra here*/

	// Dijkstra can be implemented either as a function or as a method of the class Graph

	/* call Dijkstra  */
	G.dijksta();
	/* Print answer in the required format */
	G.print_all_new_GraphNode_cost();
	system("pause");
	return 0;
}
