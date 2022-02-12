#!perl

use v5.12;
use Data::Dumper;

$_ = <>;
my ($n, $m) = split;
my @map;
for my $i (1 .. $n) {
	chomp($_ = <>);
	$map[$i] = [ ('?', split'') ];
}

my @vis;
my @que;
my $ans = 0;
for my $i (1 .. $n) {
	for my $j (1 .. $m) {
		unless ($vis[$i][$j] or $map[$i][$j] ne 'W') {
			++$ans;
			push @que, [ $i, $j ];
			$vis[$i][$j] = 1;
			while (@que) {
				my ($y, $x) = @{shift @que};
				for my $p (-1 .. 1) {
					for my $q (-1 .. 1) {
						unless ($vis[$y + $p][$x + $q] or $map[$y + $p][$x + $q] ne 'W') {
							push @que, [ $y + $p, $x + $q ];
							$vis[$y + $p][$x + $q] = 1;
						}
					}
				}
			}
		}
	}
}

say $ans;
