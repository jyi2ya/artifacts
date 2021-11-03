#!/bin/bash

gcc main.c -o main && g++ std.cpp -o std || exit 1

for i in *.in; do
	[ ! -f $i ] && break
	./main < $i > out
	./std < $i > ans
	diff out ans || exit 1
done

for i in {1..100}; do
	echo $i
	perl > in <<':'
	$T = 1;
	$varmax = 100;
	$n = 3;
	while ($T--) {
		$k = 1 + int rand $n;
		print "$n $k\n";
		@b = ();
		@a = ();
		$b[$_ - 1] = int rand $varmax for (1 .. $n);
		$a[$_ - 1] = int rand $b[$_ - 1] for (1 .. $n);
		print join ' ', @a;
		print "\n";
		print join ' ', @b;
		print "\n";
	}
	print "0 0\n";
:
	./main < in > out
	./std < in > ans
	diff out ans || {
		mv in $RANDOM$RANDOM.in
		exit 1
	}
done

rm -f in out ans main std
