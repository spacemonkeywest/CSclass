/*
   Name: Carlos Aldaco Flores, 5008406281, 1006, 3
   Description: This program is an implementation file for calculator.h
   Input: Void
   Output: Writing to console for error. Estimated tuition for 
   student object.
*/

#include "calculator.h"

/*
* function_identifier: Default constructor for calculator
* parameters: void
* return value: void
*/
calculator::calculator() {}

/*
* function_identifier: Constructor for calculator
* parameters: void
* return value: void
*/
calculator::calculator(studentType &stdObj)
{
   stdTypeObj.setStudentDetails(stdObj.getFirstName(), 
      stdObj.getLastName(), stdObj.getBirthYear(), 
      stdObj.getYearEnrolled(), 
      stdObj.getStudentID(), stdObj.getDepartment(), stdObj.getDegree(),
      stdObj.getResidency(), stdObj.getCreditsRequired(), 
      stdObj.getYearstoGrad());
}

/*
* function_identifier: Calculates tuition. Displays details if neccessary
* parameters: studentType object, bool for printing details
* return value: double containing tuition cost
*/
double calculator::calculateTuition(const studentType &stdObj, 
    bool printDetails)
{
   double fee = 0.0;
   if (!printDetails)
   {
      if (stdObj.getDegree() == "Undergraduate") 
      {
         // If undergraduate resident
         if (stdObj.getResidency() == "Resident") 
         {
            fee = undergradResident * stdObj.getCreditsRequired();
         } 
         else
         {
            // If undergraduate non-resident
            fee = undergradNonResident * stdObj.getCreditsRequired()
               + ((stdObj.getYearstoGrad() * 
               (nonResidentYearFee + intInsuranceYearFee)));
         }
      }
      else 
      {
         // if graduate resident
         if (stdObj.getResidency() == "Resident")
         {
            fee = gradResident * stdObj.getCreditsRequired();
         }
         else
         {
            // if graduate non-resident
            fee = gradNonResident * stdObj.getCreditsRequired()
               + ((stdObj.getYearstoGrad() * 
               (nonResidentYearFee + intInsuranceYearFee)));
         }
      }
   }
   else // If display details is false
   {
      if (stdObj.getDegree() == "Undergraduate") 
      {
         // if undergraduate resident
         if (stdObj.getResidency() == "Resident") 
         {
            fee = undergradResident * stdObj.getCreditsRequired();

            std::cout << "Undergraduate Resident: " << 
               undergradResident << "*" << stdObj.getCreditsRequired()
               << " = " << 
               (undergradResident*stdObj.getCreditsRequired()) << '\n';
         } 
         else
         {
            // if undergraduate non-resident
            fee = undergradNonResident * stdObj.getCreditsRequired()
               + ((stdObj.getYearstoGrad() * 
               (nonResidentYearFee + intInsuranceYearFee)));

            std::cout << "Undergraduate Non-Resident Credit Fee: " <<
               undergradNonResident << "*" << stdObj.getCreditsRequired()
               << " = " << 
               (undergradNonResident * stdObj.getCreditsRequired())  
               << '\n';

            std::cout << "Undergraduate Non-Resident Year Fee: " <<
               nonResidentYearFee << "*" << stdObj.getYearstoGrad() <<
               " = " << (nonResidentYearFee * stdObj.getYearstoGrad())
               << '\n';

            std::cout << 
               "Undergraduate Non-Resident Year Insurance Fee: " << 
               intInsuranceYearFee << "*" << stdObj.getYearstoGrad() <<
               " = " << (intInsuranceYearFee * stdObj.getYearstoGrad())
               << '\n';
         }
      }
      else 
      {
         // if graduate resident
         if (stdObj.getResidency() == "Resident")
         {
            fee = gradResident * stdObj.getCreditsRequired();

            std::cout << "Graduate Resident: " << 
               gradResident << "*" << stdObj.getCreditsRequired()
               << " = " << 
               (gradResident*stdObj.getCreditsRequired()) << '\n';
         }
         else
         {
            // if graduate non-resident
            fee = gradNonResident * stdObj.getCreditsRequired()
               + ((stdObj.getYearstoGrad() * 
               (nonResidentYearFee + intInsuranceYearFee)));
            
            std::cout << "Graduate Non-Resident Credit Fee: " << 
            gradNonResident << "*" << stdObj.getCreditsRequired() << 
            " = " << (gradNonResident * stdObj.getCreditsRequired())
            << '\n';

            std::cout << "Graduate Non-Resident Year Fee: " << 
            nonResidentYearFee << "*" << stdObj.getYearstoGrad() <<
            " = " << (nonResidentYearFee * stdObj.getYearstoGrad())
            << '\n';

            std::cout << "Graduate Non-Resident Year Insurance Fee: " << 
            intInsuranceYearFee << "*" << stdObj.getYearstoGrad() << 
            " = " << (intInsuranceYearFee * stdObj.getYearstoGrad())
            << '\n';
         }
      }
   }
   return fee;
}

/*
* function_identifier: Prints all student data
* parameters: void
* return value: void
*/
void calculator::printAllStudentData() const 
{
   stdTypeObj.printStudentDetails();
}