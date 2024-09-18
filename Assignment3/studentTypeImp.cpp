/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 3
    Description: This program is an implementation file for studentType.h
    Input: Void
    Output: Writing student details to console.
*/

#include "studentType.h"

/*
* function_identifier: Default constructor for studentType
* parameters: void
* return value: void
*/
studentType::studentType()
{
   studentID = "";
   department = "";
   stdDegree = "";
   residency = "";
   creditsRequired = 0;
   yearstoGrad = 0;
}

/*
* function_identifier: Constructor for studentType
* parameters: void
* return value: void
*/
studentType::studentType(string fName, string lName, int bYear,
   int yEnroll, string ID, string dept, string degree, string residence,
   int credsReqd, int gradYears)
{
   studentDetails::setStudentDetails(fName, lName, bYear, yEnroll);
   studentID = ID;
   department = dept;
   stdDegree = degree;
   residency = residence;
   creditsRequired = credsReqd;
   yearstoGrad = gradYears;
}

/*
* function_identifier: Sets student details
* parameters: student details like name, id, etc.
* return value: void
*/
void studentType::setStudentDetails(string fName, string lName, 
               int bYear, int yEnroll, string ID, string dept, 
               string degree, string residence, int credsReqd, 
               int gradYears)
{
   studentDetails::setStudentDetails(fName, lName, bYear, yEnroll);
   studentID = ID;
   department = dept;
   stdDegree = degree;
   residency = residence;
   creditsRequired = credsReqd;
   yearstoGrad = gradYears;
}

/*
* function_identifier: Gets student id
* parameters: void
* return value: string containing student id
*/
string studentType::getStudentID() const 
{
   return studentID;
}

/*
* function_identifier: Gets student department
* parameters: void
* return value: string containing student department
*/
string studentType::getDepartment() const 
{
   return department;
}

/*
* function_identifier: Gets student degree
* parameters: void
* return value: string containing student degree
*/
string studentType::getDegree() const 
{
   return stdDegree;
}

/*
* function_identifier: Gets student residency
* parameters: void
* return value: string containing student recidency
*/
string studentType::getResidency() const 
{
   return residency;
}

/*
* function_identifier: Gets student credits required
* parameters: void
* return value: int containing student credits required
*/
int studentType::getCreditsRequired() const 
{
   return creditsRequired;
}

/*
* function_identifier: Gets student years to graduate
* parameters: void
* return value: int containing student years to graduate
*/
int studentType::getYearstoGrad() const 
{
   return yearstoGrad;
}

/*
* function_identifier: Turns string to lowercase
* parameters: original string
* return value: string containing lowercase string
*/
string studentType::toLowerCase(const string &str)
{
   string newStr = "";
   for (int i = 0; i < str.size(); i++)
   {
      newStr += tolower(str[i]);
   }

   return newStr;
}

/*
* function_identifier: Checks if student id is valid
* parameters: current id
* return value: True if id is valid, false if not
*/
bool studentType::checkStudentID(string idTemp) const
{
   string realID = "";
   // Append first three letters of lastName
   realID += toLowerCase(lastName.substr(0, 3));
   
   // Append first two digits of birthYear
   realID += to_string(birthYear).substr(0, 2);
   
   // Append last two digits of yEnrolled
   realID += to_string(yEnrolled).substr(2, 2);

   return realID == idTemp;
}

/*
* function_identifier: Prints student details
* parameters: void
* return value: void
*/
void studentType::printStudentTypeData() const
{
   studentDetails::printStudentDetails();
   cout << "Student ID: " << studentID << ',';
   cout << " Department: " << department << ',';
   cout << " Degree: " << stdDegree << '\n';
   cout << "Residency: " << residency << '\n';
   cout << "Credits Required: " << creditsRequired << ',';
   cout << " Years to Graduate: " << yearstoGrad << '\n';
}

