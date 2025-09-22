# John Cricket's Coding Challenges

Welcome to John Cricket's collection of coding challenges! This repository contains a series of programming challenges designed to test and improve your coding skills across different domains and difficulty levels.

## Overview

Each challenge is self-contained in its own directory under `challenges/` and includes:
- Source code
- Build configuration (Makefile)
- Test suite
- Documentation

## Available Challenges

- [**CCWC**](challenges/ccwc/README.md) - Clone of `wc` command

## Getting Started

### Prerequisites
- GCC compiler
- Make
- Unix-like environment (Linux/macOS)

### Building All Challenges
```bash
make all
```

### Running Tests
```bash
make test
# or
./bin/test.sh
```

### Building a Specific Challenge
```bash
make build-ccwc
```

### Testing a Specific Challenge
```bash
make test-ccwc
```

### Cleaning All Challenges
```bash
make clean
```

### Cleaning a Specific Challenge
```bash
make clean-ccwc
```

### Listing Available Challenges
```bash
make list
```

### Creating a New Challenge
```bash
make new-my-challenge
# or
./bin/new-challenge.sh my-challenge
```

## Project Structure

```
.
├── README.md              # This file
├── Makefile              # Root Makefile for building all challenges
├── bin/
│   ├── test.sh           # Test runner for all challenges
│   └── new-challenge.sh  # Script to create new challenges from template
└── challenges/
    ├── template/          # Template challenge (excluded from builds/tests)
    │   ├── Makefile      # Template Makefile
    │   ├── src/          # Template source code
    │   ├── include/      # Template headers
    │   ├── test/         # Template test files
    │   └── README.md     # Template documentation
    └── ccwc/             # CCWC challenge
        ├── Makefile      # Challenge-specific Makefile
        ├── src/          # Source code
        │   ├── main.c
        │   └── lib.c
        ├── include/      # Header files
        │   └── lib.h
        ├── test.txt      # Test file
        └── dist/         # Build artifacts (created during build)
```

## Adding New Challenges

### Method 1: Using the Template (Recommended)
```bash
make new-my-challenge
```

This will:
- Copy the template challenge to `challenges/my-challenge/`
- Replace all template references with your challenge name
- Create a basic structure with Makefile, source files, headers, and tests
- Generate a README template for you to customize

### Method 2: Manual Creation
1. Create a new directory under `challenges/`
2. Add your source code, Makefile, and tests
3. Create a `test.sh` script in your challenge directory
4. Ensure your Makefile has the following targets:
   - `all`: Build the challenge
   - `test`: Call the test.sh script
   - `clean`: Clean build artifacts
5. The root test runner will automatically discover and run your test.sh

### Template Structure
The template challenge includes:
- **Makefile**: Build configuration with standard targets
- **src/main.c**: Main source file
- **src/template.c**: Additional source file (renamed to your challenge)
- **include/template.h**: Header file (renamed to your challenge)
- **README.md**: Documentation template
- **test/**: Directory for test files
- **test.sh**: Test script that builds and tests your challenge

### Testing Approach
Each challenge should have a `test.sh` script that:
- Builds the challenge (usually calls `make clean && make all`)
- Runs comprehensive tests
- Returns exit code 0 on success, non-zero on failure
- Provides clear output about test results

The root test runner will:
- Find all challenges (excluding template)
- Check for executable `test.sh` files
- Run each test.sh and report results
- Provide a summary of all test results

## Contributing

This is a personal collection of coding challenges. Each challenge is designed to be educational and demonstrate different programming concepts and techniques.

## License

This project is for educational purposes. Feel free to use and modify the code for learning purposes.
