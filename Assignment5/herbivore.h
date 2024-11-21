/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 5
    Description: A class representing an herbivore
    Input: Initial size, growth rate, and food need
    Output: Void
*/

#ifndef HERBIVORE_H
#define HERBIVORE_H

#include "animal.h"
#include "plant.h"

/*
* class_identifier: Represents an herbivore
* constructors: Initial size, growth rate, and food need
* public functions:  herbivore ( double = 1 , double = 0 , double = 0);
                     void nibble ( plant &);
                     ~ herbivore ();
* static members: Void
*/
class herbivore : public animal
{
public:
   // Stores the portion of plant that is eaten
	static const double PORTION;  
   // Stores max amount of food that can be eaten
	static const double MAX_FRACTION;
   /*
   * function_identifier: Constructor
   * parameters: Initial size, growth rate, and food need of org
   * return value: Void
   */
	herbivore(double = 1, double = 0, double = 0);
   /*
   * function_identifier: Increases food consumed this week
   * parameters: Plant object
   * return value: Void
   */
	void nibble(plant&);
   /*
   * function_identifier: Destructor
   * parameters: Void
   * return value: Void
   */
	~herbivore();
};

#endif // HERBIVORE_H