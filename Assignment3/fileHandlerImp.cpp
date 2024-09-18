/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 3
    Description: This program is an implementation file for fileHandler.h
    Input: filename to read from
    Output: Writing to file or console about student details
*/

#include "fileHandler.h"
#include "calculator.h"

/*
* function_identifier: reads data from file into an object and puts it
* int a vector
* parameters: name of file
* return value: vector containing studentType objects
*/
std::vector<studentType> fileHandler::readStudentData(const std::string&
   filename) 
{  
   // For return
   std::vector<studentType> students;

   ifstream inFile(filename);

   // If file fails to open
   if (inFile.fail())
   {
      std::cout << "Error: File could not be opened." << std::endl;
      return {};
   }

   // Ignore first line
   std::string firstLine;
   std::getline(inFile, firstLine);

   // To store each detail for student
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
   // reads each student detail into the object
   while (inFile >> fName >> lName >> bYear >> yEnrolled >> id >> dept1
      >> dept2 >> degree >> residence >> credRequired >> gradYears)
   {
      studentType student;
      student.setStudentDetails(fName, lName, bYear, yEnrolled, id, 
         dept1 + dept2, degree, residence, credRequired, gradYears);

      students.push_back(student);
      if (!student.checkStudentID(id)) 
      {
         // Displays all the invalid id's at the start of main output
         std::cout << "Invalid ID for the student: " << fName << " " 
            << lName << '\n'; 
      }
   }
   inFile.close();

   return students;
}

/*
* function_identifier: Writes student data into file
* parameters: name of output file and vector with studentType objects
* return value: void
*/
void fileHandler::writeFeeData(const std::string& filename, 
   const std::vector<studentType>& students) 
{
   ofstream outFile(filename);

   // If file fails to open
   if (outFile.fail())
   {
      std::cout << "Error: File could not be opened.";
      return;
   }
   outFile << fixed << setprecision(2);
   outFile << "Student Fee Calculations:\n";

   for (int i = 0; i < students.size(); i++) 
   {
         calculator fee;

         // Student number starting at 1
         outFile << "Student: " << (i+1) << '\n';

      // If id is valid
      if (students[i].checkStudentID(students[i].getStudentID()))
      {
         outFile << "Name: " << students[i].getFirstName() 
            << students[i].getLastName() << '\n';
         outFile << "Birth Year: " << students[i].getBirthYear() << ','
            << " Year Enrolled: " 
            << students[i].getYearEnrolled() << '\n';
         outFile << "Student ID: " << students[i].getStudentID() << ','
            << " Department: " << students[i].getDepartment() << '\n';
         outFile << "Degree: " << students[i].getDegree() << ','
            << " Residency: " << students[i].getResidency() << '\n';
         outFile << "Credits Required: " 
            << students[i].getCreditsRequired()
            << ',' << " Years to Graduate: " 
            << students[i].getYearstoGrad() << '\n';
         outFile << "Estimated Total: " 
            << fee.calculateTuition(students[i], false)
            << '\n';
      }
      else
      {
         outFile << "\nInvalid ID for the student (To File): " <<
            students[i].getFirstName() << students[i].getLastName() 
            << '\n' << '\n';
      }
   }

   outFile.close();
}