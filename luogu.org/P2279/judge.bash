#!/bin/bash

set -e
gcc main.c -o main
g++ std.cpp -o std

for i in {1..100}; do
	echo $i
	perl > in <<'EOF'
	$n = 1000;
	print "$n\n";
	printf "%d\n", 1 + int rand($_ - 1) for (2 .. $n);
EOF
	./main < in > out
	./std < in > ans
	diff out ans
done

rm -f in out ans std main
