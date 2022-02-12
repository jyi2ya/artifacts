#!/usr/bin/env perl

use v5.12;
use List::Util qw/max sum/;

chomp($_ = <>);
my ($N, $M) = split;
chomp($_ = <>);
my @arr = split;

my ($l, $r) = (0, max(@arr));

while ($l < $r) {
	my $m = $r - int(($r - $l) / 2);
	my $sum = 0;
	for (@arr) {
		$sum +=  $_ - $m if $_ - $m > 0
	}
	if ($sum < $M) {
		$r = $m - 1;
	} else {
		$l = $m;
	}
}

say $l;
