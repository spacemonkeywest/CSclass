#include "studentDetails.h"

studentDetails::studentDetails() {}

studentDetails::studentDetails(string fName, string lName, int bYear, 
   int yEnroll) 
{
   firstName = fName;
   lastName = lName;
   birthYear = bYear;
   yEnrolled = yEnroll;
}

void studentDetails::setStudentDetails(string fName, string lName, 
   int bYear, int yEnroll) 
{
   firstName = fName;
   lastName = lName;
   birthYear = bYear;
   yEnrolled = yEnroll;
}

string studentDetails::getFirstName() const 
{
   return firstName;
}

string studentDetails::getLastName() const 
{
   return lastName;
}

int studentDetails::getBirthYear() const 
{
   return birthYear;
}

int studentDetails::getYearEnrolled() const
{
   return yEnrolled;
}

void studentDetails::printStudentDetails() const
{
   cout << "Name: " << firstName << " " << lastName << ',';
   cout << "Birth Year: " << birthYear << ',';
   cout << "Year Enrolled: " << yEnrolled << std::endl;
}
