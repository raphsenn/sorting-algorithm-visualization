#ifndef APPLICATION_H
#define APPLICATION_H

// Imports from standard libary.
#include <algorithm>
#include <random>
#include <cstdio>

// Import SFML libary.
#include <SFML/Graphics.hpp>

class Application{
  private:
    // Window settings.
    int width;
    int height;
    // sf::RenderWindow window;
    sf::Event event;

    // Array settings.
    int arraySize;
    int* arrayPtr;

  public:
    Application();
    sf::RenderWindow window;
    void simulate();
    void update();
    void input();
    void shuff();
    void draw();
    void run();
    
    // The Algorithms.
    void minSort();
    void bubbleSort();

};
#endif // APPLICATION_H
