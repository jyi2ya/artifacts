#!perl

use v5.12;
use Data::Dumper;
use List::Util qw/first/;

$_ = <>;
my ($n, $m) = split;

my @input;
for (1 .. ($n * $m)) {
	local $_ = <>;
	push @input, $_;
}

$_ = <>;
my ($pos) = /(\d+)/;

my $ans = 0;
for (1 .. $n) {
	my @floor = map { [ (split " ", shift @input), $_ ] } (0 .. ($m - 1));

	$ans = ($ans + $floor[$pos][1]) % 20123;

	my @stairs = grep { $_->[0] } @floor;
	my $steps = $floor[$pos][1];
	until ($floor[$pos][0]) {
		++$pos;
		$pos %= @floor;
	}
	my ($idx) = first { $stairs[$_][2] == $floor[$pos][2] } (0 .. $#stairs);
	$pos = $stairs[($idx + $steps - 1) % @stairs][2];
}

say $ans;
