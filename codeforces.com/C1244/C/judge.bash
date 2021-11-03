#!/bin/bash

set -e

gcc main.c -o main
g++ std.cpp -o std -DONLINE_JUDGE

for i in {1..10000}; do
	echo $i
	perl >in <<'EOF'
	$n = 1 + int rand 1e12;
	$p = int rand 1e17;
	$d = 1 + int rand 1e5;
	$w = 1 + int rand 1e5;
	print "$n $p $w $d\n";
EOF
	timeout 1 ./main < in > out
	timeout 1 ./std < in > ans
	diff out ans
done

rm -f main in out ans std
