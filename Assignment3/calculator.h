/*
Name: Carlos Aldaco Flores, NSHE: 5008406281, CLASS-SECTION: 1006, 
ASSIGNMENT: 3
Purpose: Multiple classes, Inheritance, Composition
Description: Tuitions and Fee Estimator
Input: main.cpp is a Driver class in this assignment. 
Objects of different classes are declared in main.cpp using constructors,
setters, and other functions. Read the students' data from an input file
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
 * @class calculator
 * @brief A class to calculate tuition fees based on student details.
 *
 * This class provides functionality to compute tuition fees for 
 * undergraduate and graduate students
 * based on their residency status and required credits. 
 * It also prints student data.
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<iostream>
#include<iomanip>
#include "studentDetails.h"
#include "studentType.h"


class calculator{
public:
/**
     * @brief Default constructor for calculator.
     * Initializes the calculator with a default studentType object.
     */

    calculator(); //Default constructor
/**
     * @brief Parameterized constructor for calculator.
     * 
     * @param stdObj A reference to a studentType object containing 
     * student details.
     */

    calculator(studentType &stdObj); // Parameterized constructor

/**
     * @brief Calculates the tuition fee for a given student.
     * 
     * This method computes the tuition fee based on the student's degree
     * and residency status.
     * It can also print details of the calculations if specified.
     * @param stdObj A constant reference to a studentType object 
     * containing student details.
     * @param printDetails A boolean indicating whether to print detailed
     * calculation steps (default is false).
     * @return double The total calculated tuition fee.
     */

    double calculateTuition(const studentType &stdObj, 
    bool printDetails=false);

/**
     * @brief Prints the details of the student associated with the 
     * calculator.
     * 
     * This method calls the print method from the studentType class 
     * to display student information.
     * 
     * @return None.
     */
    
    void printAllStudentData() const;

    //const values for the fess
    static constexpr double undergradResident=109.55;
    static constexpr double undergradNonResident=317.25;
    static constexpr double gradResident=123.25;
    static constexpr double gradNonResident=388.75;
    static constexpr double nonResidentYearFee=18150.10;
    static constexpr double intInsuranceYearFee=4100.00; 
    // international insurance
private:
    studentType stdTypeObj; //composition: holds a studentType object
};

#endif



