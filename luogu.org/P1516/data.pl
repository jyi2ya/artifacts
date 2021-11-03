#!/usr/bin/perl -w

$L = int(rand() * 10000) + 1;
$x = 0, $y = 0;
while ($x == $y) {
	$x = int(rand() * $L) + 1;
	$y = int(rand() * $L) + 1;
}
$m = int(rand() * $L) + 1;
$n = int(rand() * $L) + 1;

print("$x $y $m $n $L\n");
