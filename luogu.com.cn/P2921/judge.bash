#!/bin/bash

data()
{
	perl <<'EOF'
my $n = 5;
print("$n\n");
for (1 .. $n - 1) {
	printf("%d\n", rand($n - 1) + 1);
}
print("$n\n");
EOF
}

comp()
{
	gcc main.c -o main && gcc std.c -o std
}

comp || exit 1
for i in {1..100}; do
	printf "%s\n" "$i"
	data > in
	./main < in > out
	./std < in > ans
	diff ans out || exit 1
done
