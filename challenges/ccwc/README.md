# CCWC Challenge

A C implementation of the Unix `wc` (word count) command that counts lines, words, and characters in text files or standard input.

## Description

This challenge implements a clone of the standard Unix `wc` command, providing the same functionality and behavior as the original tool.

## Features

- Count lines (`-l` flag)
- Count words (`-w` flag)  
- Count bytes (`-c` flag)
- Count multibyte characters (`-m` flag)
- Support for both file input and piped input
- Compatible with standard Unix `wc` behavior

## Language

C

## Difficulty

Intermediate

## Usage

```bash
# Build the challenge
make all

# Run with file input
./ccwc filename.txt

# Run with piped input
echo "hello world" | ./ccwc

# Use specific flags
./ccwc -l filename.txt    # Count lines only
./ccwc -w filename.txt    # Count words only
./ccwc -c filename.txt    # Count bytes only
./ccwc -m filename.txt    # Count multibyte characters
```

## Testing

```bash
# Run tests
make test
# or
./test.sh
```

## Implementation Details

The implementation includes:
- Command line argument parsing
- File and standard input handling
- Character counting with proper word boundary detection
- Multibyte character support for UTF-8 text
- Output formatting matching the original `wc` command

## Files

- `src/main.c` - Main program logic and argument parsing
- `src/lib.c` - Core counting functions
- `include/lib.h` - Function declarations
- `test.sh` - Test suite
