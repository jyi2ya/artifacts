#!/bin/bash

data ()
{
	perl <<'EOF'
	sub R { int rand shift }
	$nmax = 5000;
	$qmax = 5000;
	($n, $q) = (R($nmax), R($qmax));
	$varmax = int 1e9;
	print "$n $q\n";
	for (1 .. $n) {
		printf "%d ", R($varmax);
	}
	print "\n";
	for (1 .. $q) {
		($l, $r) = (R($n), R($n));
		($l, $r) = ($r, $l) if $l > $r;
		printf "%d %d %d\n", R($varmax), $l, $r;
	}
EOF
}

set -e
gcc brute.c -o brute
p=hugclose
g++ $p.cpp -o $p
for i in {1..100}; do
	echo $i
	data > $p.in
	./brute
	mv $p.{out,ans}
	timeout 1 ./$p
	diff $p.{out,ans}
done

rm -f $p.{in,out,ans} $p brute
