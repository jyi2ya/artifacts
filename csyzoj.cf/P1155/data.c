#include <stdio.h>
#include <stdlib.h>

int lson[3000009], rson[3000009];
int Q[30000009];
int top, bot;

/* [l, r] */
int generate(int l, int r)
{
	int rt;
	if (l == r)
		return l;
	if (l > r)
		return 0;
	rt = l + rand() % (r - l + 1);
	lson[rt] = generate(l, rt - 1);
	rson[rt] = generate(rt + 1, r);
	return rt;
}

int main(int argc, char *argv[])
{
	int size;
	int rt;
	if (argc < 3)
		return 1;
	srand(atoi(argv[1]));
	size = atoi(argv[2]);
	rt = generate(1, size);
	Q[top++] = rt;
	printf("%d\n", size);
	while (top != bot) {
		int c = Q[bot++];
		printf("%d ", c);
		if (lson[c])
			Q[top++] = lson[c];
		if (rson[c])
			Q[top++] = rson[c];
	}
	putchar('\n');
	return 0;
}
