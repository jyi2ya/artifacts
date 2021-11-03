#!/bin/bash

data()
{
	awk -v seed=$(($RANDOM << 16 | $RANDOM)) -e '
	BEGIN {
	n = 500;
	max = (2 ** 31) - 1;
	srand(seed);
	printf("%d\n", n);
	for (i = 0; i < n; ++i)
		printf("%d ", rand() * max);
	print("\n");
}'
}

comp()
{
	gcc std.c -o std && g++ main.c -o main
}

comp || exit 1
for i in {1..100}; do
	echo $i
	data > din
	diff <(./std < din) <(./main < din) || exit 1
done
rm din main std
