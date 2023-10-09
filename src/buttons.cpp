#include "buttons.h"

Button::Button(const std::string& buttonText, const sf::Font& font, const sf::Color& buttonColor, const sf::Color& textColor, const sf::Vector2f& position, const sf::Vector2f& size)
    : text(buttonText, font, 25), button(size) {
    text.setFillColor(textColor);
    text.setPosition(position);

    button.setFillColor(buttonColor);
    button.setPosition(position);
}

void Button::draw(sf::RenderWindow& window) const {
    window.draw(button);
    window.draw(text);
}

bool Button::contains(const sf::Vector2f& point) const {
    return button.getGlobalBounds().contains(point);
}

const std::string& Button::getText() const {
    sf::String sfmlString =  text.getString();
    return sfmlString.toAnsiString();
}
