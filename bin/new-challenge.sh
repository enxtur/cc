#!/bin/bash

# John Cricket's Coding Challenges - New Challenge Generator
# This script creates a new challenge from the template

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"
TEMPLATE_DIR="$PROJECT_ROOT/challenges/template"
CHALLENGES_DIR="$PROJECT_ROOT/challenges"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

usage() {
    echo "Usage: $0 <challenge-name>"
    echo
    echo "Creates a new challenge from the template."
    echo "The challenge name should be lowercase with hyphens or underscores."
    echo
    echo "Examples:"
    echo "  $0 hello-world"
    echo "  $0 file-utils"
    echo "  $0 data_structures"
}

if [ $# -ne 1 ]; then
    usage
    exit 1
fi

CHALLENGE_NAME="$1"
CHALLENGE_DIR="$CHALLENGES_DIR/$CHALLENGE_NAME"

# Validate challenge name
if [[ ! "$CHALLENGE_NAME" =~ ^[a-z0-9_-]+$ ]]; then
    echo -e "${RED}Error: Challenge name must contain only lowercase letters, numbers, hyphens, and underscores${NC}"
    exit 1
fi

# Check if template exists
if [ ! -d "$TEMPLATE_DIR" ]; then
    echo -e "${RED}Error: Template directory not found at $TEMPLATE_DIR${NC}"
    exit 1
fi

# Check if challenge already exists
if [ -d "$CHALLENGE_DIR" ]; then
    echo -e "${RED}Error: Challenge '$CHALLENGE_NAME' already exists at $CHALLENGE_DIR${NC}"
    exit 1
fi

echo -e "${BLUE}Creating new challenge: $CHALLENGE_NAME${NC}"
echo

# Copy template to new challenge directory
cp -r "$TEMPLATE_DIR" "$CHALLENGE_DIR"

# Replace template references in files
cd "$CHALLENGE_DIR"

# Update Makefile
sed -i.bak "s/TARGET = template/TARGET = $CHALLENGE_NAME/g" Makefile
rm -f Makefile.bak

# Update header file
mv include/template.h "include/$CHALLENGE_NAME.h"
# Convert challenge name to uppercase for header guard
CHALLENGE_NAME_UPPER=$(echo "$CHALLENGE_NAME" | tr '[:lower:]' '[:upper:]' | tr '-' '_')
sed -i.bak "s/TEMPLATE_H/${CHALLENGE_NAME_UPPER}_H/g" "include/$CHALLENGE_NAME.h"
sed -i.bak "s/template\.h/$CHALLENGE_NAME.h/g" "include/$CHALLENGE_NAME.h"
rm -f "include/$CHALLENGE_NAME.h.bak"

# Update source files
mv src/template.c "src/$CHALLENGE_NAME.c"
sed -i.bak "s/template\.h/$CHALLENGE_NAME.h/g" "src/$CHALLENGE_NAME.c"
rm -f "src/$CHALLENGE_NAME.c.bak"

sed -i.bak "s/template\.h/$CHALLENGE_NAME.h/g" src/main.c
rm -f src/main.c.bak

# Update README
sed -i.bak "s/Template Challenge/$CHALLENGE_NAME Challenge/g" README.md
sed -i.bak "s/template/$CHALLENGE_NAME/g" README.md
rm -f README.md.bak

# Update test.sh file
sed -i.bak "s/template/$CHALLENGE_NAME/g" test.sh
rm -f test.sh.bak

# Make sure test.sh is executable
chmod +x test.sh

echo -e "${GREEN}✓ Challenge '$CHALLENGE_NAME' created successfully!${NC}"
echo
echo -e "${BLUE}Next steps:${NC}"
echo -e "1. Edit the files in $CHALLENGE_DIR to implement your challenge"
echo -e "2. Update the README.md with your challenge description"
echo -e "3. Replace the test.sh with actual tests for your challenge"
echo -e "4. Run 'make test-$CHALLENGE_NAME' or './test.sh' to test your challenge"
echo
echo -e "${YELLOW}Files created:${NC}"
echo -e "  - $CHALLENGE_DIR/Makefile"
echo -e "  - $CHALLENGE_DIR/src/main.c"
echo -e "  - $CHALLENGE_DIR/src/$CHALLENGE_NAME.c"
echo -e "  - $CHALLENGE_DIR/include/$CHALLENGE_NAME.h"
echo -e "  - $CHALLENGE_DIR/README.md"
echo -e "  - $CHALLENGE_DIR/test/"
echo -e "  - $CHALLENGE_DIR/test.sh"
