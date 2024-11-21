#include <cstdlib>

#ifndef LL_H
#define LL_H

template <class type>
class LL
{
private:
	class node
	{
	public:
		node() : data(type()), link(nullptr) {}
		node(type d) : data(d), link(nullptr) {}

		type data;
		node * link;
	};

	node * head;
	node * tail;

	bool isEmpty() const { return head == nullptr; }

public:
	LL() : head(nullptr), tail(nullptr) {}
	LL(const LL<type>&);
	const LL<type>& operator=(const LL<type>&);
	~LL();

	void push_back(const type&);
	type pop_front();
	type peek() const;
};

#include "LL.cpp"

#endif