#include "./application.h"


Application::Application() : width(1024), height(768), window(sf::VideoMode(width, height), "SFML!"), arraySize(1000) {
	// Allocate memory for the array.
	// Fill the array with numbers from 1 to 1001.
	// Shuffle the array.
	arrayPtr = new int[arraySize];
	for (int i = 0; i < arraySize; i++) { arrayPtr[i] = i + 1; }
	shuff();

	// Create sfml window.
	sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");

}

void Application::draw()
{
	// Draw each number as a bar.
	float barX = static_cast<float>((static_cast<float>(width) / static_cast<float>(arraySize)));	
	for (int i = 0; i < arraySize; i++)
	{
		float barY = static_cast<float>(static_cast<float>(arrayPtr[i]) / static_cast<float>(arraySize + 1) * static_cast<float>(height));
		sf::RectangleShape bar;
		bar.setSize(sf::Vector2f(barY, barX));
		bar.setFillColor(sf::Color::White);
		bar.rotate(-90);
		bar.move(i * barX, height);
		window.draw(bar);	
	}
}

void Application::update()
{
	// Clear window.
	// Draw array, buttons and text on screen.
	// Display.
	window.clear(sf::Color(173, 216, 230)); // Background color: LightBlue RGB=(173, 216, 230).
	draw();
	window.display();
	input();
}

void Application::input()
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
	{
		// Enter key is pressed
		printf("pressed enter\n");
		minSort(window, arrayPtr, arraySize);
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) 
	{
		printf("pressed delete\n");
		shuff();
	}

}

void Application::shuff()
{
	// Shuffle the array.
	std::random_device rd;
	std::mt19937 g(rd());
	shuffle(arrayPtr, arrayPtr + arraySize, g);
}

void Application::run() {
	while (window.isOpen())
	{
		// sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
			update();
	}
}
