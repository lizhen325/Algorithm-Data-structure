//using a vector with adjacency list
// G = {V,E}
// V = {A,B,C,D}
// E = {(A,B,1),(A,C,2)...}
#include <iostream>
#include <vector>

using namespace std;

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
	Graph(){ }
	~Graph(){ }
	void add_new_GraphNode(char newgraphnode);
	void add_new_edge_between_GraphNode(char A, char B, int distance);
	void print_all_new_GraphNode_cost();
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

int main()
{
	//manually building the graph
	Graph mygraph;
	mygraph.add_new_GraphNode('A');
	mygraph.add_new_GraphNode('B');
	mygraph.add_new_GraphNode('C');
	mygraph.add_new_GraphNode('D');
	mygraph.add_new_edge_between_GraphNode('A', 'B', 1);
	mygraph.add_new_edge_between_GraphNode('A', 'D', 4);
	mygraph.add_new_edge_between_GraphNode('B', 'A', 1);
	mygraph.add_new_edge_between_GraphNode('C', 'A', 3);
	mygraph.add_new_edge_between_GraphNode('D', 'B', 5);
	mygraph.add_new_edge_between_GraphNode('D', 'C', 11);
	mygraph.add_new_edge_between_GraphNode('D', 'A', 10);


	cout << "print graph in the form of adjency list : " << endl;
	mygraph.print_all_new_GraphNode_cost();
	system("pause");
	return 0;

}