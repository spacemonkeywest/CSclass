/*
 * Name: KISHORE, NSHE: ABC123, CLASS-SECTION: CS202, ASSIGNMENT: 3
 * Purpose: Multiple classes, Inheritance, Composition
 * Description: Tuitions and Fee Estimator
 * Input: main.cpp is a Driver class in this assignment. 
 * Objects of different classes are declared in main.cpp using 
 * constructors, setters and other functions. Read the students' 
 * data from an input file "student_data.txt"
 * What to do?: This system manages student data, including personal 
 * information and fee calculations based on their degree and residency 
 * status. The system consists of several classes, each responsible for
 * different aspects of student management.You have to check studentID 
 * based on given conditions, and print the output on console window and 
 * write the output to a file.
 * Output: You write the output on the terminal itself and also print the
 * output to "Estimated_Fees.txt". You print all valid and 
 * invalid entries; print error messages for invalid entries accordingly.
 * Check example output for more details.
*/

/**
 * @class fileHandler
 * @brief A class to handle file operations related to student data.
 * 
 * This class provides functionality to read student data from a file
 * and write calculated fee data for students into a 
 * specified output file.
 * It utilizes the studentType and calculator classes to manage student 
 * information and fee calculations.
 */

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
#include <string>
#include <vector>
#include "studentType.h"
//Composition- has a relationship
/* The fileHandler class has methods that operate on studentType objects. 
It reads and writes data related to students using instances of 
studentType, indicating that fileHandler is composed of studentType
instances.
Functionality: The methods readStudentData and writeFeeData utilize 
studentType to manage student information without inheriting from it, 
which aligns with the concept of composition.*/
class fileHandler {
public:
/**
     * @brief Reads student data from a specified file.
     * 
     * This method reads student information from a file, creates 
     * studentType objects, 
     * and stores them in a vector. It checks the validity of each 
     * student's ID.
     * 
     * @param filename The name of the file to read student data 
     * from (string).
     * @return std::vector<studentType> A vector of studentType objects
     *  containing the read student data.
     */
    std::vector<studentType> readStudentData(const std::string& filename);
    
/**
     * @brief Writes calculated fee data for students into a 
     * specified file.
     * 
     * This method processes each student, calculates their tuition
     * using the calculator class, 
     * and writes the results to an output file. It includes 
     * error handling for invalid student IDs.
     * 
     * @param filename The name of the file to which the fee data 
     * will be written (string).
     * @param students A vector of studentType objects containing 
     * student data (const std::vector<studentType>&).
     * @return None.
     */
    void writeFeeData(const std::string& filename, 
        const std::vector<studentType>& students);
};

#endif