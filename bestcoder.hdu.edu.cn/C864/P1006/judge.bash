#!/bin/bash

data()
{
	perl -e '
	$T = 10;
	print("$T\n");
	while ($T--) {
		($n, $m, $k) = (300, 300, 300);
		print("$n $m $k\n");
		printf("%d %d\n", 1 + int rand($n - 1), 1 + int rand($n - 1))
			for (1 .. $n);
	}
	'
}

while :; do
	data > in
	time ./main
done
