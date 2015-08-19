#include <iostream>

using namespace std;


class tree
{
private:
	char data;
	tree *leftptr, *rightptr;
public:
	tree(char newthing, tree *l, tree *r)
	{
		data = newthing;
		leftptr = l;
		rightptr = r;
	}
	~tree();
	char rootdata(){ return data; }
	tree* left(){ return leftptr; }
	tree* right(){ return rightptr;}
};

void inorder(tree *T)
{
	if (T == NULL) return;
	inorder(T->left());
	cout << T->rootdata() << ",";
	inorder(T->right());
}
tree *T1, *T2, *T3, *T4, *T5, *T6, *T7, *T8, *mytree;
int height(tree *t)
{
	if (t == NULL) return 0;
	else
	{
		int l_height = height(t->left());
		int r_height = height(t->right());
		if (l_height >= r_height) 
			return (l_height + 1);
		else 
			return (r_height + 1);
	}
}
int main()
{
	T1 = new tree('G', NULL, NULL);
	T2 = new tree('D', NULL, T1);
	T3 = new tree('B', T2, NULL);
	T4 = new tree('I', NULL, NULL);
	T5 = new tree('H', T4, NULL);
	T6 = new tree('F', NULL, T5);
	T7 = new tree('E', NULL, NULL);
	T8 = new tree('C', T7, T6);
	mytree = new tree('A', T3, T8);
	cout << "inorder :" << endl;
	inorder(mytree);
	cout << endl;
	int h = height(mytree);
	cout << "the tree of height is: " << h << endl;
	system("pause");
	return 0;
}