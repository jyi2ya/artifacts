#!/bin/bash

set -e
g++ std.cpp -o std
gcc data.c -o data
p=A
g++ main.c -o $p
for i in {1..100}; do
	echo $i
	./data $RANDOM$RANDOM 100000 > $p.in
	./std
	mv $p.{out,ans}
	timeout 1 ./$p
	diff $p.{out,ans}
done

rm -f $p.{in,out,ans} $p std data main
