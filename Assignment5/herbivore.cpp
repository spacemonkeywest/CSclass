/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 5
    Description: Implementation of herbivore.h
    Input: Initial size, growth rate, and food need
    Output: Void
*/

#include "herbivore.h"
#include <iostream>
using namespace std;

const double herbivore::PORTION = 0.5;
const double herbivore::MAX_FRACTION = 0.1;

// Definition of constructor
herbivore::herbivore(double initSize, double initRate, double initNeed) 
   : animal(initSize, initRate, initNeed) {}

// Definition of nibble(plant&)
void herbivore::nibble(plant& meal)
{
   double amount = PORTION * meal.getSize();
   // Set amount
   if (amount > (MAX_FRACTION * animal::totalNeed()))
   {
      amount = (MAX_FRACTION * animal::totalNeed());
   }
   
   // Set amount
   if (amount > animal::stillNeed())
   {
      amount = animal::stillNeed();
   }

   // call eat and nibbledOn
   animal::eat(amount);
   meal.nibbledOn(amount);
}

// Definition of destructor
herbivore::~herbivore()
{
   cout << "FISH DIED" << endl;
}