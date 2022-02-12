#!perl

use v5.12;

$_ = <>;
my @arr = sort { $a <=> $b } split;
my @alp = qw/A B C/;
my %map = (
	map { ( $alp[$_] => $arr[$_] ) } (0 .. 2)
);
chomp($_ = <>);
say join " ", map { $map{$_} } split '';
