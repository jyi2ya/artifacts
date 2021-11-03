#!/bin/bash

set -e

gcc main.c -o main
[ ! -x std ] && g++ std.cpp -o std

for i in {1..100}; do
	echo $i
	perl > in <<'EOF'
	($len, $k) = (1000, int rand 4);
	print"1";
	--$len;
	print int rand 2 for (1 .. $len);
	print"\n$k\n";
EOF
	./main < in > out
	./std < in > ans
	diff out ans
done

rm -f in out ans main std
