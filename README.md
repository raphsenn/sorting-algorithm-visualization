# sorting-algorithm-visualization
## About the Project 📋

This project is a sorting visualization application implemented in C++ using the SFML library. It provides a visual representation of various sorting algorithms such as Bubble Sort, Merge Sort, Quick Sort, and more. Users can interact with the application to see how these algorithms work on randomized input data.

<div align="center">
  <img src="./res/mergesort.gif" alt="gif">
</div>

### Implemented Algorithms 🧮
- Mergesort
- Quicksort
- Bubblesort
- Minsort
- Swapsort

### Prerequisites

Before you begin, make sure you have the following tools and libraries installed:

- C++ compiler (e.g., g++)
- SFML library <3
- Google Test (for running tests)

### Installation with make

#### Edit the Makefile
Before building the project, you'll need to edit the Makefile to specify the correct paths for the SFML library and include directories based on your system. Open the Makefile in a text editor and update the following lines:

 ```js
	CXX = g++
	CXXFLAGS = -std=c++17 -Wall -Wextra -O2
	LDFLAGS = -I/your-path-to/sfml/2.6.1/include
	LIBS = -L/your-path-to/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
 ```
Replace "yourpath" with your own path.

1. Clone the repository:
	```shell
	git clone https://github.com/raphsenn/sorting-algorithm-visualization.git
2. Navigate to the project directory:
 	```shell
	 cd sorting-algorithm-visualization
3. Compile the project using the provided Makefile:
	```shell
	make all

### Installation without make

1. Clone the repository:
	```shell
	git clone https://github.com/raphsenn/sorting-algorithm-visualization.git
2. Navigate to the project directory:
 	```shell
	 cd sorting-algorithm-visualization
3. Compile the project (without Makefile):

```shell
    g++ -std=c++17 -Wall -Wextra -O2 -I/your-path-to/sfml/2.6.1/include -Iinclude -c src/application.cpp -o application.o
    g++ -std=c++17 -Wall -Wextra -O2 -I/your-path-to/sfml/2.6.1/include -Iinclude -c src/main.cpp -o main.o
```

4. Linking
	```shell
    g++ main.o application.o -o main -L/your-path-to/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

### Usage
1. Run program
	```shell
	./main
2. Use the graphical interface to select a sorting algorithm and control the visualization.
3. Enjoy exploring the visualization of sorting algorithms!

## License
This project is licensed under the MIT License - see the LICENSE file for details.

