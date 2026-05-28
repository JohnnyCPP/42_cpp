#!/bin/bash

PROG="./RPN"

echo "=== RPN TESTS ==="
echo

echo "Test 1: 3 4 +"
echo "Expected: 7"
echo -n "Actual: "
$PROG "3 4 +"
echo

echo "Test 2: 10 5 -"
echo "Expected: 5"
echo -n "Actual: "
$PROG "10 5 -"
echo

echo "Test 3: 4 2 *"
echo "Expected: 8"
echo -n "Actual: "
$PROG "4 2 *"
echo

echo "Test 4: 8 4 /"
echo "Expected: 2"
echo -n "Actual: "
$PROG "8 4 /"
echo

echo "Test 5: 2 3 + 4 *"
echo "Expected: 20"
echo -n "Actual: "
$PROG "2 3 + 4 *"
echo

echo "Test 6: 5 1 2 + 4 * + 3 -"
echo "Expected: 14"
echo -n "Actual: "
$PROG "5 1 2 + 4 * + 3 -"
echo

echo "Test 7: 9 3 / 2 * 4 +"
echo "Expected: 10"
echo -n "Actual: "
$PROG "9 3 / 2 * 4 +"
echo

echo "Test 8: 42"
echo "Expected: 42"
echo -n "Actual: "
$PROG "42"
echo

echo "Test 9: -5 3 +"
echo "Expected: Error of negative numbers."
echo -n "Actual: "
$PROG "-5 3 +"
echo

echo "Test 10: 0 5 /"
echo "Expected: 0"
echo -n "Actual: "
$PROG "0 5 /"
echo

echo "Test 11: 1 2 3 4 5 + + + +"
echo "Expected: 15"
echo -n "Actual: "
$PROG "1 2 3 4 5 + + + +"
echo

echo "Test 12: 3 4 + 5"
echo "Expected: Error of invalid expression."
echo -n "Actual: "
$PROG "3 4 + 5"
echo

echo "Test 13: 3 0 /"
echo "Expected: Error of division by zero."
echo -n "Actual: "
$PROG "3 0 /"
echo

echo "Test 14: 1 2 + +"
echo "Expected: Error of insufficient operands."
echo -n "Actual: "
$PROG "1 2 + +"
echo

echo "Test 15: 1 2"
echo "Expected: Error of invalid expression."
echo -n "Actual: "
$PROG "1 2"
echo

echo "Test 16: abc"
echo "Expected: Error of invalid token."
echo -n "Actual: "
$PROG "abc"
echo

echo "Test 17: empty string"
echo "Expected: Error of invalid expression."
echo -n "Actual: "
$PROG ""
echo

echo "Test 18: 5   6   +"
echo "Expected: 11"
echo -n "Actual: "
$PROG "5   6   +"
echo

echo "Test 19: 10 2 / 3 * 1 -"
echo "Expected: 14"
echo -n "Actual: "
$PROG "10 2 / 3 * 1 -"
echo

build_overflow_expression()
{
	local op="$1"
	local num_count="$2"
	local expression=""
	local i=1
	local j=1

	while [ $i -le $num_count ]
	do
		expression="$expression 9"
		i=$((i + 1))
	done
	j=2
	while [ $j -le $num_count ]
	do
		expression="$expression $op"
		j=$((j + 1))
	done
	echo "$expression"
}

test_double_overflow_multiplication()
{
	echo "Test Double Overflow: Multiplication"
	echo "Building expression with 23860 numbers of 9..."
	local expr=$(build_overflow_expression "*" 23860)
	echo "Expression: $expr"
	echo -n "Result: "
	$PROG "$expr"
	echo
}

test_double_overflow_multiplication

echo "=== END ==="
