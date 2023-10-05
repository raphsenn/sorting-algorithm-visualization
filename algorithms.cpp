#include "./algorithms.h"
#include "./application.h"


void minSort(Application& app, sf::RenderWindow& window, int size) {
  int* arrayData = app.myArray.getArray();  
  int swapIndex = 0; 
  int temp = 0;
  for (int i = 0; i < size; i++) {
    int currentMin = arrayData[i];
    for (int j = i; j < size; j++) {
      if (arrayData[j] <= currentMin){
        currentMin = arrayData[j];
        swapIndex = j; 
      }
    }
    temp = arrayData[i];
    arrayData[i] = currentMin;
    arrayData[swapIndex] = temp;
    
    // visualize sorting step
    window.clear(sf::Color::White);
    app.drawArray(window, app.myArray); 
    window.display();    
    sf::sleep(sf::milliseconds(10));
  }
}


void maxSort(Application& app, sf::RenderWindow& window, int size) {
  int* arrayData = app.myArray.getArray();  
  int swapIndex = 0; 
  int temp = 0;
  int maxIndex = size - 1;

  for (int i = 0; i < size; i++) {
    int currentMax = arrayData[maxIndex];
    for (int j = 0; j <= maxIndex; j++) {
      if (arrayData[j] >= currentMax){
        currentMax = arrayData[j];
        swapIndex = j; 
      }
    }
    temp = arrayData[maxIndex];
    arrayData[maxIndex] = currentMax;
    arrayData[swapIndex] = temp;
    maxIndex -= 1; 
    
    // visualize sorting step
    window.clear(sf::Color::White);
    app.drawArray(window, app.myArray); 
    window.display();    
    sf::sleep(sf::milliseconds(10));
  }
}


void quickSortRecursive(Application& app, sf::RenderWindow& window, int* arrayData, int low, int high) {
  if (low < high) {
    int pivotIndex = partition(arrayData, low, high, app, window);

    quickSortRecursive(app, window, arrayData, low, pivotIndex - 1);
    quickSortRecursive(app, window, arrayData, pivotIndex + 1, high);
  }
}


int partition(int* arrayData, int low, int high, Application& app, sf::RenderWindow& window) {
  int pivot = arrayData[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (arrayData[j] < pivot) {
      i++;
      std::swap(arrayData[i], arrayData[j]);
    }
    // Visualize sorting step
    window.clear(sf::Color::White);
    app.drawArray(window, app.myArray);
    window.display();
    sf::sleep(sf::microseconds(1));
  }
  std::swap(arrayData[i + 1], arrayData[high]);
  return i + 1;
}


void quickSort(Application& app, sf::RenderWindow& window, int size){
  int* arrayData = app.myArray.getArray();  
  quickSortRecursive(app, window, arrayData ,0, size- 1);
}


void mergeSortRecursive(Application& app, sf::RenderWindow& window ,int* arrayData, int* aux, int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    mergeSortRecursive(app, window, arrayData, aux, low, mid);
    mergeSortRecursive(app, window,arrayData, aux, mid + 1, high);
    // Merge sorted subarrays
    for (int i = low; i <= high; i++) {
      aux[i] = arrayData[i];
    }
    int i = low, j = mid + 1;
    for (int k = low; k <= high; k++) {
      if (i > mid) {
        arrayData[k] = aux[j++];
      } else if (j > high) {
        arrayData[k] = aux[i++];
      } else if (aux[i] <= aux[j]) {
        arrayData[k] = aux[i++];
      } else {
        arrayData[k] = aux[j++];
      }
      // visualize sorting step
      window.clear(sf::Color::White);
      app.drawArray(window, app.myArray);
      window.display();
      sf::sleep(sf::microseconds(1));
    }
  }
}


void mergeSort(Application& app, sf::RenderWindow& window, int size) {
  int* arrayData = app.myArray.getArray();
  int* aux = new int[size];
  mergeSortRecursive(app, window ,arrayData, aux, 0, size - 1);
  delete[] aux;
}


void bubbleSort(Application& app, sf::RenderWindow& window, int size) {
  int* arrayData = app.myArray.getArray();
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arrayData[j] > arrayData[j+1]){
        int temp = arrayData[j];
        arrayData[j] = arrayData[j+1];
        arrayData[j+1] = temp;
      }
    }
    // visualize sorting step
    window.clear(sf::Color::White);
    app.drawArray(window, app.myArray);
    window.display();
    sf::sleep(sf::milliseconds(10));
  }
}


void swapSort(Application& app, sf::RenderWindow& window, int size) {
  int* arrayData = app.myArray.getArray();
  int i = 0;
  while (i < size-1) {
    int M = arrayData[i];
    int lessThanM = 0;
    for (int j = i + 1; j < size; j++) {
      if (arrayData[j] < M) {
        lessThanM++;
      }
    }
    int temp = arrayData[i];
    arrayData[i] = arrayData[lessThanM+i];
    arrayData[lessThanM+i] = temp;
    
    if (i == lessThanM + i) {
      i++;
    }
    // visualize sorting step
    window.clear(sf::Color::White);
    app.drawArray(window, app.myArray);
    window.display();
    sf::sleep(sf::milliseconds(1));

  }
}











