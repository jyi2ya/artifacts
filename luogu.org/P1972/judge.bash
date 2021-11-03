#!/bin/bash

data()
{
	perl <<'EOF'
$n = 5000;
$EMAX = 1000000;
$m = 50000;

print("$n\n");
for (1..$n) {
	printf("%d ", rand($EMAX));
}
print("\n$m\n");
for (1..$m) {
	$l = int(rand($n) + 1), $r = int(rand($n) + 1);
	if ($l > $r) {
		($l, $r) = ($r, $l);
	}
	printf("%d %d\n", $l, $r);
}
EOF
}

comp()
{
	gcc main.c -o main && g++ o.cpp -o std
}

comp || exit 1
data > in
./main < in > out
./std < in > ans
while diff out ans; do
	data > in
	./main < in > out
	./std < in > ans
done
diff -u out ans > result.diff
exit 1
