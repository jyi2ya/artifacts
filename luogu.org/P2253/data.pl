#!/usr/bin/perl -w

$N = 3;
$M = 5;

print("$N $M\n");
for (1..$M) {
	printf("%d\n", int(rand() * $N) + 1);
}
