#include "table.h"
#include <iostream>
#include <cmath>
using namespace std;

int HashTable::getClass(std::string& str)
{
	unsigned long long hash = 0;
	for (int i = 0; i < str.length(); i++)
	{
		hash = hash*1000 + (unsigned char)str[i];
	}

	return (a*hash+c) % size;
}

HashTable::HashTable(int size, int a, int c): size(size), a(a), c(c)
{
	table = new List*[size];
	memset(table, 0, size*sizeof(List*));
}

HashTable::~HashTable()
{
	if (table)
	{
		for (int i =0; i< size; i++)
		{
			if (table[i])
			{
				delete table[i];
			}
		}
		delete[] table;
	}
}

bool HashTable::add(std::string & str)
{
	int pos = getClass(str);
	if (table[pos]==0)
	{
		table[pos] = new List;
		table[pos]->append(str);
		countClass++;
		countElements++;
	}
	else
	{
		if (!table[pos]->contain(str))
		{
			table[pos]->append(str);
			countElements++;
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool HashTable::contain(std::string& str)
{
	int pos = getClass(str);

	if (table[pos])
	{
		return table[pos]->contain(str);
	}

	return false;
}

void HashTable::showTable()
{
	for (int i=0; i< size; i ++)
	{
		cout << "[class: " << i << "] ";
		if (table[i]!=0)
		{
			table[i]->show();
		}
		else
		{
			cout << "empty";
		}
		cout << endl;
	}
}

int HashTable::getClassLongChain()
{
	if (countClass == 0)
		return -1;

	int maxLen = 0;
	int _class = 0;
	for (int i = 0; i < size; i++)
	{
		if (table[i] && table[i]->getSize() > maxLen)
		{
			maxLen = table[i]->getSize();
			_class = i;
		}
	}
	return _class;
}

List* HashTable::getLongChain()
{
	if (countClass > 0)
		return table[getClassLongChain()];
	else
		return 0;
}

int HashTable::countColision()
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (table[i] != 0)
		{
			count += table[i]->getSize();
		}
	}
	return count;
}

double HashTable::getPercentFull()
{
	return (double)countClass/size;
}

