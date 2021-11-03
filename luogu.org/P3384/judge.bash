#!/bin/bash

set -e

data()
{
	perl <<'EOF'
use List::Util qw/shuffle/;
($n, $m, $r, $p, $varmax) = (10, 10, undef, 109, 10);
@a = shuffle(1 .. $n);
$r = $a[0];
print "$n $m $r $p\n";
printf "%d ", rand $varmax for (1 .. $n);
print "\n";
printf "%d %d\n", $a[rand $_], $a[$_] for (1 .. ($n - 1));
for (1 .. $m) {
	$op = 1 + int rand 4;
	print "$op ";
	if ($op == 1) {
		printf "%d %d %d\n", 1 + int rand $n, 1 + int rand $n, int rand $varmax;
	} elsif ($op == 2) {
		printf "%d %d\n", 1 + int rand $n, 1 + int rand $n;
	} elsif ($op == 3) {
		printf "%d %d\n", 1 + int rand $n, int rand $varmax;
	} elsif ($op == 4) {
		printf "%d\n", 1 + int rand $n;
	}
}
EOF
}

gcc main.c -o main
g++ std.cpp -o std

for i in {1..100}; do
	echo $i
	data > in
	./main < in > out
	./std < in > ans
	diff out ans
done
