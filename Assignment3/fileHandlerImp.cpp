#include "fileHandler.h"
#include "calculator.h"

std::vector<studentType> fileHandler::readStudentData(const std::string&
   filename) 
{
   std::vector<studentType> students;

   ifstream inFile(filename);

   // Ignore first line
   std::string firstLine;
   std::getline(inFile, firstLine);

   std::string fName;
   std::string lName;
   int bYear;
   int yEnrolled;
   std::string id;
   std::string dept1;
   std::string dept2;
   std::string degree;
   std::string residence;
   int credRequired;
   int gradYears; 
   while (std::cin >> fName >> lName >> bYear >> yEnrolled >> id >> dept1
      >> dept2 >> degree >> residence >> credRequired >> gradYears)
   {
      studentType student;
      student.setStudentDetails(fName, lName, bYear, yEnrolled, id, 
         dept1 + dept2, degree, residence, credRequired, gradYears);

      students.push_back(student);
   }
   inFile.close();

   return students;
}

void fileHandler::writeFeeData(const std::string& filename, 
   const std::vector<studentType>& students) 
{
   ofstream outFile(filename);
   if (outFile.fail())
   {
      std::cout << "Error: File could not be opened.";
   }

   std::cout << fixed<< setprecision(2);

   outFile << "Student Fee Calculations:\n";

   for (int i = 0; i < students.size(); i++) 
   {
      if (!students[i].checkStudentID(students[i].getStudentID()))
      {
         outFile << "Invalid ID for the student (To File): " <<
            students[i].getFirstName() << students[i].getLastName() << '\n';
      }

      calculator fee;

      outFile << "Student: " << (i+1);
      outFile << "Name: " << students[i].getFirstName() 
         << students[i].getLastName() << '\n';
      outFile << "Birth Year: " << students[i].getBirthYear() << ','
         << "Year Enrolled: " << students[i].getYearEnrolled() << '\n';
      outFile << "Student ID: " << students[i].getStudentID() << ','
         << "Department: " << students[i].getDepartment() << '\n';
      outFile << "Degree: " << students[i].getDegree() << ','
         << "Residency: " << students[i].getResidency() << '\n';
      outFile << "Credits Required: " << students[i].getCreditsRequired()
         << ',' << "Years to Graduate: " << students[i].getYearstoGrad()
         << '\n';
      outFile << "Estimated Total: " << fee.calculateTuition(students[i])
         << '\n';
   }
}