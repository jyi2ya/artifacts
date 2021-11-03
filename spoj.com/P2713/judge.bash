#!/bin/bash

set -e

gcc main.c -o main -lm
g++ std.cpp -o std

for i in {1..100}; do
	echo $i
	perl > in <<'EOF'
	$T = 10;
	$varmax = 100000;
	while ($T--) {
		($n, $m) = (100, 100);
		print "$n\n";
		print(1 + int(rand $varmax), " ") for (1 .. $n);
		print "\n$m\n";
		printf "%d %d %d\n", int rand 2, 1 + int rand $n, 1 + int rand $n for (1 .. $m);
	}
EOF
	./main < in > out
	./std < in > ans
	diff out ans
done

rm -f out ans in main std
