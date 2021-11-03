#include <stdio.h>

#define BLKSIZE 250

struct blkinfo {
	int delta;
};

struct blkinfo blk[50009];
int val[50009];

void add(int l, int r, int c)
{
	for (; l <= r && l % BLKSIZE != 0; ++l)
		val[l] += c;
	for (r -= BLKSIZE; l <= r; l += BLKSIZE)
		blk[l / BLKSIZE].delta += c;
	for (r += BLKSIZE; l <= r; ++l)
		val[l] += c;
}

int query(int pos)
{
	return val[pos] + blk[pos / BLKSIZE].delta;
}

int main(void)
{
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);
		add(i, i, t);
	}
	while (n--) {
		int op, l, r, c;
		scanf("%d%d%d%d", &op, &l, &r, &c);
		if (op == 0)
			add(l - 1, r - 1, c);
		else
			printf("%d\n", query(r - 1));
	}
	return 0;
}
