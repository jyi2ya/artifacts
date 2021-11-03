#include <stdio.h>
#include <math.h>

#define BLKSIZE (233)

struct {
	int all1;
	int size;
	long long sum;
} blk[BLKSIZE];

long long val[50009];

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

int main(void)
{
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%lld", &val[i]);
		++blk[i / BLKSIZE].size;
		blk[i / BLKSIZE].sum += val[i];
	}
	while (n--) {
		int op, l, r, c;
		scanf("%d%d%d%d", &op, &l, &r, &c);
		--l, --r;
		if (op == 0)
			sss(l, r);
		else
			printf("%lld\n", qry(l, r));
	}
	return 0;
}
