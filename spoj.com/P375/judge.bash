#!/bin/bash

set -e

d()
{
	perl <<'EOF'
$n = 10;
$m = 20;
$varmax = 10;
print "$n\n";
printf "%d %d %d\n", 1 + int rand ($_ - 1), $_, rand $varmax for (2 .. $n);
for (1 .. $m) {
	if (int rand 2) {
		printf "QUERY %d %d\n", 1 + int rand $n, 1 + int rand $n
	} else {
		printf "CHANGE %d %d\n", 1 + int rand $n, rand $varmax
	}
}
print "DONE\n";
EOF
}

gcc main.c -o main
g++ std.cpp -o std
for i in {1..100}; do
	echo $i
	d > in
	./main < in > out
	./std < in > ans
	diff out ans
done
rm -f main std in out ans
