#include <iostream>
using namespace std;

struct LIST
{
	int val;
	LIST *next;

};


void ADD_LIST(LIST*& H, int x)
{
	//Tworzymy nowy element do dodania do listy
	LIST *nowy = new LIST;
	nowy->val = x;
	nowy->next = NULL;

	//Sprawdzamy czy lista pusta
	if (H == NULL)
	{
		H = nowy;
	}
	else
	{
		//Przechodzimy na koniec listy
		LIST *tmp = H;
		while (tmp->next != NULL)
			tmp = tmp->next;

		//Ostatni element na liœcie ma wskazywaæ na nowy
		tmp->next = nowy;
	}
}

void SHOW_LIST(LIST *H)
{
	cout << "H -> ";
	while (H != NULL)
	{
		cout << H->val << " -> ";
		H = H->next;
	}
	cout << "NULL" << endl;

}


void COPY(LIST *&H)
{
	LIST *tmp = H;
	LIST *copy = NULL;
	while (tmp->next != NULL)
	{
		if (tmp->val % 2 == 0)
		{
			if (copy == NULL)
			{
				copy = new LIST;
				copy->val = tmp->val;
				copy->next = NULL;
			}
			else
			{
				LIST *p = copy;
				while (p->next != NULL)
					p = p->next;

				LIST *nowy = new LIST;
				nowy->val = tmp->val;
				nowy->next = NULL;
				p->next = nowy;
			}
		}
		tmp = tmp->next;

		if (tmp->next == NULL && tmp->val % 2 == 0)
		{
			LIST *p = copy;
			while (p->next != NULL)
				p = p->next;

			LIST *nowy = new LIST;
			nowy->val = tmp->val;
			nowy->next = NULL;
			p->next = nowy;
		}
	}

	tmp->next = copy;
}

void ChangeFirstLast(LIST *&H)
{
	LIST *tmp = H;
	if (H->next->next == NULL)
	{
		H = tmp->next;
		H->next = tmp;
		tmp->next = NULL;
	}
	else
	{
		LIST *p = H;
		while (tmp->next->next != NULL)
			tmp = tmp->next;

		H = tmp->next;
		tmp->next = p;
		H->next = p->next;
		p->next = NULL;
	}
}


int main()
{
	LIST *H = NULL;
	ADD_LIST(H, 10);
	ADD_LIST(H, 12);
	ADD_LIST(H, 4);
	ADD_LIST(H, 2);
	ADD_LIST(H, 3);
	ADD_LIST(H, 7);
	ADD_LIST(H, 17);
	ADD_LIST(H, 1);
	ADD_LIST(H, 12);
	ADD_LIST(H, 8);
	SHOW_LIST(H);
	ChangeFirstLast(H);
	SHOW_LIST(H);
	COPY(H);
	SHOW_LIST(H);
	system("PAUSE");
	return 0;

}