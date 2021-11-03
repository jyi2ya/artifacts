#!/bin/bash

data()
{
	perl <<'EOF'
$n = 1000;
$m = 1000;
$nmax = 1000;
print("$n\n");
for (1..$n) {
	printf("%d ", rand($nmax));
}
print("\n$m\n");
for (1..$m) {
	$op = int(rand(3) + 1);
	print("$op ");
	if ($op == 1) {
		printf("%d\n", rand($n) + 1);
	} elsif ($op == 2) {
		printf("%d %d\n", rand($n) + 1, rand($nmax));
		++$n;
	} else {
		printf("%d\n", rand($n) + 1);
		--$n;
	}
}
EOF
}

compile()
{
	g++ std.cpp -o std && gcc main.c -o main
}

compile || exit 1
while
	data > in
	./main < in > out
	./std < in > ans

	diff out ans
do :; done
