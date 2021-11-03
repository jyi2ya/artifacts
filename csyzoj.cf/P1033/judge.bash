#!/bin/bash

set -e

gcc brute.c -o brute
gcc main.c -o main

for i in {1..100}; do
	echo $i
	perl > in <<'EOF'
	($n, $m) = (500, 500);
	$varmax = 500;
	print "$n $m\n";
	print(int(rand $varmax), " ") for (1 .. $n);
	print "\n";
	for (1 .. $m) {
		$l = 1 + int rand $n;
		$r = 1 + int rand $n;
		($l, $r) = ($r, $l) if ($l > $r);
		print "$l $r\n";
	}
EOF
	./brute < in > ans;
	./main < in > out
	diff out ans
done

rm -f in out ans brute main
