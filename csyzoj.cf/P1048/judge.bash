#!/bin/bash

set -e
p=frenzy
gcc main.c -o $p
g++ std.cpp -o std
for i in {1..100}; do
	echo $i
	perl > $p.in <<'EOF'
	#$T = 10;
	$T = 1;
	print "$T\n";
	while ($T--) {
		($n, $k) = (int rand 1000, int rand 1000);
		print "$n $k\n";
		printf "0 %d %d\n", int rand 1000, int rand 1000;
		printf "%d %d %d\n", rand 1000, rand 1000, rand 1000 for (2 .. $n);
	}
EOF
	./std
	mv $p.{out,ans}
	./$p
	diff $p.{out,ans}
done

rm -f $p.{in,out,ans} $p std
