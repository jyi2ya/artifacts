#!/bin/bash

set -e

gcc main.c -o main
g++ std.cpp -o std

for i in {1..100}; do
	echo $i
	perl > in <<'EOF'
	($n, $m) = (3, 3);
	print "$n $m\n";
	for (1 .. $n) {
		printf "%d ", int rand 2 for (1 .. $m);
		print "\n";
	}
EOF
	./std < in > ans
	./main < in > out
	diff out ans
done

rm -f in out ans std main
