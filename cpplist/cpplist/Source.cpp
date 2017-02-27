#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;

};

void dodajliste(node *&H, int x)
{
	node *p;
	p = new node;
	p->data = x;
	p->next = H;
	H = p;
};

void pokazliste(node *&H)
{
	cout << "H->";
	if (H != NULL)
	{
		node *p = H;
		while (p != NULL)
		{
			cout << p->data << "->";
			p = p->next;
		}
	}

};

int main()
{
	node *H = NULL;
	dodajliste(H, 23);
	dodajliste(H, 10);
	dodajliste(H, 29);
	dodajliste(H, 11);
	dodajliste(H, 45);
	dodajliste(H, 16);
	pokazliste(H);

	system("pause");
};