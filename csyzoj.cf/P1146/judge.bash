#!/bin/bash
set -e
gcc main.c -o main
g++ std.cpp -o std
for i in {1..100}; do
	echo $i
	perl > in <<'EOF'
	$T = 1;
	print "$T\n";
	while ($T--) {
		($n, $m) = (5, 3);
		print "$n $m\n";
		printf "%d ", int rand 10 for 1 .. $n;
		print "\n";
	}
EOF
	./main < in > out
	./std < in > ans
	diff out ans
done

rm -f in out ans std main
