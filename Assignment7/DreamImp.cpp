/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 7
    Description: Implementation for Dream.h
    Input: Void
    Output: Console output
*/
#include "Dream.h"
#include <iostream>

// Constructor for Dream
Dream::Dream(int numElements, int value)
{
   dreamLevel = value;
   std::cout << "Start of dream level: " << dreamLevel << std::endl;
   std::cout << "dynamically allocating " << numElements << " Elements."
       <<std::endl;
   // Allocate memory for ptr of size numElements
   ptr = new int[numElements];
   for (size_t i = 0; i < numElements; i++)
   {
      ptr[i] = dreamLevel;
   }
}

// Destructor for Dream
Dream::~Dream()
{
   std::cout << "End of dream level: " << dreamLevel << std::endl;
   // Deallocate memory
   delete[] ptr;
   // Fix dangling pointer
   ptr = nullptr;
}