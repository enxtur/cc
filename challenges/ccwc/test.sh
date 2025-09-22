#!/bin/bash

# CCWC Challenge Test Script
# This script tests the ccwc (clone of wc) command implementation

set -e  # Exit on any error

echo "Running ccwc tests..."

# Check if wc is installed
if ! command -v wc >/dev/null 2>&1; then
    echo "Error: wc command not found"
    exit 1
fi

# Build the project first
echo "Building ccwc..."
make clean >/dev/null 2>&1
make all >/dev/null 2>&1

test_string="This\nis test"

# Test 1: Piped input
echo "Testing piped input..."
result_wc="$(echo "$test_string" | wc)"
result_wc="${result_wc// /}"
result_ccwc="$(echo "$test_string" | ./ccwc | sed 's/\t//g')"

if [ "$result_wc" = "$result_ccwc" ]; then
    echo "✓ piped test passed"
else
    echo "✗ piped test failed:"
    echo "expected: $result_wc"
    echo "actual  : $result_ccwc"
    exit 1
fi

# Test 2: File input
echo "Testing file input..."
echo "$test_string" > /tmp/test.txt
result_wc="$(wc /tmp/test.txt)"
result_wc="${result_wc// /}"
result_ccwc="$(./ccwc /tmp/test.txt | sed 's/\t//g')"

if [ "$result_wc" = "$result_ccwc" ]; then
    echo "✓ file test passed"
else
    echo "✗ file test failed:"
    echo "expected: $result_wc"
    echo "actual  : $result_ccwc"
    exit 1
fi

# Clean up
rm -f /tmp/test.txt

echo "✓ All ccwc tests passed!"
