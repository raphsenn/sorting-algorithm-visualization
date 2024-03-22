#ifndef APPLICATION_H
#define APPLICATION_H

// Imports from standard libary.
#include <algorithm>
#include <random>

// Import SFML libary.
#include <SFML/Graphics.hpp>

class Application{
	private:
		// Window settings.
		int width;
		int height;
		sf::RenderWindow window;

		// Array settings.
		int arraySize;
		int* arrayPtr;

	public:
		Application();
		void simulate();
		void update();
		void shuff();
		void draw();
		void run();
};
#endif // APPLICATION_H
