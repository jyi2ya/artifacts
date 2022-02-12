#!/usr/bin/env perl

use v5.12;

sub fill
{
	my ($y, $x, $size, $hy, $hx) = @_;
	my $carpid;
	--$size;
	my $s = 1 << $size;
	for ([0, 0], [0, 1], [1, 0], [1, 1]) {
		if (
			$y + $_->[0] * $s <= $hy and
			$hy < $y + $_->[0] * $s + $s and
			$x + $_->[1] * $s <= $hx and
			$hx < $x + $_->[1] * $s + $s
		) {
			$carpid = $_->[0] * 2 + $_->[1] + 1;
			printf "%d %d %d\n",
			$y + $s - $_->[0] + 1,
			$x + $s - $_->[1] + 1,
			$carpid;
			last;
		}
	}

	return if $size == 0;

	fill($y, $x, $size, $y + $s - 1, $x + $s - 1) unless $carpid == 1;
	fill($y, $x + $s, $size, $y + $s - 1, $x + $s) unless $carpid == 2;
	fill($y + $s, $x, $size, $y + $s, $x + $s - 1) unless $carpid == 3;
	fill($y + $s, $x + $s, $size, $y + $s, $x + $s) unless $carpid == 4;
	fill($y, $x, $size, $hy, $hx) if $carpid == 1;
	fill($y, $x + $s, $size, $hy, $hx) if $carpid == 2;
	fill($y + $s, $x, $size, $hy, $hx) if $carpid == 3;
	fill($y + $s, $x + $s, $size, $hy, $hx) if $carpid == 4;
}

chomp(my $k = <>);
$_ = <>;
my ($yy, $xx) = split;
--$xx; --$yy;
fill(0, 0, $k, $yy, $xx);
