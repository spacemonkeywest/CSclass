/*
Name: Carlos Aldaco Flores, NSHE: 5008406281, CLASS-SECTION: 1006, 
ASSIGNMENT: 3
Purpose: Multiple classes, Inheritance, Composition
Description: Tuitions and Fee Estimator
Input: main.cpp is a Driver class in this assignment. Objects of different 
classes are declared in main.cpp using constructors, setters and 
other functions. Read the students' data from an input file 
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
 * @class studentType
 * @brief Base class for undergraduate and graduate student types.
 * 
 * This class encapsulates the details related to a student, including 
 * personal information, identification, academic department, degree, 
 * residency status, required credits, and years remaining to graduate.
 */
#ifndef STUDENTTYPE_H
#define STUDENTTYPE_H
#include<iostream>
#include "studentDetails.h"
using namespace std;
//Derived class- Inheritance
class studentType: public studentDetails
{
public:
    /**
         * @brief Default constructor for studentType.
         * Initializes studentID, department, stdDegree, residency, 
         * and credits. Required to default values.
         */
    studentType(); // Default constructor
    
    // Parameterized constructor
    /**
     * @brief Parameterized constructor for studentType.
     * 
     * @param fName First name of the student.
     * @param lName Last name of the student.
     * @param bYear Birth year of the student.
     * @param yEnroll Year the student enrolled.
     * @param ID Unique student ID.
     * @param dept Academic department.
     * @param degree Type of degree.
     * @param residence Residency status.
     * @param credsReqd Credits required for graduation.
     * @param gradYears Years remaining until graduation.
     */
    studentType(string fName, string lName,
                int bYear, int yEnroll, string ID, string dept, 
                string degree, string residence, int credsReqd, 
                int gradYears);
    
    //Mutator method
    /**
     * @brief Sets the details of the student.
     * 
     * @param fName First name of the student.
     * @param lName Last name of the student.
     * @param bYear Birth year of the student.
     * @param yEnroll Year the student enrolled.
     * @param ID Unique student ID.
     * @param dept Academic department.
     * @param degree Type of degree.
     * @param residence Residency status.
     * @param credsReqd Credits required for graduation.
     * @param gradYears Years remaining until graduation.
     */
    void setStudentDetails(string fName, string lName,
                int bYear, int yEnroll, string ID, string dept, 
                string degree, string residence, int credsReqd, 
                int gradYears);

    //Accessor Methods
    /**
     * @brief Retrieves the student's ID.
     * 
     * @return string representing the student ID.
     */
    string getStudentID() const; // Returns student ID

    /**
     * @brief Retrieves the student's department.
     * 
     * @return string representing the department.
     */
    string getDepartment() const; // Returns department

    /**
     * @brief Retrieves the student's degree.
     * 
     * @return string representing the degree.
     */
    string getDegree() const; // Returns degree

    /**
     * @brief Retrieves the student's residency status.
     * 
     * @return string representing the residency status.
     */
    string getResidency() const; // Returns residency status

    /**
     * @brief Retrieves the number of credits required to graduate.
     * 
     * @return int representing the credits required.
     */
    int getCreditsRequired() const; // Returns credits required

    /**
     * @brief Retrieves the years remaining until graduation.
     * 
     * @return int representing the years to graduate.
     */
    int getYearstoGrad() const; // Returns years to graduate

    //Utility Methods
    /**
     * @brief Converts a string to lowercase.
     * 
     * @param str The string to convert.
     * @return string The converted lowercase string.
     */
    static string toLowerCase(const string &str); 

    /**
     * @brief Checks if the provided student ID is valid.
     * 
     * @param idTemp The ID to check.
     * @return bool True if the ID is valid, false otherwise.
     */
    bool checkStudentID(string idTemp) const; 
    /*
    first 3 characters of last name + first and second digit of birth 
    year + third and fourth digit of enrolled year
    */
    
    /**
     * @brief Prints the details of the student.
     * 
     * This function outputs the student's details, including ID, department,
     * degree, residency status, credits required, and years to graduate.
     */
    void printStudentTypeData() const;
    
private:
    string studentID; //variable to store the student ID
    string department; //variable to store the department
    string stdDegree; //variable to store the degree like grad or ungrad
    string residency; //variable to store it Resident or International
    int creditsRequired; //variable to store the credits required
    int yearstoGrad; //variable to store the number of years to graduate

};

#endif
