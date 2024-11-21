/*
Name: KISHORE, NSHE: ABC123, CLASS-SECTION: CS202, ASSIGNMENT: 6
Purpose: Multiple classes, Composition, Templates, Operator Overloading
Description: Implementing Pokemon Mechanics:Templates and 
Operator Overloading
Input: GameImp.cpp is a Driver class in this assignment. Objects of 
different classes are declared in GameImp.cpp using constructors, and 
other functions. 
What to do?: This system manages pokemon's information like name, level, 
health,  and experience. Implement the function prototypes in Pokemon.h
and implement the functions in Trainer.h 
Output: You write the output on the terminal itself. You print all valid 
and invalid entries; 
print error messages for invalid entries accordingly. 
Check example output for more details.
*/
#ifndef GAME_H
#define GAME_H

#include "Trainer.h"

class Game {
public:
    static void start();
};

#endif // GAME_H