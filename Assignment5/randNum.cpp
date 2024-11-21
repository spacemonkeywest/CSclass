/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 5
    Description: Implementation of randNum.h
    Input: File containing random numbers
    Output: Void
*/

#include "randNum.h"
#include <string>
using namespace std;

// Definition of constructor
randNum::randNum(string fileName)
{
   infile.open(fileName);
}

// Definition of getNextRand()
int randNum::getNextRand()
{
   int number;
   infile >> number;
   return number;
}

// Definition of destructor
randNum::~randNum()
{
   infile.close();
}