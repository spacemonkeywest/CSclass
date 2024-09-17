#include "calculator.h"

calculator::calculator()
{
   studentType student;
}

calculator::calculator(studentType &stdObj)
{
   studentType student;
   student.setStudentDetails(stdObj.getFirstName(), stdObj.getLastName(),
      stdObj.getBirthYear(), stdObj.getYearEnrolled(), 
      stdObj.getStudentID(), stdObj.getDepartment(), stdObj.getDegree(), 
      stdObj.getResidency(), stdObj.getCreditsRequired(), 
      stdObj.getYearstoGrad());
}

double calculator::calculateTuition(const studentType &stdObj, 
    bool printDetails)
{
   double fee = 0.0;
   if (!printDetails)
   {
      if (stdObj.getDegree() == "Undergraduate") 
      {
         if (stdObj.getResidency() == "Resident") 
         {
            fee = undergradResident * stdObj.getCreditsRequired();
         } 
         else
         {
            fee = undergradNonResident * stdObj.getCreditsRequired()
               + ((stdObj.getYearstoGrad() * 
               (nonResidentYearFee + intInsuranceYearFee)));
         }
      }
      else 
      {
         if (stdObj.getResidency() == "Resident")
         {
            fee = gradResident;
         }
         else
         {
            fee = gradNonResident * stdObj.getCreditsRequired()
               + ((stdObj.getYearstoGrad() * 
               (nonResidentYearFee + intInsuranceYearFee)));
         }
      }
   }

   if (stdObj.getDegree() == "Undergraduate") 
      {
         if (stdObj.getResidency() == "Resident") 
         {
            fee = undergradResident * stdObj.getCreditsRequired();

            std::cout << "Undergraduate Resident Credit Fee: " << 
               undergradResident << "*" << stdObj.getCreditsRequired()
               << " = " << 
               (undergradResident*stdObj.getCreditsRequired()) << '\n';
         } 
         else
         {
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

            std::cout << "Undergraduate Non-Resident Year Insurance Fee: " <<
               intInsuranceYearFee << "*" << stdObj.getYearstoGrad() <<
               " = " << (intInsuranceYearFee * stdObj.getYearstoGrad())
               << '\n';
         }
      }
      else 
      {
         if (stdObj.getResidency() == "Resident")
         {
            fee = gradResident;

            std::cout << "Graduate Resident Credit Fee: " << 
               undergradResident << "*" << stdObj.getCreditsRequired()
               << " = " << 
               (undergradResident*stdObj.getCreditsRequired()) << '\n';
         }
         else
         {
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

   return fee;
}

void calculator::printAllStudentData() const 
{
   stdTypeObj.printStudentDetails();
}