/*
   Name: Carlos Aldaco Flores, 5008406281, 1006, 3
   Description: This program is an implementation file for 
   studentDetails.h
   Input: Void
   Output: Writing student details to console.
*/

#include "studentDetails.h"

/*
* function_identifier: Default constructor for studentDetails
* parameters: void
* return value: void
*/
studentDetails::studentDetails() 
{
   firstName = "";
   lastName = "";
   birthYear = 0;
   yEnrolled = 0;
}

/*
* function_identifier: Constructor for studentDetails
* parameters: void
* return value: void
*/
studentDetails::studentDetails(string fName, string lName, int bYear, 
   int yEnroll) 
{
   firstName = fName;
   lastName = lName;
   birthYear = bYear;
   yEnrolled = yEnroll;
}

/*
* function_identifier: Sets student details
* parameters: void
* return value: void
*/
void studentDetails::setStudentDetails(string fName, string lName, 
   int bYear, int yEnroll) 
{
   firstName = fName;
   lastName = lName;
   birthYear = bYear;
   yEnrolled = yEnroll;
}

/*
* function_identifier: gets first name
* parameters: void
* return value: string containing first name
*/
string studentDetails::getFirstName() const 
{
   return firstName;
}

/*
* function_identifier: gets last name
* parameters: void
* return value: string containing last name
*/
string studentDetails::getLastName() const 
{
   return lastName;
}

/*
* function_identifier: gets birth year
* parameters: void
* return value: int containing birth year
*/
int studentDetails::getBirthYear() const 
{
   return birthYear;
}

/*
* function_identifier: gets year enrolled
* parameters: void
* return value: int containing year enrolled
*/
int studentDetails::getYearEnrolled() const
{
   return yEnrolled;
}

/*
* function_identifier: Prints student details
* parameters: void
* return value: void
*/
void studentDetails::printStudentDetails() const
{
   cout << "Name: " << firstName << " " << lastName << ',';
   cout << " Birth Year: " << birthYear << ',';
   cout << " Year Enrolled: " << yEnrolled << endl;
}
