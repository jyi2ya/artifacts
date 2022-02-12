#!/usr/bin/perl

use v5.12;
use Data::Dumper;

$_ = <>;
my ($L, $n, $M) = (/(\d+)\s+(\d+)\s+(\d+)/);
my @arr = map { int(<>) } (1 .. $n);
unshift @arr, 0;
push @arr, $L;
my ($l, $r) = (0, $L);

while ($l < $r) {
	my $m = $r - int(($r - $l) / 2);

	my $ok = 1;
	my $cnt = 0;

	my ($i, $j);
	for ($i = 0; $i < @arr - 1; $i = $j) {
		for ($j = $i + 1; $j < @arr; ++$j) {
			last if $arr[$j] - $arr[$i] >= $m;
		}

		if ($j == @arr) {
			$ok = 0;
			last;
		}

		$cnt += ($j - $i - 1);
		if ($cnt > $M) {
			$ok = 0;
			last;
		}
	}

	if ($ok) {
		$l = $m;
	} else {
		$r = $m - 1;
	}
}

say $l;
