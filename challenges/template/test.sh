#!/bin/bash

# Template Challenge Test Script
# Replace this with actual tests for your challenge

set -e  # Exit on any error

echo "Running template tests..."
echo "This is a template challenge - replace with actual tests"

# Build the project first
echo "Building template..."
make clean >/dev/null 2>&1
make all >/dev/null 2>&1

# Example basic test - replace with your actual tests
echo "Running basic functionality test..."
if ./template >/dev/null 2>&1; then
    echo "✓ Basic functionality test passed"
else
    echo "✗ Basic functionality test failed"
    exit 1
fi

echo "✓ Template test passed (placeholder)"
echo
echo "Note: Replace this test.sh with actual tests for your challenge!"
