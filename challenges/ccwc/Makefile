CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=dist/%.o)
TARGET = ccwc

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