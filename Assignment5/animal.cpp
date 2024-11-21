/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 5
    Description: Implementation of animal.h
    Input: Initial size, growth rate, and food need
    Output: Void
*/

#include "animal.h"

// Definition of constructor
animal::animal(double initSize, double initRate, double initNeed) 
   : organism::organism(initSize, initRate), needThisWeek(initNeed)
{
   eatenThisWeek = 0;
}

// Definition of assignNeed(double)
void animal::assignNeed(double newNeed)
{
   needThisWeek = newNeed;
}

// Definition of eat(double)
void animal::eat(double amount)
{
   eatenThisWeek += amount;
}

// Definition of simulateWeek()
void animal::simulateWeek()
{
   // Check need of animal
   if (stillNeed() > 0 && growthRate > 0)
   {
      // Reverse
      growthRate *= -1.0;
   }
   
   // Check need of animal
   if (stillNeed() == 0 && growthRate < 0)
   {
      // Reverse
      growthRate *= -1.0;
   }

   // Simulate a single week
   organism::simulateWeek();
   eatenThisWeek = 0;
   // Check if organism is alive
   if (!organism::isAlive())
   {
      organism::death();
   }
}

// Definition of stillNeed()
double animal::stillNeed() const
{
   if (eatenThisWeek >= needThisWeek)
   {
      return 0;
   }

   return (needThisWeek - eatenThisWeek);
}

// Definition of totalNeed()
double animal::totalNeed() const
{
   return needThisWeek;
}

// Definition of destructor
animal::~animal()
{
   needThisWeek = 0;
   eatenThisWeek = 0;
}