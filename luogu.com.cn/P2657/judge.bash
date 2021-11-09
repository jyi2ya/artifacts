#!/bin/bash

while true; do
	#a=$((${RANDOM}${RANDOM} % 1000 + 1))
	#b=$((${RANDOM}${RANDOM} % 1000 + 1))
	a=${RANDOM}
	b=${RANDOM}

	if [ $a -gt $b ]; then
		t=$a;
		a=$b;
		b=$t;
	fi

	echo $a $b > in

	./o > ans
	./main > out
	diff ans out || break;
done
