#!/bin/bash

set -e

data()
{
	perl -e'
	$n = 1000;
	$am = 1000;
	print "$n\n";
	print ((int rand $am) . " ") for (1 .. $n);
	print "\n";
	for (1 .. $n) {
		$l = 1 + int rand($n - 1);
		$r = 1 + int rand($n - 1);
		($l, $r) = ($r, $l) if ($l > $r);
		printf "%d %d %d %d\n", rand 2, $l, $r, int rand $am
	}
	'
}

gcc -lm main.c -o main && g++ brute.c -o brute
for i in {1..100}; do
	echo $i
	data > in
	./main < in > out
	./brute < in > ans
	diff out ans
done

rm in out ans main brute
