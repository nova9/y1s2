# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11

# Target executable
TARGET = main

# Source files
SRCS = main.cpp graph.cpp


compile: $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

.PHONY: clean

clean:
	rm -f $(OBJS) $(TARGET)


run: compile
	./$(TARGET)