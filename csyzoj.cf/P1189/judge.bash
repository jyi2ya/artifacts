#!/bin/bash

hugedata ()
{
	# 可以卡到 O(n sqrt n) ，大成功。
	perl <<'EOF'
	$n = 500000;
	$t = 707; # sqrt(n)
	print "$n $t\n";
	for (1 .. $n) {
		printf "%d %d\n", 1, $_;
	}
EOF
}

data ()
{
	perl <<'EOF'
	sub R { 1 + int rand shift }
	$nmax = 500000;
	$n = R($nmax);
	$t = R($nmax);
	print "$n $t\n";
	for (1 .. $n) {
		printf "%d %d\n", R($n), R($n);
	}
EOF
}

hugedata
exit

set -e
gcc brute.c -o brute
p=wayhome
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
