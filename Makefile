# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
SFML_INCLUDE = -I/opt/homebrew/Cellar/sfml/2.6.1/include
SFML_LIB = -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

# Directories
SRCDIR = src
INCDIR = include

# Source files
SOURCES := $(wildcard $(SRCDIR)/*.cpp)

# Object files
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=%.o)

# Executable
EXECUTABLE = main

# Compile targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $^ -o $@ $(SFML_LIB)

%.o: $(SRCDIR)/%.cpp $(wildcard $(INCDIR)/*.h)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -I$(INCDIR) -c $< -o $@

# Cleaning
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

