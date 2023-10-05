# Compiler and Flags
CXX = g++
CXXFLAGS = -I/yourpath/sorting-algorithm-visualization/sfml/include -std=c++14
LDFLAGS = -L/yourpath/Desktop/sorting-algorithm-visualization/sfml/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -Wl,-rpath,./sfml/lib/

# Test Compiler and Flags (for Google Test)
TEST_CXX = g++
TEST_CXXFLAGS = -I/Users/v/Desktop/sorting/sfml/include -std=c++14 -I/path/to/google-test/include
TEST_LDFLAGS = -L/Users/v/Desktop/sorting/sfml/lib -L/path/to/google-test/lib
TEST_LIBS = -lgtest -lgtest_main -pthread

# Zieldatei und Objektdateien
TARGET = main
OBJS = array.o buttons.o application.o algorithms.o main.o

# Test target and object files
TEST_TARGET = sortingTests
TEST_OBJS = array.o buttons.o application.o algorithms.o sortingTests.o

# Standard-Regel zum Kompilieren einer .cpp-Datei zu einer .o-Datei
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Hauptziel: Erzeugt das Ausführbare
$(TARGET): $(OBJS) 
	$(CXX) $(LDFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

# Test target: Erzeugt das Test-Ausführbare
$(TEST_TARGET): $(TEST_OBJS) 
	$(TEST_CXX) $(TEST_CXXFLAGS) $(TEST_LDFLAGS) $(TEST_OBJS) -o $(TEST_TARGET) $(TEST_LIBS)

# Regeln für einzelne Dateien
application.o: application.cpp
array.o: array.cpp
main.o: main.cpp
algorithms.o: algorithms.cpp
buttons.o: buttons.cpp

# Test source file
sortingTests.o: sortingTests.cpp

# Bereinigen: Löscht alle .o-Dateien und das Ausführbare
clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)

