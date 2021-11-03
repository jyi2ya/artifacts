#!/bin/bash

data()
{
	awk -v seed=$(($RANDOM << 16 | $RANDOM)) -e '
	BEGIN {
	t = 10;
	n = 30;
	srand(seed);
	for (i = 0; i < t; ++i)
		printf("%d %d\n", rand() * n + 1, rand() * n + 1);
}
'
}

comp()
{
	g++ std.cpp -o std && gcc main.c -o main
}

comp || exit 1
for i in {1..100}; do
	printf "%d\n" "$i"
	data > din
	./std < din > ans
	./main < din > out
	diff out ans || exit
done

rm din out ans main std
