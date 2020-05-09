#pragma once

struct  elem
{
	int val;
	elem * next;
};

elem* createNewElement(int data);
elem* last(elem * list);
int* get_loop(elem * list, int position);
void reverse(elem*& list);


void add(elem*& list, int data);
int count(elem* list);
void insert(elem*& list, int data, int position);
int* get(elem* list, int position);
