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
#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

template<typename T>
class Pokemon {
private:
    std::string name;
    int level;
    T* health; // Using a pointer for health
    int experience; // Experience points for leveling up

public:
    // Parameterized Constructor
    Pokemon(const std::string& name, int level, T healthValue);
    
    // Copy Constructor
    Pokemon(const Pokemon& other);
    
    // Destructor
    ~Pokemon();

    // Getters and other member functions
    std::string getName() const;
    // Increases experience by xp
    void gainExperience(int xp);
    // Gets experience left to level up
    int requiredExperience() const;
    // Increases level
    void levelUp();
    // Changes name
    void evolve(const std::string& newName);
    // Displays details
    void display() const;
    // Reduces health
    void takeDamage(int damage);
    // Returns power of an attack
    int getAttackPower() const;

    //operators overloading- member functions
    // Defines + operator
    Pokemon operator+(const Pokemon& other);
    // Defines == operator
    bool operator==(const Pokemon& other) const;
    // Defines <= operator
    bool operator<=(const Pokemon& other) const;
    // Defines >= operator
    bool operator>=(const Pokemon& other) const;
    // Defines = operator
    Pokemon& operator=(const Pokemon& other);
    // Defines ! operator
    bool operator!() const;
    // Defines ++ operator
    Pokemon& operator++(); //Pre-increment
    // Defines ++ operator
    Pokemon operator++(int); // Post-increment
    
    // Friend functions for I/O- Non-member functions
    // Defines << friend operator
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, 
      const Pokemon<U>& p);
    // Defines >> friend operator
    template<typename U>
    friend std::istream& operator>>(std::istream& is, 
      Pokemon<U>& p);

    
};
// Do not make any changes above this line 
// Implement the template functions
// Your code here

// Implementation for Pokemon constructor
template <typename T>
Pokemon<T>::Pokemon(const std::string& name, int level, T healthValue)
{
   Pokemon::name = name;
   Pokemon::level = level;
   health = new T(healthValue);
   experience = 0;
   std::cout << "Pokemon parameterized constructor invoked for " 
      << name << '\n';
}

// Implementation for Pokemon copy constructor
template <typename T>
Pokemon<T>::Pokemon(const Pokemon<T>& other)
{
   name = other.name;
   level = other.level;
   // Deep copy
   health = new T(*other.health);
   experience = other.experience;
   std::cout << "Pokemon copy constructor invoked for " << name << '\n';
}

// Implementation for Pokemon destructor
template <typename T>
Pokemon<T>::~Pokemon()
{
   // Delete only dynamically allocated resource
   delete health;
   std::cout << "Pokemon destructor invoked for " << name << '\n';
}

// Implementation for getName()
template <typename T>
std::string Pokemon<T>::getName() const
{
   return name;
}

// Implementation for gainExperience(int xp)
template <typename T>
void Pokemon<T>::gainExperience(int xp)
{
   experience += xp;
   while (experience > requiredExperience())
   {
      levelUp();
   }
}

// Implementation for requiredExperience()
template <typename T>
int Pokemon<T>::requiredExperience() const
{
   return level * 100;
}

// Implementation for levelUp()
template <typename T>
void Pokemon<T>::levelUp()
{
   level++;
   *health += 10;
   std::cout << "Level Up!\n";
}

// Implementation for display()
template <typename T>
void Pokemon<T>::display() const
{
   std::cout << "Pokemon Name: " << name 
      << ", Level: " << level 
      << ", Health: " << *health 
      << ", Experience: " << experience << '\n';
}

// Implementation for takeDamage(int damage)
template <typename T>
void Pokemon<T>::takeDamage(int damage) 
{
   *health -= damage;
   if (*health < 0)
   {
      *health = 0;
   }
}

// Implementation for evolve(const std::string& newName)
template <typename T>
void Pokemon<T>::evolve(const std::string& newName) 
{
   name = newName;
   if (newName != "")
   {
      std::cout << name << " has evolved!\n";
   }
   else
   {
      std::cout << "Empty string: No Evolution\n";
   }
}

// Implementation for getAttackPower()
template <typename T>
int Pokemon<T>::getAttackPower() const
{
   return level * 5;
}

// Implementation for + operator
template <typename T>
Pokemon<T> Pokemon<T>::operator+(const Pokemon<T>& other) 
{
   std::string newName = name + '-' + other.name;
   // Get average
   int newLevel = (level + other.level) / 2;
   // Get average
   int newHealth = (*health + *other.health) / 2;
   Pokemon<T> p(newName, newLevel, newHealth);
   return p;
}

// Implementation for == operator
template <typename T>
bool Pokemon<T>::operator==(const Pokemon<T>& other) const
{
   if (level != other.level)
   {
      return false;
   }

   if (name != other.name)
   {
      return false;
   }

   if (*health != *other.health)
   {
      return false;
   }

   return true;
}

// Implementation for <= operator
template <typename T>
bool Pokemon<T>::operator<=(const Pokemon<T>& other) const
{
   return (level <= other.level);
}

// Implementation for >= operator
template <typename T>
bool Pokemon<T>::operator>=(const Pokemon<T>& other) const
{
   return (level >= other.level);
}

// Implementation for ! operator
template <typename T>
bool Pokemon<T>::operator!() const
{
   return (*health <= 0);
}

// Implementation for = operator
template <typename T>
Pokemon<T>& Pokemon<T>::operator=(const Pokemon<T>& other) 
{
   // Check for self-assignment
   if (this != &other) 
   { 
      name = other.name;
      level = other.level;
      delete health;
      // Deep copy
      health = new T(*other.health);
   }
   return *this;
}

// Implementation for pre-increment operator
template <typename T>
Pokemon<T>& Pokemon<T>::operator++() 
{
   level++;
   return *this;
}

// Implementation for post-increment operator
template <typename T>
Pokemon<T> Pokemon<T>::operator++(int) 
{
   // Store current instance in temporary variable
   Pokemon<T> temp = *this;
   level++;
   return temp;
}

// Implementation for insertion operator
template<typename U>
std::ostream& operator<<(std::ostream& os, const Pokemon<U>& p)
{
   p.display();
   return os;
}

// Implementation for extraction operator
template<typename U>
std::istream& operator>>(std::istream& is, Pokemon<U>& p)
{
   std::string tempName;
   int healthValue;
   // Input name, level, and health
   is >> tempName >> p.level >> healthValue;
   // Loop until both valid
   while (p.level < 0 || healthValue < 0)
   {
      if (p.level < 0)
      {
         std::cout << "Invalid Level\n";
      }
      
      if (healthValue < 0)
      {
         std::cout << "Invalid Health Value\n";
      }

      is.clear();
      is >> tempName >> p.level >> healthValue;
   }

   p.name = tempName;
   delete p.health;
   // Will be casted
   p.health =  new U(healthValue);
   return is;
}

#endif // POKEMON_H