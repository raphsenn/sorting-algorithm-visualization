#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "./array.h"
#include "./buttons.h"

class Application {

private:
  int width; // Width of the application window
  int height; // Height of the application window
  int sizeArray; // Size of the array for visualization
  sf::Font font; // Font for text rendering
  sf::RenderWindow window; // SFML window object
  std::vector<Button> buttons; // Vector of UI buttons

public:
  MyArray myArray; // Instance of the MyArray class for data storage
  sf::RenderWindow& getWindow(); // Method to get a referece to the window
  Application(int w = 1600, int h = 1000, int s = 1000); // Constructor
  int calculateBar(int value, int maxValue, int maxLength); // Calculate bar length
  void drawArray(sf::RenderWindow& window, MyArray& myArray); // Draw array bars
  void run(); // Main application loop
};

#endif // APPLICATION_H
