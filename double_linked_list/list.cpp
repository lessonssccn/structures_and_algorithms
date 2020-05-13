#include "list.h"

void add(list2& list, double data)
{
	elem* newel = new elem;
	newel->x = data;
	list.count++;
	if (!list.first)
	{
		list.first = list.last = newel;
	}
	else
	{
		if (newel->x <= list.first->x)
		{
			newel->next = list.first;
			list.first->prev = newel;
			list.first = newel;
		}
		else if (newel->x >= list.last->x)
		{
			newel->prev = list.last;
			list.last->next = newel;
			list.last = newel;
		}
		else
		{
			elem* curr = list.first->next;
			while (curr->x < newel->x)
			{
				curr = curr->next;
			}
			newel->next = curr;
			newel->prev = curr->prev;
			curr->prev->next = newel;
			curr->prev = newel;
		}
	}
}

void pushend(list2& list, double data)
{
	elem* newel = new elem;
	newel->x = data;
	newel->prev = nullptr;
	newel->next = nullptr;
	list.count++;

	if (!list.first)
	{
		list.first = list.last = newel;
	}
	else
	{
		list.last->next = newel;
		newel->prev = list.last;
		list.last = newel;
	}
}

void pushfront(list2& list, double data)
{
	elem* newel = new elem;
	newel->x = data;
	newel->prev = nullptr;
	newel->next = nullptr;
	list.count++;

	if (!list.first)
	{
		list.first = list.last = newel;
	}
	else
	{
		list.first->prev = newel;
		newel->next = list.first;
		list.first = newel;
	}
}

elem* findElem(list2 list, int pos)
{
	int p = 1;
	bool fwd = pos < list.count / 2;
	elem* curr;
	if (fwd)
		curr = list.first->next;
	else
	{
		curr = list.last->prev;
		pos = list.count - pos - 1;
	}
	while (p < pos)
	{
		p++;
		curr = (fwd) ? curr->next : curr->prev;
	}
	return curr;
}

bool remove(list2& list, int pos)
{
	if (pos < 0 || pos >= list.count)
		return false;
	
	if (pos == 0)
	{
		elem* rem = list.first;
		list.first = list.first->next;
		if (list.first) list.first->prev = nullptr;
		else list.last = nullptr;
		delete rem;
		return true;
	}
	if (pos == list.count - 1)
	{
		elem* rem = list.last;
		list.last = list.last->prev;
		list.last->next = nullptr;
		delete rem;
		return true;
	}
	elem* curr = findElem(list, pos);
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	delete curr;
	list.count--;
	return true;
}

double* get(list2 list, int pos)
{
	if (pos < 0 || pos >= list.count)
		return nullptr;
	if (pos == 0) return &list.first->x;
	if (pos == list.count - 1) return &list.last->x;
	elem * curr = findElem(list, pos);
	return &curr->x;
}

void clear(list2 & list)
{
	elem* rem;
	while (list.first)
	{
		rem = list.first;
		list.first = list.first->next;
		delete rem;
	}
	list.last = nullptr;
	list.count = 0;
}