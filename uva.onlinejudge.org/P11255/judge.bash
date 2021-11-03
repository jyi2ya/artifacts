#!/bin/bash

data()
{
	awk -v seed=$(($RANDOM << 16 | $RANDOM)) -e '
	BEGIN {
	srand(seed);
	T = 10;
	max = 30;
	printf("%d\n", T);
	for (i = 0; i < T; ++i)
		printf("%d %d %d\n", rand() * max, rand() * max, rand() * max);
}
	'
}

comp()
{
	g++ std.cpp -o std && gcc main.c -o main
}

clean()
{
	rm -f std main din out ans
}

comp || exit 1
for i in {1..100}; do
	echo $i
	data > din
	./main < din > out
	./std < din > ans
	diff out ans || exit 1
done

clean
