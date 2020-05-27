#pragma once
#include "list.h"
class HashTable
{
	int size;
	int a;
	int c;
	int countElements;
	int countClass;
	List ** table;
	int getClass(std::string & str);
public:
	HashTable(int size = 30, int a = 1, int c = 0);
	~HashTable();
	bool add(std::string& str);
	bool contain(std::string& str);
	void showTable();
	int getClassLongChain();
	List * getLongChain();
	int countColision();
	double getPercentFull();
};