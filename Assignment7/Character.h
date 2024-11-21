#ifndef CHARACTER_H
#define CHARACTER_H

#include "Dream.h"
#include <fstream>
#include <vector>
using namespace std;

class Character {
private:
  int currentIndex;
  ifstream iFile;
  vector<string> commands;

public:
  Character(string filename);
  void readFromFile();
  string reverseString(string command, string reverseCommand, int index);
  void printCommands();
  void startDreaming();
  int fibonacci(int n);
  ~Character();
};

#endif