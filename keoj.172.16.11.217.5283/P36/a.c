#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLKSIZE 250

struct blkinfo {
	int delta;
	int size;
	int sorted[BLKSIZE];
};

struct blkinfo blk[BLKSIZE];
int val[50009];

int cmp(const void *a, const void *b)
{
	return *(int*)a < *(int*)b ? -1 : 1;
}

void add(int l, int r, int c)
{
	int i, id, cac;
	cac = ((l - 1) / BLKSIZE + 1) * BLKSIZE;
	for (i = l; i <= r && i != cac; ++i)
		val[i] += c;
	id = l / BLKSIZE;
	memcpy(blk[id].sorted, val + (id) * BLKSIZE, sizeof(int) * blk[id].size);
	qsort(blk[id].sorted, blk[id].size, sizeof(int), cmp);
	for (r -= BLKSIZE, id = i / BLKSIZE; i <= r; i += BLKSIZE, ++id)
		blk[id].delta += c;
	for (r += BLKSIZE; i <= r; ++i)
		val[i] += c;
	id = r / BLKSIZE;
	memcpy(blk[id].sorted, val + (id) * BLKSIZE, sizeof(int) * blk[id].size);
	qsort(blk[id].sorted, blk[id].size, sizeof(int), cmp);
}

int qry(int l, int r, int c)
{
	int i, id, cac;
	int ans = 0;
	cac = ((l - 1) / BLKSIZE + 1) * BLKSIZE;
	for (i = l, id = l / BLKSIZE; i <= r && i != cac; ++i)
		if (val[i] + blk[id].delta < c)
			++ans;
	for (r -= BLKSIZE, id = i / BLKSIZE; i <= r; i += BLKSIZE, ++id) {
		int ll, rr, m;
		ll = 0, rr = blk[id].size;
		while (ll < rr) {
			m = ll + (rr - ll) / 2;
			if (blk[id].sorted[m] + blk[id].delta < c)
				ll = m + 1;
			else
				rr = m;
		}
		ans += ll;
	}
	for (r += BLKSIZE, id = r / BLKSIZE; i <= r; ++i)
		if (val[i] + blk[id].delta < c)
			++ans;
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
		++blk[i / BLKSIZE].size;
	for (i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);
		val[i] = t;
		blk[i / BLKSIZE].sorted[i % BLKSIZE] = t;
	}
	for (i = 0; blk[i].size; ++i)
		qsort(blk[i].sorted, blk[i].size, sizeof(int), cmp);
	while (n--) {
		int op, l, r, c;
		scanf("%d%d%d%d", &op, &l, &r, &c);
		--l, --r;
		if (op == 0)
			add(l, r, c);
		else
			printf("%d\n", qry(l, r, c * c));
	}
	return 0;
}
