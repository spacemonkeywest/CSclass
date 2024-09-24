#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class Vector {
private:
  int *beginPtr;
  int sizeValue;
  int capacityValue;

public:
  Vector();
  Vector(int capacityValue);
  Vector(int capacityValue, int initialValue);
  void resize();
  void push_back(int);
  void pop_back();
  void clear();
  int size();
  int capacity();
  bool empty();
  void printElements();
  void shrink_to_fit();
  ~Vector();
};

#endif