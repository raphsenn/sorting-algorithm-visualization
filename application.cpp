#include <vector>
#include "./application.h"
#include "./algorithms.h"

Application::Application(int w, int h, int s) : 
    width(w),
    height(h),
    sizeArray(s),
    myArray(s) {
    myArray.createArray();
    
    // Initialize buttons
    buttons.push_back(Button("Run-Algorithm", font, sf::Color::Red, sf::Color::White, sf::Vector2f(1390, 925), sf::Vector2f(200, 35)));
    buttons.push_back(Button("Reset", font, sf::Color::Green, sf::Color::White, sf::Vector2f(1100, 925), sf::Vector2f(200, 35)));
    buttons.push_back(Button("NEXT", font, sf::Color::Black, sf::Color::White, sf::Vector2f(350, 925), sf::Vector2f(75, 35)));
    buttons.push_back(Button("BACK", font, sf::Color::Black, sf::Color::White, sf::Vector2f(100, 925), sf::Vector2f(75, 35)));

  }

int Application::calculateBar(int value, int maxValue, int maxLength){
  if (maxValue == 0){
    return 1; 
  }
  return static_cast<int>(static_cast<float>(value) / static_cast<float>(maxValue) * static_cast<float>(maxLength));
}

void Application::drawArray(sf::RenderWindow& window, MyArray& myArray){
  int heightBar = height - 100; 
  float widthBar = static_cast<float>((static_cast<float>(width) / static_cast<float>(sizeArray)));
  int* arrayData = myArray.getArray();
  for (int i = 0; i < sizeArray; i++){
    sf::RectangleShape bar;
    bar.setSize(sf::Vector2f(calculateBar(arrayData[i], sizeArray, heightBar), widthBar));
    bar.setFillColor(sf::Color::Black);
    bar.rotate(-90);
    bar.move(i * (widthBar), heightBar); 
    window.draw(bar);
  }
}

void Application::run(){
  window.create(sf::VideoMode(width, height), "sorting-algorithm-visualization"); 

  int algoNumb = 0;
  int numberOfAlgorithms = 6;
  std::vector<std::string> listOfAlgorithms = {"Mergesort", "Quicksort", "Minsort", "Maxsort", "Bubblesort", "Swapsort"}; 
  
  if (!font.loadFromFile("res/VarelaRound-Regular.ttf")) {
    printf("Failed to load font!");
  }
  sf::Text algo;
  algo.setFont(font);
  algo.setCharacterSize(24);
  algo.setFillColor(sf::Color::Black);
  algo.setString("Mergesort");
  algo.setPosition(sf::Vector2f(200, 925));

  while (window.isOpen()) {
    sf::Event event;
    sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
            window.close();
      }
      if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          for (const auto& button : buttons) {
            if (button.contains(mousePosition)) {
              if (button.getText() == "Run-Algorithm") {
                if (algoNumb == 0){
                  mergeSort(*this, window, sizeArray);
                }
                if (algoNumb == 1){
                  quickSort(*this, window, sizeArray);
                }
                if (algoNumb == 2){
                  minSort(*this, window, sizeArray);
                }
                if (algoNumb == 3){
                  maxSort(*this, window, sizeArray);
                }
                if (algoNumb == 4) {
                  bubbleSort(*this, window, sizeArray);
                }
                if (algoNumb == 5) {
                  swapSort(*this, window, sizeArray);
                }
              }
              if (button.getText() == "Reset") {
                myArray.createArray();
              }
              if (button.getText() == "NEXT") {
                algoNumb ++;
                algoNumb = algoNumb % numberOfAlgorithms; 
              }
              if (button.getText() == "BACK") {
                algoNumb --;
                algoNumb = algoNumb % numberOfAlgorithms; 
                if (algoNumb < 0) {
                  algoNumb = algoNumb + numberOfAlgorithms;
                } 

              }
            }
          }
        }
      }
    }
    window.clear(sf::Color::White);
    drawArray(window, myArray);
    for (const auto& button : buttons) {
      button.draw(window);
    }
    algo.setString(listOfAlgorithms[algoNumb]);
    window.draw(algo);
    window.display();
  }
}
sf::RenderWindow& Application::getWindow() {
  return window;
}
