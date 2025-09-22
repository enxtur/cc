CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=dist/%.o)
TARGET = ccwc

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

dist/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

test:
	./bin/test.sh

.PHONY: all clean test