#!/bin/sh

set -e

cnt=0
g++ -O3 huff.cpp -o huff
gcc -O3 enum.c -o enum
while :; do
	perl -e '
	$n = 4;
	print "$n\n";
	print int(rand(10)), " " for (1 .. $n);
	print "\n";
	' > in
	./enum < in > ans
	./huff < in > out
	diff out ans
done
