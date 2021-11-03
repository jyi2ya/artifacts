#!/usr/bin/perl -w

$size = 1e6;

for (1..$size) {
	print(chr(int(rand() * 26) + ord('a')));
}
print("\n");
