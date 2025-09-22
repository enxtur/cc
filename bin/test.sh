#!/bin/bash

# John Cricket's Coding Challenges - Test Runner
# This script runs tests for all challenges in the challenges directory

CHALLENGES_DIR="challenges"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"

cd "$PROJECT_ROOT"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}=== John Cricket's Coding Challenges - Test Runner ===${NC}"
echo

# Check if challenges directory exists
if [ ! -d "$CHALLENGES_DIR" ]; then
    echo -e "${RED}Error: $CHALLENGES_DIR directory not found${NC}"
    exit 1
fi

# Find all challenge directories (excluding template)
challenges=($(find "$CHALLENGES_DIR" -maxdepth 1 -type d -not -name "$CHALLENGES_DIR" | grep -v "/template$" | sort))

if [ ${#challenges[@]} -eq 0 ]; then
    echo -e "${YELLOW}No challenges found in $CHALLENGES_DIR directory${NC}"
    exit 0
fi

echo -e "${BLUE}Found ${#challenges[@]} challenge(s):${NC}"
for challenge in "${challenges[@]}"; do
    echo -e "  - $(basename "$challenge")"
done
echo

# Test results tracking
total_challenges=0
passed_challenges=0
failed_challenges=0

# Run tests for each challenge
for challenge in "${challenges[@]}"; do
    challenge_name=$(basename "$challenge")
    total_challenges=$((total_challenges + 1))
    
    echo -e "${BLUE}=== Testing Challenge: $challenge_name ===${NC}"
    
    # Check if challenge has a test.sh file
    if [ ! -f "$challenge/test.sh" ]; then
        echo -e "${YELLOW}Warning: No test.sh found in $challenge_name, skipping...${NC}"
        continue
    fi
    
    # Check if test.sh is executable
    if [ ! -x "$challenge/test.sh" ]; then
        echo -e "${YELLOW}Warning: test.sh is not executable in $challenge_name, skipping...${NC}"
        continue
    fi
    
    # Run the test
    echo -e "${YELLOW}Running tests for $challenge_name...${NC}"
    
    if (cd "$challenge" && ./test.sh); then
        echo -e "${GREEN}✓ $challenge_name tests passed${NC}"
        passed_challenges=$((passed_challenges + 1))
    else
        echo -e "${RED}✗ $challenge_name tests failed${NC}"
        failed_challenges=$((failed_challenges + 1))
    fi
    
    echo
done

# Print summary
echo -e "${BLUE}=== Test Summary ===${NC}"
echo -e "Total challenges: $total_challenges"
echo -e "${GREEN}Passed: $passed_challenges${NC}"
echo -e "${RED}Failed: $failed_challenges${NC}"

if [ $failed_challenges -eq 0 ]; then
    echo -e "${GREEN}All tests passed! 🎉${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed. Please check the output above.${NC}"
    exit 1
fi
