#!/usr/bin/env perl

use v5.12;
use Data::Dumper;
use List::Util qw/sum any/;

<>;
$_ = <>;
my @arr = split;
my @mine = ();
my @test = ();

if (@arr == 1) {
	say($arr[0] == 1 ? 1 : 0);
	exit;
}

@test = $arr[0] == 0 ? ([0, 0]) :
$arr[0] == 1 ? ([1, 0], [0, 1]) :
([1, 1]);

my $ans = 0;

for (@test) {
	@mine[0, 1] = @$_;
	for (1 .. ($#arr - 1)) {
		$mine[$_ + 1] = $arr[$_] - sum(@mine[$_, $_ - 1]);
	}

	++$ans unless (
		(any { $_ != 0 && $_ != 1 } @mine) or
		($arr[$#arr] != sum @mine[$#arr, $#arr - 1])
	);
}

say $ans;
