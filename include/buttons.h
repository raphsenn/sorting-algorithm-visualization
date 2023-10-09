#pragma once // Include guard to prevent multiple inclusion of the header file

#include <SFML/Graphics.hpp>

class Button {
public:
  // Constructor to initialize the button   
  Button(const std::string& buttonText, const sf::Font& font, const sf::Color& buttonColor, const sf::Color& textColor, const sf::Vector2f& position, const sf::Vector2f& size);
  
  void draw(sf::RenderWindow& window) const; // Method to draw the button on a given SFML window
  bool contains(const sf::Vector2f& point) const; // Method to check if a point (usually mouse cursor) is inside the button's bounds
  const std::string& getText() const;

private:
  sf::Text text; // SFML text object for button label
  sf::RectangleShape button; // SFML rectangle shape representing the button
};

