#!/bin/bash

PROG="./RPN"

echo "=== RPN TESTS ==="
echo

echo "Test 1: 3 4 +"
echo "Expected: 7"
$PROG "3 4 +"
echo

echo "Test 2: 10 5 -"
echo "Expected: 5"
$PROG "10 5 -"
echo

echo "Test 3: 4 2 *"
echo "Expected: 8"
$PROG "4 2 *"
echo

echo "Test 4: 8 4 /"
echo "Expected: 2"
$PROG "8 4 /"
echo

echo "Test 5: 2 3 + 4 *"
echo "Expected: 20"
$PROG "2 3 + 4 *"
echo

echo "Test 6: 5 1 2 + 4 * + 3 -"
echo "Expected: 14"
$PROG "5 1 2 + 4 * + 3 -"
echo

echo "Test 7: 9 3 / 2 * 4 +"
echo "Expected: 10"
$PROG "9 3 / 2 * 4 +"
echo

echo "Test 8: 42"
echo "Expected: 42"
$PROG "42"
echo

echo "Test 9: -5 3 +"
echo "Expected: -2"
$PROG "-5 3 +"
echo

echo "Test 10: 0 5 /"
echo "Expected: 0"
$PROG "0 5 /"
echo

echo "Test 11: 1 2 3 4 5 + + + +"
echo "Expected: 15"
$PROG "1 2 3 4 5 + + + +"
echo

echo "Test 12: 3 4 + 5 (invalid expression)"
echo "Expected: error message"
$PROG "3 4 + 5"
echo

echo "Test 13: 3 0 /"
echo "Expected: division by zero error"
$PROG "3 0 /"
echo

echo "Test 14: 1 2 + +"
echo "Expected: insufficient operands error"
$PROG "1 2 + +"
echo

echo "Test 15: 1 2"
echo "Expected: invalid expression error"
$PROG "1 2"
echo

echo "Test 16: abc"
echo "Expected: invalid token error"
$PROG "abc"
echo

echo "Test 17: empty string"
echo "Expected: error"
$PROG ""
echo

echo "Test 18: 5   6   +"
echo "Expected: 11"
$PROG "5   6   +"
echo

echo "Test 19: 10 2 / 3 * 1 -"
echo "Expected: 14"
$PROG "10 2 / 3 * 1 -"
echo

echo "=== END ==="
