#!/usr/bin/perl

use strict;
use warnings;

my @flw = ();
my @vis = ();

while (<>) {
	my @arr = split(' ');
	if ($arr[0] == 1) {
		next if ($vis[$arr[2]]);
		$vis[$arr[2]] = 1;
		push(@flw, [ $arr[1], $arr[2] ]);
	} elsif ($arr[0] == 2) {
		next unless (@flw);
		@flw = sort({ $a->[1] <=> $b->[1] } @flw);
		$vis[pop(@flw)->[1]] = 0;
	} elsif ($arr[0] == 3) {
		next unless (@flw);
		@flw = sort({ $a->[1] <=> $b->[1] } @flw);
		$vis[shift(@flw)->[1]] = 0;
	} else {
		last;
	}
}

my ($wc, $cc) = (0, 0);

for my $i (@flw) {
	$wc += $i->[0];
	$cc += $i->[1];
}

print("$wc $cc\n");
