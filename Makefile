# Compiler and Flags
CXX = g++
CXXFLAGS = -I/yourpath/sorting-algorithm-visualization/sfml/include -std=c++11
LDFLAGS = -L/yourpath/sorting-algorithm-visualization/sfml/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -Wl,-rpath,./sfml/lib/

# Target file and object files
TARGET = main
OBJS = array.o buttons.o application.o algorithms.o main.o

# Standard rule for compiling a .cpp file to a .o file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Maintarget: Generates exe
$(TARGET): $(OBJS) 
	$(CXX) $(LDFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

# Rules for individual files
application.o: application.cpp
array.o: array.cpp
main.o: main.cpp
algorithms.o: algorithms.cpp
buttons.o: buttons.cpp


# Clean: Deletes all .o files and the exe
clean:
	rm -f $(OBJS) $(TARGET)
