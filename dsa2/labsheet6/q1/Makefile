# Compiler
CC = gcc

# Target executable
TARGET = main

# Source files
SRCS = main.c list.c graph.c queue.c

# Link the object files to create the executable
$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET)

# Clean the object files and executable
clean:
	rm -f $(TARGET)
