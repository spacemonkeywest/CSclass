/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 5
    Description: Implementation file for organism.h
    Input: Initial size and rate
    Output: Void
*/

#include "organism.h"

// Definition of organism constructor
organism::organism(double initSize, double initRate) : size(initSize), growthRate(initRate) {}

// Definition of simulateWeek()
void organism::simulateWeek()
{
   size += growthRate;
}

// Definition of assignRate(double)
void organism::assignRate(double r)
{
   growthRate = r;
}

// Definition of alterSize(double)
void organism::alterSize(double amount)
{
   size += amount;
}

// Definition of death()
void organism::death()
{
   size = 0;
   growthRate = 0;
}

// Definition of getRate()
double organism::getRate() const
{
   return growthRate;
}

// Definition of getSize()
double organism::getSize() const
{
   return size;
}

// Definition of isAlive()
bool organism::isAlive() const
{
   return size > 0;
}

// Definition of organism destructor
organism::~organism()
{
   size = 0;
   growthRate = 0;
}