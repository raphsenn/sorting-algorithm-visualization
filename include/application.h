#ifndef APPLICATION_H
#define APPLICATION_H

// Imports from standard libary.
#include <algorithm>
#include <random>
#include <cstdio>
#include <map>
#include <string>
#include <tuple>

// Import SFML libary.
#include <SFML/Graphics.hpp>

class Application{
  private:
    // Window settings.
    int width;
    int height;
    sf::RenderWindow window;
    sf::Event event;
    sf::Font font;

    // Array settings.
    int arraySize;
    int* arrayPtr;

    // Define a type for pointers to methods.
    typedef void (Application::*AlgorithmFunction)();
    // Map algorithm number to algorithm method.
    std::map<int, std::tuple<std::string, AlgorithmFunction>> algorithmsMap;
    // std::map<int, AlgorithmFunction> algorithmsMap;
    int currentAlgorithm;    

    // Methods. 
    void simulate();
    void update();
    void input();
    void executeCurrentAlgorithm();
    void selectNextAlgorithm();
    void selectPreviousAlgorithm(); 
    void shuff();
    void draw();
 
  public:
    // Methods. 
    Application();
    void run();
    
    // The Algorithms.
    void minSort();
    void bubbleSort();
    void merge(int low, int mid, int high);
    void mergeSort(int low, int high);
    void mergeSortCall();

};
#endif // APPLICATION_H
