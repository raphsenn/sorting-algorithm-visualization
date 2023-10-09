#ifndef MYARRAY_H
#define MYARRAY_H

#include <random>


class MyArray {


private:
  int sizeMyArray; // Size of the Array
  int* myarray; // Pointer to the dynamically allocated array
  std::mt19937 rng; // random number generator


public:
  MyArray(int size); // Constructor to initialize the object
  ~MyArray(); // Destructor to free allocated memory

  void createArray(); // Method to create and shuffle the array
  int* getArray(); // Method to get a pointer to the array
  void printArray(); // Method to print the array (prints the array like a list in python <3)
};

#endif // MYARRAY_H
