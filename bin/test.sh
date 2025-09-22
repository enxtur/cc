#!/bin/bash

# check if wc is installed
if ! command -v wc &> /dev/null; then
    echo "wc could not be found"
    exit 1
fi

make clean
make all

test_string="This\nis test"

# piped test
result_wc="$(echo "$test_string" | wc)"
result_wc="${result_wc// /}"
result_ccwc="$(echo "$test_string" | ./ccwc | sed 's/\t//g')"

if [ "$result_wc" == "$result_ccwc" ]; then
    echo "piped test passed"
else
    echo "piped test failed:"
    echo "expected: $result_wc"
    echo "actual  : $result_ccwc"
    exit 1
fi


# file test
echo "$test_string" > /tmp/test.txt
result_wc="$(wc /tmp/test.txt)"
result_wc="${result_wc// /}"
result_ccwc="$(./ccwc /tmp/test.txt | sed 's/\t//g')"

if [ "$result_wc" == "$result_ccwc" ]; then
    echo "file test passed"
else
    echo "file test failed:"
    echo "expected: $result_wc"
    echo "actual  : $result_ccwc"
    exit 1
fi
