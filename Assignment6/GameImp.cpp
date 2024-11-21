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
#include "Game.h"

void Game::start() {
    Trainer ash("Ash");
    Trainer misty("Misty");

    Pokemon<int>* pikachu = new Pokemon<int>("Pikachu", 90, 200);
    Pokemon<int>* charizard = new Pokemon<int>("Charizard", 70, 160);
    Pokemon<int>* staryu = new Pokemon<int>("Staryu", 21, 50);
    Pokemon<int>* psyduck = new Pokemon<int>("Psyduck", 19, 60);

    ash.addPokemon(pikachu);
    ash.addPokemon(charizard);
    misty.addPokemon(staryu);
    misty.addPokemon(psyduck);

    //Display after adding pokemons but before battle
    ash.displayPokemons();
    misty.displayPokemons();

    std::cout << "\n\"It's a battle between Pikachu and Staryu\""<<std::endl;
    // Start a battle
    ash.battle(*pikachu, *staryu); // Pikachu attacks Staryu

    std::cout << "\n\"Display the results after battle\"" << std::endl;
    //Display after battle
    ash.displayPokemons(); //Show ash after battle
    misty.displayPokemons(); // Show misty after battle


    std::cout << std::endl;

    // Test cases for operators Test + ;
    Pokemon<int> combined = *pikachu + *charizard; 
                                    // Combined is like fusion
    std::cout << "Combined Pokemon: \n" << combined << std::endl << "\n";

    std::cout << "\n\"Test == operator\"\n" << std::endl;
    // Test == operator
    if (*pikachu == *charizard) {
        std::cout << "Pikachu is the same as Charizard.\n";
    } else {
        std::cout << "Pikachu is different from Charizard.\n";
    }

    Pokemon<int>ashPikachu("Pikachu", 85, 180);
    Pokemon<int>redPikachu("Pikachu", 80, 160);
    if (ashPikachu == redPikachu) {
        std::cout << "Ash's Pikachu is the same as Red's.\n";
    } else {
        std::cout << "Ash's Pikachu is different from Red's.\n";
    }

    // Test <= and >= operators
    std::cout << "\n\"Test <= and >= operators\"\n" << std::endl;
    if (*pikachu >= *charizard) {
        std::cout << "Pikachu's level is greater than or equal to " <<
        "Charizard's level.\n";
    }
    if (*charizard <= *pikachu) {
        std::cout << "Charizard's level is less than or equal to " << 
        "Pikachu's level.\n";
    }

    std::cout << std::endl; 

    // Evolve the Pokemon
    staryu->evolve("Starmie");

    // Check if the name has changed
    std::string expectedName = "Starmie";
    std::string actualName = staryu->getName();

    // Output the results
    std::cout << "After evolution: " << actualName << std::endl;

    // Assert the condition
    if (actualName == expectedName) {
        std::cout << "Test passed: Evolution successful!" << std::endl;
    } else {
        std::cout << "Test failed: Evolution not successful!"<< std::endl;
    }

     // Evolve the Pokemon2
    psyduck->evolve("");

    // Check if the name has changed
    expectedName = "Golduck";
    actualName = psyduck->getName();

    // Output the results
    std::cout << "After evolution: " << actualName << std::endl;

    // Assert the condition
    if (actualName == expectedName) {
        std::cout << "Test passed: Evolution successful!" << std::endl;
    } else {
        std::cout << "Test failed: Evolution not successful!"<< std::endl;
    }


    // Test copy constructor
    Pokemon<int> pikachuCopy = *pikachu; // Copy constructor
    std::cout << "Copy of Pikachu: \n" << pikachuCopy <<std::endl << "\n";

    // Test increment operators
    ++(*pikachu); // Pre-increment
    std::cout<< "Pikachu after pre-increment: \n" << *pikachu <<std::endl;
    (*charizard)++; // Post-increment
    std::cout << "\nCharizard after post-increment: \n" << *charizard 
    << std::endl;
    
    std::cout << std::endl;

    // Test extraction operator >>
    Pokemon<int> newPokemon("", 0, 0);
    std::cout << "Enter new Pokemon details (name level health): \n";
    std::cin >> newPokemon; // Using extraction operator
    // Using insertion operator
    std::cout << "\nNew Pokemon created: " << newPokemon << std::endl; 
    std::cout << std::endl;
}
