#!/bin/bash

data()
{
	perl <<'EOF'
my $str;
$str .= chr(rand(26) + ord('a')) for (1 .. 250);
$str .= reverse($str);
print("$str\n");
EOF
}

comp()
{
	gcc std.c -o std && gcc main.c -o main
}

comp || exit 1

for i in {1..100}; do
	printf "%s\n" "$i"
	data > in
	./main < in > out
	./std < in > ans
	diff out ans || break
done
