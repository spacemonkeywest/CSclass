/*
Name: Carlos Aldaco Flores, NSHE: 5008406281, CLASS-SECTION: 1006, 
ASSIGNMENT: 3
Purpose: Multiple classes, Inheritance, Composition
Description: Tuitions and Fee Estimator
Input: main.cpp is a Driver class in this assignment. Objects of 
different classes are declared in main.cpp using constructors, setters
and other functions. Read the students' data from an input file 
"student_data.txt"
What to do?: This system manages student data, including personal 
information and fee calculations based on their degree and residency 
status. The system consists of several classes, each responsible for 
different aspects of student management.You have to check studentID 
based on given conditions, and print the output on console window and 
write the output to a file.
Output: You write the output on the terminal itself and also print the 
output to "Estimated_Fees.txt". You print all valid and invalid entries; 
print error messages for invalid entries accordingly. 
Check example output for more details.
*/
/**
 * @class studentDetails
 * @brief A class to hold and manage basic student information.
 * 
 * This class serves as a base class for managing student details 
 * such as name, birth year, and enrollment year. It provides methods
 * to set and retrieve these details.
 */
#ifndef STUDENTDETAILS_H
#define STUDENTDETAILS_H
#include<iostream>
#include<string>
using namespace std;
//Base class 1
class studentDetails{
public:
/**
     * @brief Default constructor for studentDetails.
     * 
     * Initializes a studentDetails object with default values: empty 
     * strings for names and zeros for birth year and enrollment year.
     */
    studentDetails(); //Default constructor
/**
     * @brief Parameterized constructor for studentDetails.
     * 
     * @param fName The first name of the student (string).
     * @param lName The last name of the student (string).
     * @param bYear The birth year of the student (integer).
     * @param yEnroll The year the student enrolled (integer).
     */    

    studentDetails(string fName, string lName, int bYear, int yEnroll);

/**
     * @brief Sets multiple student attributes.
     * 
     * This method allows updating the student's details in one call.
     * 
     * @param fName The first name of the student (string).
     * @param lName The last name of the student (string).
     * @param bYear The birth year of the student (integer).
     * @param yEnroll The year the student enrolled (integer).
     * @return None.
     */
  /*Mutator Method-Setter function*/
    void setStudentDetails(string fName, string lName, int bYear, 
      int yEnroll);

/*Accessor Methods*/
/**
     * @brief Retrieves the student's first name.
     * 
     * @return The first name of the student (string).
     */
   string getFirstName() const;
   
/**
     * @brief Retrieves the student's last name.
     * 
     * @return The last name of the student (string).
     */   
   string getLastName() const;
 
/**
     * @brief Retrieves the student's birth year.
     * 
     * @return The birth year of the student (integer).
     */
   int getBirthYear() const;
   
/**
     * @brief Retrieves the year the student enrolled.
     * 
     * @return The year the student enrolled (integer).
     */
   int getYearEnrolled() const;
   
/*Utility Methods*/
/**
     * @brief Prints the student's details.
     * 
     * This method outputs the student's name, birth year, and enrollment
     * year to the console.
     * 
     * @return None.
     */
   void printStudentDetails() const;
       
 protected:
   string firstName; //variable to store the first name
   string lastName;  //variable to store the last name
   int birthYear; //variable to store the birth month
   int yEnrolled; // variable to store the year that student has enrolled

};
#endif