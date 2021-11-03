#!/usr/bin/perl

for $i (1..(int(rand() * 10) + 5)) {
	if (int(rand() * 10) < 5) {
		print("G");
	} else {
		print("R");
	}
}
print("\n");
