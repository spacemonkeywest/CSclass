#include <iostream>
#include <string>
#include <fstream>
#include "emptyList.h"

// Linked header file
#include "LL.h"

template <class type>
LL<type>::LL(const LL<type>& copy)
{
   if (!copy.head)
   {
      head = tail = nullptr;
      return;
   }
	node<type>* otherCurrent = copy.head;
   head = new node(otherCurrent->data);
   tail = head;

   while (otherCurrent->link)
   {
      otherCurrent = otherCurrent->link;
      node<type>* newNode = new node(otherCurrent->data);
      tail->link = newNode;
      tail = newNode;
   }
}

template <class type>	
const LL<type>& LL<type>::operator=(const LL<type>& rhs)
{
	if (this != &rhs)
	{
		while (head)
      {
         pop_front();
      }

      if (!rhs.head)
      {
         head = tail = nullptr;
         return *this;
      }

      node<type>* head = new node(rhs.head);
      tail = head;
      node<type>* otherCurrent = rhs.head;

      while (otherCurrent->link)
      {
         node<type>* newNode = new node(otherCurrent->data);
         tail->link = newNode;
         tail = newNode;
         otherCurrent = otherCurrent->link;
      }
	}

	return *this;
}

template <class type>
LL<type>::~LL()
{
	node<type>* current = head;
   while (current)
   {
      node<type>* temp = current;
      current = current->link;
      delete temp;
   }

   head = tail = nullptr;
}

template <class type>
void LL<type>::push_back(const type& item)
{
   if (!head)
      {
         head = new node(item);
         tail = head;
      }
      else
      {
         tail->link = new node(item);
         tail = tail->link;
      }
}

template <class type>
type LL<type>::pop_front()
{
	if (!head)
   {
      throw emptyList;
   }

   node<type>* temp = head;
   head = head->link;
   type data = temp->data;
   delete temp;

   if (!head)
   {
      tail = nullptr;
   }

   return data;
}

template <class type>
type LL<type>::peek() const
{
	if (!head) 
   {
      throw emptyList;
   }

   return head->data;
}
