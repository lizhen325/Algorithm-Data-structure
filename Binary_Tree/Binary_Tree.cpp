#include <iostream>

using namespace std;


class tree
{
private:
	char data;
	tree *rightptr, *leftptr;
public:
	tree(char newthing, tree *l, tree *r);
	~tree();
	char rootdata(){ return data;}
	tree *left(){ return leftptr; }
	tree *right(){ return rightptr;}
};

tree::tree(char newthing, tree *l, tree *r)
{
	data = newthing;
	leftptr = l;
	rightptr = r;
}

void inorder(tree *T)
{
	if (T == NULL) return;
	inorder(T->left());
	cout << T->rootdata() << ",";
	inorder(T->right());
}

void postorder(tree *T)
{
	if (T == NULL) return;
	postorder(T->left());
	postorder(T->right());
	cout << T->rootdata() << ",";
}
void preorder(tree *T)
{
	if (T == NULL) return;
	cout << T->rootdata() << ",";
	preorder(T->left());
	preorder(T->right());
}
tree *T1, *T2, *T3, *T4, *T5, *T6, *mytree;

int main()
{
	T1 = new tree ('F', NULL, NULL);
	T2 = new tree ('G', NULL, NULL);
	T3 = new tree ('C', T1, T2);
	T4 = new tree ('D', NULL, NULL);
	T5 = new tree ('E', NULL, NULL);
	T6 = new tree ('B', T4, T5);
	mytree = new tree ('A', T6, T3);
	cout << "InOrder : ";
	inorder(mytree);
	cout << endl;
	cout << "PostOrder : ";
	postorder(mytree);
	cout << endl;
	cout << "PreOrder : ";
	preorder(mytree);
	cout << endl;
	system("pause");
	return 0;
}