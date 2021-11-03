#!/bin/bash

set -e

gcc brute.c -o brute
gcc main.c -o noname

for i in {1..100}; do
	echo $i
	perl > noname.in <<'EOF'
	($n, $m) = (2 + int rand (100 - 2), int rand 1000000000);
	print "$n $m\n";
EOF
	./brute
	mv noname.out noname.ans
	./noname
	diff noname.out noname.ans
done

rm -f noname.{in,out,ans} noname brute main
