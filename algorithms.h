#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "application.h"
#include <SFML/Graphics.hpp>

class Application;

// easy implementation of Minsort algorithm (iterativ)
// https://de.wikipedia.org/wiki/Selectionsort
void minSort(Application& app, sf::RenderWindow& window ,int size);

// easy implementation of Maxsort algorithm (iterativ)
// https://de.wikipedia.org/wiki/Selectionsort
void maxSort(Application& app, sf::RenderWindow& window ,int size);

void quickSortRecursive(Application& app, sf::RenderWindow& window, int* arrayData, int low, int high); 

int partition(int* arrayData, int low, int high, Application& app, sf::RenderWindow& window);

// easy implementation of Quicksort algorithm (recursive)
// https://en.wikipedia.org/wiki/Quicksort
void quickSort(Application& app, sf::RenderWindow& window, int size); 

void mergeSortRecursive(Application& app,sf::RenderWindow& window ,int* arrayData, int* aux, int low, int high);

// easy implementation of Mergesort algorithm (recursive)
// https://en.wikipedia.org/wiki/Merge_sort
void mergeSort(Application& app, sf::RenderWindow& window, int size); 


// easy implementation of Bubblesort algorithm (iterativ)
// https://en.wikipedia.org/wiki/Bubble_sort
void bubbleSort(Application& app, sf::RenderWindow& window, int size);


// easy implementation of Swapsort algorithm (iterativ)
// https://de.wikipedia.org/wiki/Swap-Sort (in german)
void swapSort(Application& app, sf::RenderWindow& window, int size);

#endif // ALGORITHMS_H
