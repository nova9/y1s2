# Compiler
CXX = gcc

# Compiler flags
CXXFLAGS =

# Target executable
TARGET = q1.out q2.out q3.out q4.out

# Source files
SRCS = main.c

INCLUDES = includes/graph.c includes/list.c

PROGRAMS = q1 q2

all: $(PROGRAMS)

$(PROGRAMS):%:%/main.c
	$(CXX) $(CXXFLAGS) $@/$(SRCS) $(INCLUDES) -o $@.out

clean:
	rm -f $(TARGET)