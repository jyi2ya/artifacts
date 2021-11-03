#!/bin/bash

cnt=0
while true; do
	echo $cnt
	let cnt+=1
	perl -e '
	$n = 1000000000;
	printf("%d %d %d\n0 0 0\n", 1 + int rand $n, 2 + int rand $n, 1 + int rand $n)
	' > in
	./main
done
