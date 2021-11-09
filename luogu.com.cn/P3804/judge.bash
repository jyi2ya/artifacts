#!/bin/bash

set -e

data()
{
	perl -e 'print chr(ord("a") + int rand 26) for (1 .. 1000000)';
}

comp()
{
	gcc main.c -o main && g++ std.cpp -o std
}

comp
for i in {1..100}; do
	echo $i
	data > in
	time ./std < in > ans
	time ./main < in > out
	diff out ans
done
