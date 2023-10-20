# Makefile for building and running the fork and generation printing code

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++20

# Target executable name
TARGET = generations

# Source files
SRC = generations.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)	$(ARG)

clean:
	rm -f $(TARGET)

