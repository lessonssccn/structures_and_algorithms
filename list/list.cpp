#include "list.h"

elem* createNewElement(int data)
{
	elem* node = new elem;
	node->next = nullptr;
	node->val = data;
	return node;
}

elem* last(elem* list)
{
	if (list==nullptr)
	{
		return nullptr;
	}
	elem* cur = list;
	while (cur->next != nullptr)
	{
		cur = cur->next;
	}
	return cur;
}

int* get_loop(elem* list, int position)
{
	int len = count(list);

	//if (position > len || position < 0)
	if (position >= len || position < 0)
	{
		position = position % len;
	}

	return get(list, position);
}

void reverse(elem*& list)
{
	if (list==nullptr)
	{
		return;
	}

	elem* newHead = nullptr;
	elem* cur = list;

	while (cur!=nullptr)
	{
		elem* next = cur->next;
		cur->next = newHead;
		newHead = cur;
		cur = next;
	}
	list = newHead;
}

void add(elem*& list, int data)
{
	if (list==nullptr)
	{
		list = createNewElement(data);
	}
	else
	{
		elem* tail = last(list);
		tail->next = createNewElement(data);
	}
}

int count(elem* list)
{
	int cnt = 0;
	elem* curr = list;
	while (curr)
	{
		cnt++;
		curr = curr->next;
	}
	return cnt;
}

void insert(elem*& list, int data, int pos)
{
	elem* newel = new elem;
	newel->val = data;

	if (list && pos > 0)
	{
		elem* curr = list;
		int p = 0;
		while (p < pos - 1 && curr->next)
		{
			curr = curr->next;
			p++;
		}
		newel->next = curr->next;
		curr->next = newel;
	}
	else
	{
		newel->next = list;
		list = newel;
	}
}

int* get(elem* list, int pos)
{
	if (pos < 0 || !list) return nullptr;
	int p = 0;
	elem * curr = list;
	while (curr && p < pos)
	{
		curr = curr->next;
		p++;
	}
	if (curr)
	{
		return &curr->val;
	}
	return nullptr;
}