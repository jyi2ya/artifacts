#!/usr/bin/env perl

use v5.12;
use bigint;
use List::Util qw/max/;

$_ = <>;
my ($m, $n) = split;

my @arr;
$arr[$m] = 1;
$arr[$_] += $arr[max 0, $_ - 1] + $arr[max 0, $_ - 2] for $m .. $n;
say $arr[$n];
