/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 5
    Description: Implementation of plant.h
    Input: Void
    Output: Void
*/

#include "plant.h"
#include <iostream>
using namespace std;

// Definition of constructor
plant::plant(double initSize, double initRate) : organism::organism(initSize, initRate) {}

// Definition of nibbledOn(double)
void plant::nibbledOn(double amount)
{
   organism::alterSize(-amount);

   if (organism::getSize() < 0)
   {
      organism::alterSize(-organism::getSize());
   }

}

// Definition of constructor
plant::~plant()
{
   cout << "PLANT DIED" << endl;
}