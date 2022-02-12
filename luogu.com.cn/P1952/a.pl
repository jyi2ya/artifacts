#!perl

use v5.12;
use List::Util qw/max/;
use Data::Dumper;

$_ = <>; my ($base) = /(\w+)/;
$_ = <>; my ($a) = /(\w+)/;
$_ = <>; my ($b) = /(\w+)/;

my @a = reverse map { /\d/ ? $_ : ord($_) - ord('a') + 10 } split '', $a;
my @b = reverse map { /\d/ ? $_ : ord($_) - ord('a') + 10 } split '', $b;
$a[$_] += $b[$_] for 0 .. max($#a, $#b);
for (0 .. $#a) {
	$a[$_ + 1] += int($a[$_] / $base);
	$a[$_] %= $base;
}
pop @a while $a[$#a] == 0;
say reverse map { $_ <= 9 ? $_ : chr($_ - 10 + ord('a')) } @a;
