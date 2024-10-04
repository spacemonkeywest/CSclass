/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 4
    Description: This is an implementation file for Vector.h
    Input: Void
    Output: Error or success message
*/

#include "Vector.h"

/*
* function_identifier: Constructor for Vector
* parameters: Void
* return value: Void
*/
Vector::Vector()
{
   beginPtr = nullptr;
   sizeValue = 0;
   capacityValue = 0;
}

/*
* function_identifier: Constructor for Vector
* parameters: Integer representing initial size
* return value: Void
*/
Vector::Vector(int size)
{
   beginPtr = new int[size];
   capacityValue = size;
   sizeValue = size;

   for (int i = 0; i < sizeValue; i++)
   {
      beginPtr[i] = 0;
   }
}

/*
* function_identifier: Constructor for Vector
* parameters: Integer representing initial size and
* and an integer representing the default value
* return value: Void
*/
Vector::Vector(int size, int defaultValue)
{
   beginPtr = new int[size];
   capacityValue = size;
   sizeValue = size;

   for (int i = 0; i < sizeValue; i++)
   {
      beginPtr[i] = defaultValue;
   }
}

/*
* function_identifier: Destructor for Vector
* parameters: Void
* return value: Void
*/
Vector::~Vector()
{
   delete[] beginPtr;
   std::cout << "\nDe-allocating memory..";
}

/*
* function_identifier: Resizes memory allocated to vector
* parameters: Void
* return value: Void
*/
void Vector::resize()
{
   if (capacityValue == 0)
   {
      capacityValue = 1;
   }
   else
   {
      capacityValue *= 2;
   }

   // Create new vector
   int* newData = new int[capacityValue];
   // Copy data from old vector
   for (int i = 0; i < sizeValue; i++)
   {
      newData[i] = beginPtr[i];
   }
   
   // Delete old vector
   delete[] beginPtr;
   // Make beginPtr point to new vector
   beginPtr = newData;

}

/*
* function_identifier: Shrinks memory allocated to fit size
* parameters: Void
* return value: Void
*/
void Vector::shrink_to_fit()
{
   int *newData = new int[sizeValue];
   for (int i = 0; i < sizeValue; i++)
   {
      newData[i] = beginPtr[i];
   }
   
   delete[] beginPtr;
   beginPtr = newData;
   capacityValue = sizeValue;
}

/*
* function_identifier: Pushes an integer to end of vector
* parameters: Integer to push
* return value: Void
*/
void Vector::push_back(int num)
{
   if (sizeValue == capacityValue)
   {
      resize();
   }

   beginPtr[sizeValue] = num;
   sizeValue++;
}

/*
* function_identifier: Removes a value from the end of vector
* parameters: Void
* return value: Void
*/
void Vector::pop_back()
{
   if (sizeValue > 0)
   {
      // Reducing the sizeValue makes the last value unaccessible 
      sizeValue--;
   } 
   else
   {
   std::cout << "Vector empty." << std::endl;
   }
}

/*
* function_identifier: Clears vector of elements
* parameters: Void
* return value: Void
*/
void Vector::clear()
{
   sizeValue = 0;
}

/*
* function_identifier: Gets size of vector
* parameters: Void
* return value: Size of vector
*/
int Vector::size()
{
   return sizeValue;
}

/*
* function_identifier: Gets capacity of vector
* parameters: Void
* return value: Capacity of vector
*/
int Vector::capacity()
{
   return capacityValue;
}

/*
* function_identifier: Checks if vector is empty
* parameters: Void
* return value: True if empty, false if not
*/
bool Vector::empty()
{
   return sizeValue == 0;
}

/*
* function_identifier: Prints each element in vector
* parameters: Void
* return value: Void
*/
void Vector::printElements()
{
   for (int i = 0; i < sizeValue; i++)
   {
      std::cout << beginPtr[i] << " "; 
   }
   std::cout << std::endl;
}
