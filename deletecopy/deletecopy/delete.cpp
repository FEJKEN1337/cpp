#include <iostream>
using namespace std;

struct node
{
	int val;
	node * next;
};

void dodajliste(node*&H, int x) {
	node *p;
	p = new node;
	p->val = x;
	p->next = H;
	H = p;
}

void usuwanieco2(node*&H)
{
	if (H != NULL)
	{
		node *p = H;
		node *pom;
		while (p != NULL&&p->next != NULL)
		{
			pom = p->next;
			p->next = pom->next;
			delete pom;
			p = p->next;
		}
		{

		}
	}

}

void wyswietlliste(node*&H)
{
	cout << "H -> ";
	if (H != NULL) {
		node *p = H;
		while (p != NULL) {
			cout << p->val << "->";
			p = p->next;
		}
	}
	cout << "NULL" << endl;
}

int main() {
	node *H = NULL;
	dodajliste(H, 5);
	dodajliste(H, 18);
	dodajliste(H, 98);
	dodajliste(H, -78);
	dodajliste(H, 92);
	dodajliste(H, 15);
	dodajliste(H, -24);
	wyswietlliste(H);
	usuwanieco2(H);
	wyswietlliste(H);
	system("pause");

}