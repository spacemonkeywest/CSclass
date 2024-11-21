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
#ifndef TRAINER_H
#define TRAINER_H

#include <iostream>
#include <vector>
#include "Pokemon.h"

class Trainer {
private:
    std::string trainerName;
    std::vector<Pokemon<int>*> pokemons; // Dynamic allocation of Pokemon

public:
    // Constructor
    Trainer(const std::string& name);
    
    // Destructor
    ~Trainer();

    // Add Pokemon to trainer's collection
    void addPokemon(Pokemon<int>* pokemon);
    
    // Display trainer's Pokemon
    void displayPokemons() const;
    
    // Function to initiate a battle
    void battle(Pokemon<int>& attacker, Pokemon<int>& defender);
};

#endif // TRAINER_H