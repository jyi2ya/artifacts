#!/bin/sh

gen()
{
	perl -e'
use List::Util qw/shuffle/;
use Data::Dumper;
$n = 20;
$name = "absi2010";
@pos = (shuffle (
	("HuFa") x 2, ("ZhangLao") x 4, ("TangZhu") x 7, ("JingYing") x 25,
       	("BangZhong") x 80))[0 .. ($n - 1)];
(@pos[0 .. 2]) = ("BangZhu", ("FuBangZhu") x 2);

print "$n\n";
while ($n--) {
	printf "%s %s %d %d\n", ++$name, shift(@pos),
		int(rand(1000000000)), int(rand(150));
}
'
}

set -e

gcc a.c -o a
g++ std.cpp -o std
while :; do 
	gen > in
	./std < in > ans
	./a < in > out
	diff ans out
done
