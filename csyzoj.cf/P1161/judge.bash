#!/bin/bash

set -e
p=apple
gcc brute.c -o brute
g++ $p.cpp -o $p
for i in {1..100}; do
	echo $i
	perl > $p.in <<'EOF'
	sub R { 1 + int rand shift }
	$nmax = 10000;
	$n = R($nmax);
	$k = R($n) - 1;
	printf "%d %d\n", $n, $k;
	printf "%d\n", (R($_ - 1) - 1) for 2 .. $n;
EOF
	./brute
	mv $p.{out,ans}
	./$p
	diff $p.{out,ans}
done

rm -f $p.{in,out,ans} $p brute
