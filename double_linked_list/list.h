#pragma once
struct elem
{
	double x;
	elem* next = nullptr;
	elem* prev = nullptr;
};

struct list2
{
	elem* first = nullptr;
	elem* last = nullptr;
	int count = 0;
};

void add(list2& list, double data);

void pushend(list2& list, double data);
void pushfront(list2& list, double data);



bool remove(list2& list, int position);

double* get(list2 list, int position);

void clear(list2& list);

