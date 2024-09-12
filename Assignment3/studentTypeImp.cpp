#include "studentType.h"

studentType::studentType()
{
   studentID = "";
   department = "";
   stdDegree = "";
   residency = "";
   creditsRequired = 0;
   yearstoGrad = 0;
}

studentType::studentType(string fName, string lName, int bYear,
   int yEnroll, string ID, string dept, string degree, string residence,
   int credsReqd, int gradYears)
{
   firstName = fName;
   lastName = lName;
   birthYear = bYear;
   yEnrolled = yEnroll;
   studentID = ID;
   department = dept;
   stdDegree = degree;
   residency = residence;
   creditsRequired = credsReqd;
   yearstoGrad = gradYears;
}

void studentType::setStudentDetails(string fName, string lName, 
               int bYear, int yEnroll, string ID, string dept, 
               string degree, string residence, int credsReqd, 
               int gradYears)
{
   firstName = fName;
   lastName = lName;
   birthYear = bYear;
   yEnrolled = yEnroll;
   studentID = ID;
   department = dept;
   stdDegree = degree;
   residency = residence;
   creditsRequired = credsReqd;
   yearstoGrad = gradYears;
}

string studentType::getStudentID() const 
{
   return studentID;
}

string studentType::getDepartment() const 
{
   return department;
}


string studentType::getDegree() const 
{
   return stdDegree;
}


string studentType::getResidency() const 
{
   return residency;
}


int studentType::getCreditsRequired() const 
{
   return creditsRequired;
}

int studentType::getYearstoGrad() const 
{
   return yearstoGrad;
}

string studentType::toLowerCase(const string &str)
{
   string newStr = "";
   for (int i = 0; i < str.size(); i++)
   {
      newStr += tolower(str[i]);
   }

   return newStr;
}

bool studentType::checkStudentID(string idTemp) const
{
   string realID = "";
   realID += lastName[0] + lastName[1] + lastName[2];
   realID += ((birthYear / 1000) + '0') + (((birthYear / 100) % 10) + '0');
   realID += (((yEnrolled%100) / 10)) + '0' + ((yEnrolled % 10) + '0');

   return realID == idTemp;
}

void studentType::printStudentTypeData() const
{
   studentDetails::printStudentDetails();
   cout << "Student ID: " << studentID << ',';
   cout << "Department: " << department << ',';
   cout << "Degree: " << stdDegree << '\n';
   cout << "Residency: " << residency;
}

