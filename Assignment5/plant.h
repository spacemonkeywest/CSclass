/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 5
    Description: A class representing a plant 
    Input: Initial size and growth rate
    Output: Void
*/

#ifndef PLANT_H
#define PLANT_H

#include "organism.h"

/*
* class_identifier: Represents a plant
* constructors: Initial size and growth rate
* public functions:  plant ( double = 1 , double = 0);
                     void nibbledOn ( double );
                     ~ plant ();
* static members: Void
*/
class plant : public organism
{
public:
   /*
   * function_identifier: Constructor
   * parameters: Initial size and growth rate of plant
   * return value: Void
   */
	plant(double = 1, double = 0);
   /*
   * function_identifier: Decreases size by amount
   * parameters: Amount it decreases by
   * return value: Void
   */
  	void nibbledOn(double);
   /*
   * function_identifier: Destructor
   * parameters: Void
   * return value: Void
   */
	~plant();
};

#endif // PLANT_H