#!/bin/bash

set -e

gcc main.c -o main
g++ std.cpp -o std

for i in {1..100}; do
	echo $i
	perl > in <<'EOF'
	$n = 100000;
	print "$n\n";
	print "01" for (1 .. ($n / 2));
	#print int rand 2 for (1 .. $n);
	print "\n";
EOF
	./main < in > out
	./std < in > ans
	diff out ans
done

rm -f in out ans main std
