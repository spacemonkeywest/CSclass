/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 5
    Description: A class representing an organism
    Input: Initial size and growth rate
    Output: Void
*/

#ifndef ORGANISM_H
#define ORGANISM_H

/*
* class_identifier: Represents an organism
* constructors: Initial size and growth rate
* public functions:  organism ( double = 1 , double = 0);
                     virtual void simulateWeek ();
                     void assignRate ( double );
                     void alterSize ( double );
                     void death ();
                     double getSize () const ;
                     double getRate () const ;
                     bool isAlive () const ;
                     virtual ~ organism ();
* static members: Void
*/
class organism
{
public:
   /*
   * function_identifier: Constructor
   * parameters: Initial size and growth rate of org
   * return value: Void
   */
	organism(double = 1, double = 0);
   /*
   * function_identifier: Adds growthRate to size
   * parameters: Void
   * return value: Void
   */
	virtual void simulateWeek();
   /*
   * function_identifier: Changes growth rate
   * parameters: New growth rate
   * return value: Void
   */
	void assignRate(double);
   /*
   * function_identifier: Adds to size
   * parameters: Decimal to add to size
   * return value: Void
   */
	void alterSize(double);
   /*
   * function_identifier: Sets size and rate to 0
   * parameters: Void
   * return value: Void
   */
	void death();
   /*
   * function_identifier: Gets size
   * parameters: Void
   * return value: Size
   */
	double getSize() const;
   /*
   * function_identifier: Gets growth rate
   * parameters: Void
   * return value: Growth rate
   */
	double getRate() const;
   /*
   * function_identifier: Checks if size > 0
   * parameters: Void
   * return value: True if alive, false if not
   */
	bool isAlive() const;
   /*
   * function_identifier: Destructor
   * parameters: Void
   * return value: Void
   */
	virtual ~organism();
protected:
   // Stores growth rate of organism
	double growthRate;
private:
   // Stores size of organism
	double size;
};

#endif // ORGANISM_H
