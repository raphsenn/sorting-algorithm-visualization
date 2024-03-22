
compile:
	
	g++ -c application.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include
	g++ -c main.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include
	g++ -c algorithms.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include
	g++ main.o application.o algorithms.o -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f *.o
	rm -f main


