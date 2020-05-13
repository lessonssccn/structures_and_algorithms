#include "list.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;

list2* loadFromFile(string nameFile, bool sorted = true)
{
	list2* res = new list2;

	ifstream fin(nameFile);
	if (fin.is_open() && fin.good())
	{
		double data;
		while (!fin.eof())
		{
			fin >> data;
			if (!sorted)
			{
				pushend(*res, data);
			}
			else
			{
				add(*res, data);
			}
		}
	}
	fin.close();
	return res;
}

void showList(list2 * list)
{
	if (list==nullptr || list->first==nullptr || list->last == nullptr)
	{
		return;
	}
	for (elem* cur = list->first; cur!=nullptr; cur = cur->next)
	{
		cout << cur->x << " ";
	}
}

void showListReverce(list2* list)
{
	if (list == nullptr || list->first == nullptr || list->last == nullptr)
	{
		return;
	}
	for (elem* cur = list->last; cur != nullptr; cur = cur->prev)
	{
		cout << cur->x << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	auto list = loadFromFile("input.txt");
	cout << endl;
	showList(list);
	cout << endl;
	showListReverce(list);
	cout << endl;

	remove(*list, 0);
	cout << endl;
	showList(list);
	cout <<endl<< *get(*list, 6) << endl;
	remove(*list, 6);
	cout << endl;
	showList(list);
	cout << endl;


	clear(*list);

	showList(list);
	cout << endl;
	delete list;
	system("pause");
	return 0;
}