#!/usr/bin/perl -w

$n = 6;

print("$n ");
for ($i = 0; $i < $n; ++$i) {
	printf("%d %d ", int(rand() * 2) + 1, int(rand() * 100));
}
print("\n");
