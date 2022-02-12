#!/usr/bin/perl

use v5.12;
use Data::Dumper;
use List::Util qw/first/;

my $len = <>;
my @second = grep { /\w+/ } split '', <>;
my $pos = <>;
my @first = sort { $a cmp $b } @second;
my @chr_pairs = map { [ $first[$_], $second[$_] ] } (0 .. $#first);
my %stk;
push @{$stk{$first[$_]}}, $second[$_] for (0 .. $#first);
my $head_chr = (first { $_->[0] eq $second[$pos - 1] } @chr_pairs)->[1];
my $ans;
my $cur = $head_chr;
for (1 .. $len) {
	$ans .= $cur;
	$cur = pop @{$stk{$cur}};
}

say scalar reverse $ans;
