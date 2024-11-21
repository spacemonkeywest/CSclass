/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 5
    Description: A class representing a random number
    Input: File containing random numbers
    Output: Void
*/

#ifndef RAND_NUM_H
#define RAND_NUM_H

#include <fstream>
using namespace std;

/*
* class_identifier: Represents a random number
* constructors: Open file
* public functions:  randNum ( string );
                     int getNextRand ();
                     ~ randNum ();
* static members: Void
*/
class randNum
{
public:
    /*
    * function_identifier: Constructor
    * parameters: Name of file
    * return value: Void
    */ 
    randNum(string);
    /*
    * function_identifier: Destructor
    * parameters: Void
    * return value: Void
    */
    ~randNum();
    /*
    * function_identifier: Gets next number in file
    * parameters: Void
    * return value: Number from file
    */
    int getNextRand();
private:
    // Stores an open file
    ifstream infile;
};

#endif // RAND_NUM_H