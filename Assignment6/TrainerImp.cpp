/*
   Name: Carlos Aldaco Flores, 5008406281, 1006, 6
   Description: Implementation for Trainer.h
   Input: Void
   Output: Some success messages
*/

#include "Trainer.h"

// Implementation for Trainer constructor 
Trainer::Trainer(const std::string& name) : trainerName(name) 
{
   std::cout << "Trainer constructor invoked for " 
      << trainerName << '\n';
}

// Implementation for Trainer destructor 
Trainer::~Trainer()
{
   for (size_t i = 0; i < pokemons.size(); i++)
   {
      delete pokemons[i];
   }

   std::cout << "Trainer destructor invoked for " 
      << trainerName << std::endl;
}

// Implementation for addPokemon(Pokemon<int>* pokemon)
void Trainer::addPokemon(Pokemon<int>* pokemon)
{
   pokemons.push_back(pokemon);
}

// Implementation for displayPokemons()
void Trainer::displayPokemons() const
{
   std::cout << trainerName << "'s Pokemon:\n";
   for (size_t i = 0; i < pokemons.size(); i++)
   {
      pokemons[i]->display();
   }
}

// Implementation for 
// battle(Pokemon<int>& attacker, Pokemon<int>& defender)
void Trainer::battle(Pokemon<int>& attacker, Pokemon<int>& defender)
{
   defender.takeDamage(attacker.getAttackPower());
   // Display action
   std::cout << attacker.getName() << " attacks " << defender.getName()
      << " for " << attacker.getAttackPower() << " damage.\n";
   if (!defender)
   {
      // Adds experience for victory
      attacker.gainExperience(50);
      // Display victory message
      std::cout << attacker.getName() << " defeated " 
         << defender.getName() << "!\n";
   }
}