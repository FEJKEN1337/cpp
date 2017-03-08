#include <iostream>
using namespace std;

struct BST
{
	int val;
	BST *L;
	BST *R;
};

void INSERT(BST *&, int);
void INORDER(BST *);

void RotRight(BST *root)
{
	BST *p = root->L;
	root->L = p->R;
	p->R = root;
	root = p;
}

void RotLeft(BST *root)
{
	BST *p = root->R;
	root->R = p->L;
	p->L = root;
	root = p;
}

int main()
{
	BST *root = NULL;

	INSERT(root, 5);
	INSERT(root, 15);
	INSERT(root, 2);
	INSERT(root, 1);
	INSERT(root, 7);

		INORDER(root);

	RotLeft(root);

	system("PAUSE");
	return 0;
}

void INSERT(BST *&root, int x)
{
	if (root == NULL)
	{
		root = new BST;
		root->val = x;
		root->L = NULL;
		root->R = NULL;
	}
	else {
		if (x > root->val)
			INSERT(root->R, x);
		else
			INSERT(root->L, x);
	}
}

void INORDER(BST * root)
{
	if (root != NULL)
	{
		INORDER(root->L);
		cout << root->val << " -> ";
		INORDER(root->R);
	}
}