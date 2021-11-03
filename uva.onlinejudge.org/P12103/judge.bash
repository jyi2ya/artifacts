#!/bin/bash

gcc main.c -o main && g++ std.cpp -o std || exit 1
for i in {1..100}; do
	echo $i
	perl > in <<'EOF'
	use List::Util;
	my $t = 1;
	print("$t\n");
	print(join("", List::Util::shuffle(A .. Z)) . "\n") for (1 .. $t);
EOF
	./main < in > out
	./std < in > ans
	diff out ans || exit 1
done
rm -f main std in out ans
