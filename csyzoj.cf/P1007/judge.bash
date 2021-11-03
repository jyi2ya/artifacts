#!/bin/bash

set -e

gcc -DLOCAL_TEST brute.c -o brute
gcc -DLOCAL_TEST main.c -o main

for i in {1..100}; do
	echo $i
	perl > in <<'EOF'
#($n, $m, $var) = (100, 100, 1000);
($n, $m, $var) = (2, 2, 10);
print "$n $m\n";
printf '%d ', 1 + int rand $var for (1 .. $n);
print "\n";
for (1 .. $m) {
	if (int rand 2) {
		printf "Q %d\n", 1 + int rand $var;
	} else {
		printf "C %d %d\n", 1 + int rand $n, 1 + int rand $var;
	}
}
EOF
	./brute < in > ans
	./main < in > out
	diff out ans
done

rm -f in out ans brute main
