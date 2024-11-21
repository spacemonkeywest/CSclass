/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 5
    Description: A class representing an animal
    Input: Initial size, growth rate, and food need
    Output: Void
*/

#ifndef ANIMAL_H
#define ANIMAL_H

#include "organism.h"

/*
* class_identifier: Represents an animal
* constructors: Initial size, growth rate, and food need
* public functions:  animal ( double = 1 , double = 0 , double = 0);
                     void assignNeed ( double );
                     void eat ( double );
                     void simulateWeek ();
                     double stillNeed () const ;
                     double totalNeed () const ;
                     ~ animal ();
* static members: Void
*/
class animal : public organism
{
public:
/*
   * function_identifier: Constructor
   * parameters: Initial size, growth rate, and food need of animal
   * return value: Void
   */
	animal(double = 1, double = 0, double = 0);
   /*
   * function_identifier: sets new food need
   * parameters: New need amount
   * return value: Void
   */
	void assignNeed(double);
   /*
   * function_identifier: Increases food eaten by amount
   * parameters: Amount of food eaten
   * return value: Void
   */
	void eat(double);
   /*
   * function_identifier: Adds growth rate to size
   * parameters: Void
   * return value: Void
   */
	void simulateWeek();
   /*
   * function_identifier: Gets food amount still needed
   * parameters: Void
   * return value: Void
   */
	double stillNeed() const;
   /*
   * function_identifier: Gets total food amount needed
   * parameters: Void
   * return value: Void
   */
	double totalNeed() const;
   /*
   * function_identifier: Destructor
   * parameters: Void
   * return value: Void
   */
	~animal();
private:
   // Stores food need for a week
	double needThisWeek;
   // Stores food eaten this week
	double eatenThisWeek;
};

#endif // ANIMAL_H