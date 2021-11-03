#!/bin/bash

set -e

data()
{
	perl -e '
	$T = 1;
	print("$T\n");
	while ($T--) {
		$P = 5;
		$a = int rand $P;
		$b = int rand $P;
		$X = 1 + int rand($P - 1);
		$t = 1 + int rand($P - 1);
		print("$P $a $b $X $t\n");
	}
	'
}

gcc -lm main.c -o main && g++ std.cpp -o std
for i in {1..100}; do
	echo $i
	data > in
	diff <(./main < in) <(./std < in)
done
