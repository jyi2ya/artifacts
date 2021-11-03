#!/usr/bin/perl

$max_num = 1e10;
$n = 100000;
$m = 100000;

print("$n\n");
for (1..$n) {
	printf("%d ", int(rand() * $max_num) + 1);
}
print("\n$m\n");
for (1..$m) {
	$l = int(rand() * $n) + 1;
	$r = int(rand() * $n) + 1;
	if ($l > $r) {
		$t = $l;
		$l = $r;
		$r = $t;
	}

	printf("%d %d %d\n", int(rand() * 2), $l, $r);
}
