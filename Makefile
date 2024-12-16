# Compiler
CXX = g++

# Compiler flags
INCLUDES = -IInc
CXXFLAGS = -std=c++17 $(INCLUDES)

# Target executable name
TARGET = program

# Source files
SRC = Src/*

# Build the target
all: run

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Run the program
run: clean $(TARGET) 
	./$(TARGET)
# Clean the build
clean:
	rm -f $(TARGET)
