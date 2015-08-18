#include <iostream>
#include <vector>

using namespace std;

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
	void makecopy(list &l);
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
template <class T>
void list<T>::makecopy(list &l)
{
	Node *temp;
	temp = front;
	while (temp != NULL)
	{
		l.add_to_front(temp->data);
		temp = temp->next;
	}
}
int main()
{
	list<int> L, R;
	L.add_to_front(1);
	L.add_to_front(2);
	L.add_to_front(3);
	L.reverse();
	L.makecopy(R);
	int x;
	bool ok = R.first_item(x);
	
	while (ok)
	{
		cout << x << endl;
		ok = R.next_item(x);
	}
	system("pause");
	return 0;
}