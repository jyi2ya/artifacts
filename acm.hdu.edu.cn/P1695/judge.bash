#!/bin/bash

data()
{
	awk -v seed=$((RANDOM << 16 | RANDOM)) -e '
#!/bin/awk -f

BEGIN {
	t = 3000;
	nmax = 1000;
	kmax = 1000;

	srand(seed);

	printf("%d\n", t);
	for (i = 0; i < t; ++i) {
		a = 1;
		b = rand() * nmax + 1;
		c = 1;
		d = rand() * nmax + 1;
		if (c > d) {
			T = c;
			c = d;
			d = T;
		}
		if (a > b) {
			T = a;
			a = b;
			b = T;
		}
		printf("%d %d %d %d %d\n", a, b, c, d, rand() * kmax + 1);
	}
}
'
}

comp()
{
	gcc main.c -o main && gcc std.c -o std
}

clean()
{
	rm -f main std in out ans
}

clean

comp || exit 1

for i in {1..100}; do
	echo $i
	data > in
	./main < in > out
	./std < in > ans
	diff out ans || exit 1
done

clean
