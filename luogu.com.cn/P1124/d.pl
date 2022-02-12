#!/usr/bin/env perl

use v5.12;

my $len = 10000;
my $str = join '', map { chr(int(rand(26)) + ord('a')) } (1 .. $len);

# say '==== str ====';
# say $str;

# say '==== strings ====';

my $dup_str = $str x 2;
my @strs = map { substr($dup_str, $_, length($str)) } (0 .. (length($str) - 1));

# say join "\n", @strs;

# say '==== sorted ====';

my @sorted = map { $_->[0] }
sort {
	substr($a->[0], 0, 1) cmp substr($b->[0], 0, 1) or $a->[1] <=> $b->[1]
} map { [ $strs[$_], $_ ] } (0 .. $#strs);

# say join "\n", @sorted;

# say '==== last chr ====';

say length $str;

say join '', (map { substr($_, -1, 1) } @sorted);

# say '==== pos ====';

say (grep { my $tmp = $sorted[$_ - 1]; $tmp =~ s/(.*)(.)/$2$1/; $tmp eq $str } (1 .. @sorted));
