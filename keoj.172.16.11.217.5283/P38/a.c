#include <stdio.h>
#include <stdlib.h>

div_t D[50009];

#define BLKSIZE (233)

long long val[50009];

struct {
	long long sum;
	long long add;
	int size;
} blk[BLKSIZE];

void add(int l, int r, int c)
{
	int i;
	for (i = l; i <= r && i % BLKSIZE != 0; ++i) {
		val[i] += c;
		blk[i / BLKSIZE].sum += c;
	}
	for (r -= BLKSIZE; i <= r; i += BLKSIZE) {
		blk[i / BLKSIZE].sum += (c * blk[i / BLKSIZE].size);
		blk[i / BLKSIZE].add += c;
	}
	for (r += BLKSIZE; i <= r; ++i) {
		val[i] += c;
		blk[i / BLKSIZE].sum += c;
	}
}

long long qry(int l, int r, int c)
{
	int i;
	long long ans = 0;
	for (i = l; i <= r && i % BLKSIZE != 0; ++i)
		ans = (ans + val[i] + blk[i / BLKSIZE].add) % c;
	for (r -= BLKSIZE; i <= r; i += BLKSIZE)
		ans = (ans + blk[i / BLKSIZE].sum) % c;
	for (r += BLKSIZE; i <= r; ++i)
		ans = (ans + val[i] + blk[i / BLKSIZE].add) % c;
	return ans;
}

int main(void)
{
	int n;
	int i;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%lld", &val[i]);
	for (i = 0; i < n; ++i) {
		++blk[i / BLKSIZE].size;
		blk[i / BLKSIZE].sum += val[i];
	}
	while (n--) {
		int op, l, r, c;
		scanf("%d%d%d%d", &op, &l, &r, &c);
		--l, --r;
		if (op == 0)
			add(l, r, c);
		else
			printf("%lld\n", qry(l, r, c + 1));
	}
	return 0;
}
