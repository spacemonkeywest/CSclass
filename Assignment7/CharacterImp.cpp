/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 7
    Description: Implementation for Character.h
    Input: File containing commands
    Output: Console output
*/

#include "Character.h"
#include <iostream>

// Constructor for Character
Character::Character(string fileName) : currentIndex(-1)
{
   iFile.open(fileName);
   readFromFile();
   cout << "The following are the commands received: " << endl;
}

// Reads file contents using recursion
void Character::readFromFile()
{
    string line;
    if (getline(iFile, line)) {
        // Recursively call the function to read the next line
        readFromFile();
        // Push the current line to the vector after recursive call
        commands.push_back(line);
    }
    // Base case: eof
}

// Calculate nth fibonacci number
int Character::fibonacci(int n)
{
   // Base cases
   if (n == 0) return 0;
   if (n == 1) return 1;

   // Recursive case
   return fibonacci(n - 1) + fibonacci(n - 2);
}

// Print all commands read from file
void Character::printCommands()
{
   for (size_t i = 0; i < commands.size(); i++)
   {
      cout << commands[i] << endl;
   }
}

// Reverses given command and stores it in reverseCommand 
string Character::reverseString(string command, string 
   reverseCommand, int index)
{
   // Base case
   if (index == 0)
   {
      reverseCommand += command[0];
      return reverseCommand;
   }

   // Recursive case
   reverseCommand += command[index];
   return reverseString(command, reverseCommand, index - 1);
}

// Starts dreaming
void Character::startDreaming()
{
    // Increment currentIndex to move to the next command
    currentIndex++;
    
    // Base case
    if (currentIndex >= static_cast<int>(commands.size())) {
        currentIndex--; // Decrement to backtrack
        return;
    }

    // Calculate current dream level
    int dreamLevel = currentIndex + 1;

    // Allocate a new Dream object
    int dreamSize = fibonacci(dreamLevel);
    Dream* dream = new Dream(dreamSize, dreamLevel);

    // Reverse the current command
    std::string currentCommand = commands[currentIndex];
    std::string reverseCommand = reverseString(currentCommand, "", 
      currentCommand.length() - 1);

    // Palindrome check
    if (currentCommand == reverseCommand) {
        delete dream; // Free the allocated memory
        currentIndex--; // Decrement to backtrack
        return;
    }

    // Recursive call
    startDreaming();

    // Clean up and print the end of the current dream level
    delete dream; // Free the dynamically allocated memory
    currentIndex--; // Decrement to backtrack
}

// Destructor for Character
Character::~Character()
{
   if (iFile.is_open())
   {
      iFile.close();
   }
}