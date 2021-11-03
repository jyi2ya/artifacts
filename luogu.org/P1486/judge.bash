#!/bin/bash

data()
{
	awk -v seed=$RANDOM -e '
	BEGIN {
	n = 100000;
	min = 10000000;
	argmax = 100000;
	srand(seed);
	cmd[0] = "I";
	cmd[1] = "A";
	cmd[2] = "S";
	cmd[3] = "F";
	printf("%d %d\n", n, min);
	for (i = 0; i < n; ++i)
		printf("%s %d\n", cmd[int(rand() * 4)], rand() * argmax);
}
	'
}

comp()
{
	gcc main.c -o main
}

comp || exit 1
for i in {1..1000}; do
	printf "%d\n" "$i"
	data > in
	./main < in > /dev/null || exit 1
done
