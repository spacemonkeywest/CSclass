/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 8
    Description: Implementation of LL.h for a singly linked list.
    Input: Void
    Output: Exceptions if trying to access elements from an empty list.
*/

#include <iostream>
#include <string>
#include <fstream>
#include "emptyList.h"
#include "LL.h"

// Copy constructor: Creates a deep copy of the linked list
template <class type>
LL<type>::LL(const LL<type>& copy)
{
   // If the list is empty, initialize the new list as empty as well
   if (!copy.head)
   {
      head = tail = nullptr;
      return;
   }

   // Initialize the new list with the first node of the copied list
   node* otherCurrent = copy.head;
   head = new node(otherCurrent->data);
   tail = head;

   // Traverse the copied list and create new nodes in the new list
   while (otherCurrent->link)
   {
      otherCurrent = otherCurrent->link;
      node* newNode = new node(otherCurrent->data);
      tail->link = newNode;  // Link the current node to the new node
      tail = newNode;        // Move the tail to the new node
   }
}

// Assignment operator: Assigns one linked list to another (deep copy)
template <class type>
const LL<type>& LL<type>::operator=(const LL<type>& rhs)
{
   // Avoid self-assignment
   if (this != &rhs)
   {
      // Clear the current list by popping all elements
      while (head)
      {
         pop_front();
      }

      // Initialize the new list as empty
      if (!rhs.head)
      {
         head = tail = nullptr;
         return *this;
      }

      // Copy the first node of the right-hand side list
      head = new node(rhs.head->data);
      tail = head;
      node* otherCurrent = rhs.head;

      // Copy the rest of the nodes
      while (otherCurrent->link)
      {
         otherCurrent = otherCurrent->link;
         node* newNode = new node(otherCurrent->data);
         tail->link = newNode;  // Link the current node to the new node
         tail = newNode;        // Move the tail to the new node
      }
   }

   return *this;
}


// Destructor: Frees all nodes in the list to prevent memory leaks
template <class type>
LL<type>::~LL()
{
   node* current = head;
   // Traverse the list and delete each node
   while (current)
   {
      node* temp = current;
      current = current->link;
      delete temp;
   }

   // Set head and tail to null as the list is now empty
   head = tail = nullptr;
}

// Push a new item to the end of the list
template <class type>
void LL<type>::push_back(const type& item)
{
   // If the list is empty, create the first node
   if (!head)
   {
      head = new node(item);
      tail = head;
   }
   else
   {
      // Otherwise, add the new node to the end of the list
      tail->link = new node(item);
      tail = tail->link;
   }
}

// Pop the first item from the list (remove it) and return its value
template <class type>
type LL<type>::pop_front()
{
   // If the list is empty, throw an exception
   if (!head)
   {
      throw emptyList();  // Throws exception if the list is empty
   }

   node* temp = head;
   head = head->link;  // Move the head to the next node
   type data = temp->data;  // Save the data from the removed node
   delete temp;  // Free the memory of the removed node

   // If the list becomes empty after removal, set the tail to nullptr
   if (!head)
   {
      tail = nullptr;
   }

   return data;  // Return the data from the removed node
}

// Peek at the first item in the list and return its value
template <class type>
type LL<type>::peek() const
{
   // If the list is empty, throw an exception
   if (!head)
   {
      throw emptyList();  // Throws exception if the list is empty
   }

   return head->data;  // Return the data of the first node
}
