#include <iostream>
#include <fstream>
#include "list.h"
#include <Windows.h>
using namespace std;

void fillList(elem*& list)
{
	ifstream f("data.txt");
	if (f.is_open())
	{
		char* data = new char[31];
		while (!f.eof())
		{
			f.getline(data, 31, '\n');
			if (f.fail())
			{
				break;
			}
			int v, p;
			int cnt = sscanf_s(data, "%d %d", &v, &p);
			switch (cnt)
			{
			case 1:
			{
				add(list, v);
				break;
			}
			case 2:
			{
				insert(list, v, p);
			}
			}
		}
		f.close();
	}
}

void showList(elem* list)
{
	elem* curr = list;
	if (!curr) cout << "EMPTY LIST" << endl;
	while (curr)
	{
		cout << curr->val << (curr->next ? " " : "\n");
		curr = curr->next;
	}
}

void showOdd(elem * list)
{
	int cnt = count(list);
	for (int i = 1; i < cnt; i += 2)
	{
		auto val = get(list, i);
		cout << *val << ((i + 2 < cnt) ? " " : "\n");
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	elem* list1 = nullptr;
	fillList(list1);
	showList(list1);//300 -10 -1 30 1 10 100 200
	int len = count(list1);
	cout << endl <<"len list: "<< len << endl;
	cout << endl <<"position len+2: "<<  *get_loop(list1, len+2) << endl;
	cout << endl << "position -2: " << *get_loop(list1, 10) << endl;
	reverse(list1);
	cout << endl;
	showList(list1);
	
	return 0;
}