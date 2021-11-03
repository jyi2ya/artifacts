#!/bin/bash

set -e
p=debate
b=brute
g++ $p.cpp -o $p
gcc $b.c -o $b
for i in {1..100}; do
	echo $i
	perl > $p.in <<'EOF'
	$n = 20;
	print "$n\n";
	printf "%02b %d\n", int rand 4, int rand 40000 for 1 .. $n;
EOF
	./$b
	mv $p.out $p.ans
	./$p
	diff $p.out $p.ans
done

rm -f $p.{in,out,ans} $p $b
