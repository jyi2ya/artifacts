#!/bin/bash

set -e

gcc brute.c -o brute
p=card
g++ $p.cpp -o $p
for i in {1..100}; do
	echo $i
	perl > $p.in <<'EOF'
	sub R { 1 + int rand shift }
	($nmax, $mmax) = (10000, 10000);
	#($nmax, $mmax) = (200000, 200000);
	($n, $m) = (R($nmax), R($mmax));
	#($n, $m) = ($nmax, $mmax);
	print "$n $m\n";
	printf "%d ", R($n) for 1 .. $n;
	print "\n";
	printf "%d %d\n", R($n), R($n) for 1 .. $m;
EOF
	./brute
	mv $p.{out,ans}
	timeout 1 ./$p
	diff $p.{out,ans}
done

rm -f $p.{in,out,ans} $p brute
