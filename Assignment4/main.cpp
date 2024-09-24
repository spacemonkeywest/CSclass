#include "Vector.h"

int main() {

  // Test Case 1
  // Default Vector Initialization
  Vector v1;
  cout << "v1.size(): " << v1.size() << endl;
  cout << "v1.capacity(): " << v1.capacity() << endl;
  cout << "v1.empty(): " << v1.empty() << endl;
  cout << endl;

  // Test Case 2
  // Vector(size) Initialization
  Vector v2(2);
  // cout << "Vector Initialization with Size Test Case: " << endl;
  // v2.printElements();
  cout << "v2.size(): " << v2.size() << endl;
  cout << "v2.capacity(): " << v2.capacity() << endl;
  cout << "v2.empty(): " << v2.empty() << endl;
  cout << "Vector elements are: ";
  v2.printElements();
  cout << endl;

  // Test Case 3
  // Vector(size, defaultValue) Initialization
  Vector v3(5, 1);
  cout << "v3.size(): " << v3.size() << endl;
  cout << "v3.capacity(): " << v3.capacity() << endl;
  cout << "v3.empty(): " << v3.empty() << endl;
  cout << "Vector elements are: ";
  v3.printElements();
  cout << endl;

  // // // Test Case 4
  Vector v4;
  cout << "v4.size(): " << v4.size() << endl;
  cout << "v4.capacity(): " << v4.capacity() << endl;
  cout << endl;

  cout << "Resizing the vector.." << endl;
  v4.resize();
  cout << "v4.size(): " << v4.size() << endl;
  cout << "v4.capacity(): " << v4.capacity() << endl;
  cout << endl;

  cout << "Resizing the vector.." << endl;
  v4.resize();
  cout << "v4.size(): " << v4.size() << endl;
  cout << "v4.capacity(): " << v4.capacity() << endl;
  cout << endl;

  cout << "Resizing the vector.." << endl;
  v4.resize();
  cout << "v4.size(): " << v4.size() << endl;
  cout << "v4.capacity(): " << v4.capacity() << endl;
  cout << endl;

  // // Test Case 5
  Vector v5;
  // cout << "Vector Initialization with Size Test Case: " << endl;
  cout << "v5.size(): " << v5.size() << endl;
  cout << "v5.capacity(): " << v5.capacity() << endl;
  cout << endl;

  cout << "pushing back 0.." << endl;
  v5.push_back(0);
  cout << "v5.size(): " << v5.size() << endl;
  cout << "v5.capacity(): " << v5.capacity() << endl;
  cout << endl;

  cout << "pushing back 1.." << endl;
  v5.push_back(1);
  cout << "v5.size(): " << v5.size() << endl;
  cout << "v5.capacity(): " << v5.capacity() << endl;
  cout << endl;

  cout << "pushing back 2.." << endl;
  v5.push_back(2);
  cout << "v5.size(): " << v5.size() << endl;
  cout << "v5.capacity(): " << v5.capacity() << endl;
  cout << endl;

  // // Test Case 6
  Vector v6(5, 1);
  // cout << "Vector Initialization with Size Test Case: " << endl;
  cout << "v6.size(): " << v6.size() << endl;
  cout << "v6.capacity(): " << v6.capacity() << endl;
  v6.printElements();
  cout << endl;

  cout << "popping back four elements" << endl;
  v6.pop_back();
  v6.pop_back();
  v6.pop_back();
  v6.pop_back();
  cout << "v6.size(): " << v6.size() << endl;
  cout << "v6.capacity(): " << v6.capacity() << endl;
  cout << endl;

  cout << "pushing back 1.." << endl;
  v6.push_back(1);

  cout << "pushing back 2.." << endl;
  v6.push_back(2);

  cout << "pushing back 3.." << endl;
  v6.push_back(3);

  cout << "pushing back 4.." << endl;
  v6.push_back(4);

  cout << "pushing back 5.." << endl;
  v6.push_back(5);

  cout << "v6.size(): " << v6.size() << endl;
  cout << "v6.capacity(): " << v6.capacity() << endl;
  cout << endl;

  cout << "clearing the vector.." << endl;
  v6.clear();

  cout << "v6.empty(): " << v6.empty() << endl;
  cout << "v6.size(): " << v6.size() << endl;
  cout << "v6.capacity(): " << v6.capacity() << endl;

  v6.shrink_to_fit();
  cout << "v6.size(): " << v6.size() << endl;
  cout << "v6.capacity(): " << v6.capacity() << endl;

  v6.push_back(1);
  cout << "v6.size(): " << v6.size() << endl;
  cout << "v6.capacity(): " << v6.capacity() << endl;
}