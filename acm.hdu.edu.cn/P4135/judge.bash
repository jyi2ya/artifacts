#!/bin/bash

data()
{
	awk -v seed=$((RANDOM << 16 | RANDOM)) -e '
	BEGIN {
	t = 5;
	amax = 20;
	nmax = 10
	srand(seed);
	printf("%d\n", t);
	for (i = 0; i < t; ++i) {
		a = rand() * amax + 1;
		b = rand() * amax + 1;
		if (a > b) {
			T = a;
			a = b;
			b = T;
		}
		printf("%d %d %d\n", a, b, rand() * nmax + 1);
	}
}
	'
}

comp()
{
	gcc main.c -o main && gcc std.c -o std
}

clean()
{
	rm -f main std in out ans
}

clean

comp || exit 1

for i in {1..100}; do
	echo $i
	data > in
	./main < in > out
	./std < in > ans
	diff -d out ans || exit 1
done

clean
