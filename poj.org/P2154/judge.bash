#!/bin/bash

data()
{
	awk -v seed=$((RANDOM << 16 | RANDOM)) -e '
	BEGIN {
	srand(seed);

	t = 1;
	pmax = 30000;
	nmax = 10; /* #00000000; */

	printf("%d\n", t);
	while (t--) {
		printf("%d %d\n", rand() * nmax, rand() * pmax);
	}
}'
}

comp()
{
	gcc -lm std.c -o std && gcc main.c -o main -lm
}

clean()
{
	rm -f main std din out ans
}

comp || exit
for i in {1..100}; do
	echo $i
	data > din
	./main < din > out
	./std < din > ans
	diff out ans || exit 1
done
clean
