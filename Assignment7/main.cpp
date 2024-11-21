#include "Character.h"
#include <iostream>

int main() {
  // Creating a character Dom
  // Reading the commands from strings.txt file
  Character Dom("commands.txt");
  cout << endl << endl;
  
  Dom.printCommands();
  cout << endl << endl;
  
  cout << "Calling startDreaming() function from main.." << endl;
  Dom.startDreaming();
  cout << endl;
  
}