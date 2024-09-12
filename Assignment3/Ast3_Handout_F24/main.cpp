/*
Name: KISHORE, NSHE: ABC123, CLASS-SECTION: CS202, ASSIGNMENT: 3
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
#include <iostream>
#include "fileHandler.h"
#include "studentType.h"
#include "calculator.h"
#include "studentDetails.h"

int main() {
    fileHandler fh;
    calculator studentFee;
    int stdCount = 0; //Student count
    vector<studentType> students = fh.readStudentData("student_data.txt");
    cout << fixed << setprecision(2)<< endl;

    cout << "\nStudent Fee Calculations:\n";
     
    // Test case 1: Create studentType object that can set the following parameters
    studentType student("Sophia", "Taylor", 1998, 2020, "tay2920",
     "Computer Science", "Undergraduate", "International", 120, 4);
    cout <<"Student: "<< ++stdCount << endl;
    student.printStudentTypeData();

    double sFee= studentFee.calculateTuition(student, true);
    cout << "Estimated Fee in Total: " << sFee << endl << endl;


    // Test case 2: Create another studentType object using studentDetails
    studentDetails sdObj("Luke", "Tucker", 2001, 2023);
    studentType student2(sdObj.getFirstName(), sdObj.getLastName(), 
                         sdObj.getBirthYear(), sdObj.getYearEnrolled(), 
                         "tuc2023", "Civil Engineering", "Graduate", 
                         "International", 34, 3);
    cout <<"Student: "<< ++stdCount << endl;
    student2.printStudentTypeData();
    sFee= studentFee.calculateTuition(student2, true);
    cout << "Estimated Fee in Total: " << sFee << endl << endl;

    // Test case 3: Iterate through the vector of studentType objects
    for (const auto& student : students) {
        cout << "Student: "<< ++stdCount << endl;
        student.printStudentTypeData(); /* This function calls 
                                        printStudentDetails() and prints 
                                        all the information from 
                                        studentType and prints the other 
                                        details of student.*/
        calculator feeCalculator;
        double fee = feeCalculator.calculateTuition(student, true);
        cout << fixed << setprecision(2);
        cout << "Estimated Fee in Total: " << fee << endl << endl;
    }

    // Test case 4: Test setting and getting student details
    student.setStudentDetails("Alice", "Johnson", 2000, 2020, "joh2020",
     "Biology", "Undergraduate", "Resident", 120, 4);
    cout <<"Student: "<< ++stdCount << endl;
    student.printStudentTypeData();
    double updatedFee = studentFee.calculateTuition(student, true);
    cout << "Updated Calculated Fee: " << updatedFee << endl << endl;

    fh.writeFeeData("Estimated_Fees.txt", students);
    
    return 0;
}
