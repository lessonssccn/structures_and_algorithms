#pragma once
#include <string>
class ListNode
{
	std::string word;
	ListNode* next;
public:
	ListNode(std::string & str);
	void setNext(ListNode* next);
	ListNode* getNext();
	~ListNode();
	bool isEq(std::string& str);
	std::string& getWord();
};

class List
{
	ListNode* head;
	ListNode* tail;
	int size;
public:
	List();
	~List();
	void append(std::string & fileInfo);
	bool contain(std::string& fileInfo);
	void show();
	int getSize();
};