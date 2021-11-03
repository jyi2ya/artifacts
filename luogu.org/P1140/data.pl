#!/usr/bin/perl -w

$MAX = 10;

$n = int(rand() * ($MAX - 5) + 5);
print("$n ");
for $i (1..$n) {
	$rd = int(rand() * 4);
	if ($rd == 0) {
		print('A');
	} elsif ($rd == 1) {
		print('C');
	} elsif ($rd == 2) {
		print('G');
	} elsif ($rd == 3) {
		print('T');
	}
}
print("\n");

$n = int(rand() * ($MAX - 5) + 5);
print("$n ");
for $i (1..$n) {
	$rd = int(rand() * 4);
	if ($rd == 0) {
		print('A');
	} elsif ($rd == 1) {
		print('C');
	} elsif ($rd == 2) {
		print('G');
	} elsif ($rd == 3) {
		print('T');
	}
}
print("\n");
