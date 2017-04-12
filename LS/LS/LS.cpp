#include <iostream>
#include <fstream>

using namespace std;

struct node
{
	int from;
	int to;
	int val;
	node *next;
};

int **macierz()
{
	fstream czytaj;
	czytaj.open("graf.txt");
	int n;
	czytaj >> n;
	int **MS = new int *[n];
	for (int i = 0; i < n; i++)
	{
		MS[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			czytaj >> MS[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << MS[i][j] << ' ';
		cout << endl;
	}
	return MS;
};

void addls(node *&H, int to, int val)
{
	node *p = new node;
	p->to = to;
	p->val = val;
	p->next = H;
	H = p;
};

node **CreateLS(int **MS) // tworzenie listy sasiedztwa
{
	int x = 5;
	node **LS = new node *[x];
	for (int i = 0; i < x; i++)
		LS[i] = NULL;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < x; j++)
			if (MS[i][j] != 0)
				addls(LS[i], j, MS[i][j]);
	return LS;
};

void pokazLS(node **LN)
{
	node *p = NULL;
	int a = 5;
	for (int i = 0; i < a; i++)
	{
		p = LN[i];
		cout << "[" << i << "] ->";
		while (p != NULL)
		{
			cout << "To:" << p->to << "Dystans:" << p->val << " , ";
			p = p->next;
		}
		cout << endl;
	}
}

int main()
{
	int **MS = macierz();
	node **LS = CreateLS(MS);
	pokazLS(LS);
	system("pause");

};