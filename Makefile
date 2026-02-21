# Makefile for House-Renting-Database

# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Source files
SRC = main.cpp ClientList.cpp
# Executable name
TARGET = houseDB

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -static-libgcc -static-libstdc++ -o $(TARGET)

# Clean up compiled files
clean:
	rm -f $(TARGET) *.o

.PHONY: all clean