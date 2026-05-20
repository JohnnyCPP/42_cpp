#!/bin/bash

for n in 5 10 100 500; do
	numbers=$(shuf -i 1-1000 -n $n | tr "\n" " ")
	echo "$numbers" | tr ' ' '\n' | sort -n | tr '\n' ' ' | sed 's/^ //' | sed 's/ $//' > expected_${n}.txt
	./PmergeMe $numbers > output.tmp
	grep "^After:" output.tmp | sed 's/After: //' | sed 's/^ //' | sed 's/ $//' > actual_${n}.txt
	if diff -q expected_${n}.txt actual_${n}.txt > /dev/null; then
		echo "Test $n: OK"
	else
		echo "Test $n: FAIL"
	fi
done

rm -f output.tmp
