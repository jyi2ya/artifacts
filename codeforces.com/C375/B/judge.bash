#!/bin/bash

set -e

gcc main.c -o main
gcc std.c -o std

i=0
while true; do
	echo $i
	let i+=1
	perl > in <<'lty'
	($n, $m) = (501, 529);
	print "$n $m\n";
	for (1 .. $n) {
		print int rand 2 for (1 .. $m);
		print "\n";
	}
lty
	./std < in > ans
	./main < in > out
	diff out ans
done

rm -f in out ans std main
