# Template Makefile for John Cricket's Coding Challenges
# Copy this file to your new challenge directory and modify as needed

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=dist/%.o)
TARGET = json-parser

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

dist/%.o: src/%.c | dist
	$(CC) $(CFLAGS) -c $< -o $@

dist:
	mkdir -p dist

clean:
	rm -f $(OBJ) $(TARGET)
	rmdir dist 2>/dev/null || true

test:
	@./test.sh

.PHONY: all clean test
