# Makefile for Minesweeper Game

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SOURCES = main.c display.c board.c scores.c game.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = main

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compile each source file to object file
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild everything
rebuild: clean all

# Phony targets (not actual files)
.PHONY: all run clean rebuild
