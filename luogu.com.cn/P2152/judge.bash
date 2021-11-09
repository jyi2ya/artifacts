#!/bin/bash

data()
{
	perl <<'EOF'
$a = 5;
$b = 5;
printf("%d", rand(9) + 1);
for (2..$a) {
	printf("%d", rand(10));
}
print("\n");
printf("%d", rand(9) + 1);
for (2..$b) {
	printf("%d", rand(10));
}
print("\n");
EOF
}

data > in
./main < in > out
./std < in > ans
while diff ans out; do
	data > in
	./main < in > out
	./std < in > ans
done
