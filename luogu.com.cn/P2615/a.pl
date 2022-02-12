#!perl

use v5.12;

chomp(my $N = <>);
my @pos = ( [ -1, -1 ] );
my @num = ();

$num[1][($N + 1) / 2] = 1;
push @pos, [ 1, ($N + 1) / 2 ];
for (2 .. $N * $N) {
	my $l = $_ - 1;
	if ($pos[$l][0] == 1 && $pos[$l][1] != $N) {
		$num[$N][$pos[$l][1] + 1] = $_;
		push @pos, [ $N, $pos[$l][1] + 1 ];
	} elsif ($pos[$l][1] == $N && $pos[$l][0] != 1) {
		$num[$pos[$l][0] - 1][1] = $_;
		push @pos, [ $pos[$l][0] - 1, 1 ];
	} elsif ($pos[$l][0] == 1 && $pos[$l][1] == $N) {
		$num[$pos[$l][0] + 1][$pos[$l][1]] = $_;
		push @pos, [ $pos[$l][0] + 1, $pos[$l][1] ];
	} else {
		if (defined($num[$pos[$l][0] - 1][$pos[$l][1] + 1])) {
			$num[$pos[$l][0] + 1][$pos[$l][1]] = $_;
			push @pos, [ $pos[$l][0] + 1, $pos[$l][1] ];
		} else {
			$num[$pos[$l][0] - 1][$pos[$l][1] + 1] = $_;
			push @pos, [ $pos[$l][0] - 1, $pos[$l][1] + 1 ];
		}
	}
}

for (1 .. $N) {
	my @t = @{$num[$_]};
	shift @t;
	say join " ", @t;
}
