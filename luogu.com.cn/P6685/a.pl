#!perl

use v5.12;
use Math::BigFloat;

$_ = <>;
my ($n, $m) = split;
Math::BigFloat->accuracy(30);
$n = Math::BigFloat->new($n);
$m = Math::BigFloat->new($m);
my $t = Math::BigFloat->new(1);
$t->bdiv($m);
$n->bpow($t);

say int($n->bstr() + 1e-6);
