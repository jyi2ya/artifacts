#!/bin/sh

set -e
cnt=0
gcc -O2 std.c -o std
while :; do
	cnt=$((cnt + 1))
	[ $(($cnt % 100)) -eq 0 ] && {
		echo $cnt
	}
	perl d.pl > data.in
	./std < data.in > data.ans
	perl a.pl < data.in > data.out
	diff data.out data.ans
done
