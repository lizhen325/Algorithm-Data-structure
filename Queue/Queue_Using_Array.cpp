#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale>
#include <sstream>

using namespace std;

class queue
{
private:
	int data[10];
	int first, last, count;
public:
	queue();
	~queue();
	void join(int newthing);
	void leave();
	int front();
	bool isempty();
};
//constructor
queue :: queue()
{
	first = 0;
	last = -1;
	count = 0;
}
//desturctor
queue::~queue()
{

}
void queue::join(int newthing)
{
	if (last >= 10) last = 0;
	last = last + 1;
	data[last] = newthing;
	count++;
}
void queue::leave()
{
	first++;
	if (first >= 10) first = 0;
	count++;
}
int queue::front()
{
	return data[first];
}
bool queue::isempty()
{
	if (count == 0) return true;
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