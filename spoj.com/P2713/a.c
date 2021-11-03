#include <stdio.h>
#include <string.h>
#include <math.h>

#define BLKSIZE (350)

struct {
	int all1;
	int size;
	long long sum;
} blk[BLKSIZE];

long long val[100009];

void sss(int l, int r)
{
	int i, j;
	if (!blk[l / BLKSIZE].all1) {
		for (i = l; i <= r && i % BLKSIZE != 0; ++i) {
			int nv = (long long)sqrt(val[i]);
			blk[i / BLKSIZE].sum -= val[i];
			blk[i / BLKSIZE].sum += nv;
			val[i] = nv;
		}
		if (blk[l / BLKSIZE].sum == blk[l / BLKSIZE].size)
			blk[l / BLKSIZE].all1 = 1;
	} else {
		i = ((l - 1) / BLKSIZE + 1) * BLKSIZE;
	}
	for (r -= BLKSIZE; i <= r; i += BLKSIZE)
		if (!blk[i / BLKSIZE].all1) {
			for (j = 0; j < BLKSIZE; ++j) {
				int nv = (long long)sqrt(val[i + j]);
				blk[i / BLKSIZE].sum -= val[i + j];
				blk[i / BLKSIZE].sum += nv;
				val[i + j] = nv;
			}
			if (blk[i / BLKSIZE].size == blk[i / BLKSIZE].sum)
				blk[i / BLKSIZE].all1 = 1;
		}
	r += BLKSIZE;
	if (!blk[r / BLKSIZE].all1) {
		for (; i <= r; ++i) {
			int nv = (long long)sqrt(val[i]);
			blk[i / BLKSIZE].sum -= val[i];
			blk[i / BLKSIZE].sum += nv;
			val[i] = nv;
		}
		if (blk[r / BLKSIZE].size == blk[r / BLKSIZE].sum)
			blk[r / BLKSIZE].all1 = 1;
	}
}

long long qry(int l, int r)
{
	int i;
	long long ans = 0;
	if (blk[l / BLKSIZE].all1) {
		i = ((l - 1) / BLKSIZE + 1) * BLKSIZE;
		if (r + 1 < i)
			i = r + 1;
		ans += i - l;
	} else {
		for (i = l; i <= r && i % BLKSIZE != 0; ++i)
			ans += val[i];
	}
	for (r -= BLKSIZE; i <= r; i += BLKSIZE)
		ans += blk[i / BLKSIZE].sum;
	r += BLKSIZE;
	if (blk[r / BLKSIZE].all1) {
		ans += r - i + 1;
	} else {
		for (; i <= r; ++i)
			ans += val[i];
	}
	return ans;
}

int solve(int n)
{
	int i;
	int m;
	for (i = 0; i < n; ++i) {
		scanf("%lld", &val[i]);
		++blk[i / BLKSIZE].size;
		blk[i / BLKSIZE].sum += val[i];
	}
	scanf("%d", &m);
	while (m--) {
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		--l, --r;
		if (l > r) {
			int t = l;
			l = r;
			r = t;
		}
		if (op == 0)
			sss(l, r);
		else
			printf("%lld\n", qry(l, r));
	}
	return 0;
}

int main(void)
{
	int n;
	int cnt = 1;
	while (scanf("%d", &n) == 1) {
		printf("Case #%d:\n", cnt++);
		memset(blk, 0, sizeof(blk));
		memset(val, 0, sizeof(val));
		solve(n);
		putchar('\n');
	}
	return 0;
}
