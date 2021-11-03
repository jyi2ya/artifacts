#!/bin/bash

set -e

gcc main.c -o main
g++ std.cpp -o std

for i in {1..100}; do
	echo $i
	perl > in <<'lty'
	$T = 10;
	print "$T\n";
	while ($T--) {
		$n = 25;
		for (1 .. $n) {
			print int rand 2 for (1 .. $n);
			print "\n";
		}
	}
lty
	./std < in > ans
	./main < in > out
	diff out ans
done

rm -f in out ans std main
