#!/bin/bash

data()
{
	perl <<'EOF'
$n = 100000;
print("$n\n");
for (1..$n) {
	printf("%d ", int(rand() * 8 + 1));
}
print("\n");
EOF
}

./data.pl > in
./main > out
./o > ans

while diff -Z out ans; do
	./data.pl > in
	./main > out
	./o > ans
done
