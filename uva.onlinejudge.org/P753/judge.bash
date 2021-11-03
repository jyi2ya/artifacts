#!/bin/bash

gcc main.c -o main && g++ std.cpp -o std || exit 1

for i in {1..100}; do
	echo $i
	perl > in <<'EOF'
	$T = 1;
	print "$T\n";
	while ($T--) {
		print "\n";
		$varmax = 20;
		($rec, $eqp, $adp) = (20, 20, 20);
		print "$rec\n";
		printf "%d\n", rand $varmax for (1 .. $rec);
		print "$eqp\n";
		printf "%s %d\n", 'luotianyi', rand $varmax for (1 .. $eqp);
		print "$eqp\n";
		for (1 .. $eqp) {
			$a = int rand $varmax;
			$b = $a;
			while ($b == $a) { $b = int rand $varmax; }
			printf "%d %d\n", $a, $b;
		}
	}
EOF
	./main < in > out
	./std < in > ans
	diff out ans || exit 1
done

rm -f in out ans main std
