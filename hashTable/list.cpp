#include "list.h"
#include <iostream>
using namespace std;

ListNode::ListNode(std::string & str): next(0)
{
	this->word = str;
}

void ListNode::setNext(ListNode* next)
{
	this->next = next;
}

ListNode* ListNode::getNext()
{
	return next;
}

ListNode::~ListNode()
{
}

bool ListNode::isEq(std::string& str)
{
	return word==str;
}

std::string& ListNode::getWord()
{
	return word;
}


List::List():head(0),tail(0)
{

}

List::~List()
{
	auto cur = head;
	while (cur!=0)
	{
		auto next = cur->getNext();
		delete cur;
		cur = next;
	}
	head = 0;
	tail = 0;
}

void List::append(std::string & str)
{
	if (head && tail)
	{
		tail->setNext(new ListNode(str));
		tail = tail->getNext();
	}
	else
	{
		head = tail = new ListNode(str);
	}
	size++;
}

bool List::contain(std::string& str)
{
	for (auto cur = head; cur!=0; cur = cur->getNext())
	{
		if (cur->isEq(str))
		{
			return true;
		}
	}
	return false;
}

void List::show()
{
	for (auto cur = head; cur != 0; cur = cur->getNext())
	{
		cout << cur->getWord() << " | ";
	}
}

int List::getSize()
{
	return size;
}
