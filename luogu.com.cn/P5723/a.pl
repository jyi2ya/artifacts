#!perl

use v5.12;

my @isprime;
my @primes;

chomp(my $L = <>);

$isprime[$_] = 1 for 2 .. 1e6;
for my $t (2 .. 1e6) {
	if ($isprime[$t]) {
		push @primes, $t;
		for (my $i = $t * 2; $i < 1e6; $i += $t) {
			$isprime[$i] = 0;
		}
	}
}

my $acc = 0;
my @num;
for (@primes) {
	$acc += $_;
	push @num, $_;
	if ($acc > $L) {
		$acc -= $_;
		pop @num;
		last;
	}
}

say join "\n", @num if @num;
say scalar @num;
