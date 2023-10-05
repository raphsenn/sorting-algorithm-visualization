#include "./array.h"
#include <cstdio>


MyArray::MyArray(int size) {
  sizeMyArray = size;
  myarray = new int[sizeMyArray]; 
  rng.seed(std::time(0)); 
}

MyArray::~MyArray() {
  delete[] myarray;
}

void MyArray::createArray() {
  for (int i = 0; i < sizeMyArray; i++) {
    myarray[i] = i + 1;
  }
  std::shuffle(myarray, myarray + sizeMyArray, rng);

}

int* MyArray::getArray() {
  return myarray;
}


void MyArray::printArray() {
  for (int i = 0; i < sizeMyArray; i++) {
    if (i == 0) {printf("[");}
    if (i < sizeMyArray - 1) {printf("%d, ", myarray[i]);}
    if (i == sizeMyArray - 1) {printf("%d]", myarray[i]);} 
  }
  printf("\n");
}
