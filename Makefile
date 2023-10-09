# Compiler and Flags
CXX = g++
CXXFLAGS = -I/yourpath/Desktop/sorting-visualization/sfml/include -I$(INCDIR) -std=c++11
LDFLAGS = -L/yourpath/sorting-visualization/sfml/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -Wl,-rpath,./sfml/lib/

# Target file and object files
TARGET = main
SRCDIR = src
INCDIR = include
OBJDIR = obj

# List of source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)

# Generate object file names from source file names
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

# Standard rule for compiling a .cpp file to a .o file
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Maintarget: Generates exe
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

# Clean: Deletes all .o files and the exe
clean:
	rm -f $(OBJS) $(TARGET)

# Create the directories if they don't exist
$(shell mkdir -p $(OBJDIR))

# Rules for individual files
$(OBJDIR)/application.o: $(SRCDIR)/application.cpp
$(OBJDIR)/array.o: $(SRCDIR)/array.cpp
$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
$(OBJDIR)/algorithms.o: $(SRCDIR)/algorithms.cpp
$(OBJDIR)/buttons.o: $(SRCDIR)/buttons.cpp