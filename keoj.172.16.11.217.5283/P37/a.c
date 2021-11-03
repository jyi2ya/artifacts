#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*
#define BLKSIZE (323)
*/
#define MAX_BLK_SIZE (323)

int BLKSIZE;

div_t D[100009];

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

void div_init(int n)
{
	int i;
	for (i = 0; i < n; ++i)
		D[i] = div(i, BLKSIZE);
}

struct blkinfo {
	int size;
	int add;
	int org[MAX_BLK_SIZE];
	int sorted[MAX_BLK_SIZE];
} blk[MAX_BLK_SIZE];

void blk_add(int l, int r, int c)
{
	int i;
	for (i = l; i <= r && D[i].rem != 0; ++i)
		blk[D[i].quot].org[D[i].rem] += c;
	memcpy(blk[D[l].quot].sorted, blk[D[l].quot].org, sizeof(int) * blk[D[l].quot].size);
	qsort(blk[D[l].quot].sorted, blk[D[l].quot].size, sizeof(int), cmp);
	for (r -= BLKSIZE; i <= r; i += BLKSIZE)
		blk[D[i].quot].add += c;
	for (r += BLKSIZE; i <= r; ++i)
		blk[D[i].quot].org[D[i].rem] += c;
	memcpy(blk[D[r].quot].sorted, blk[D[r].quot].org, sizeof(int) * blk[D[r].quot].size);
	qsort(blk[D[r].quot].sorted, blk[D[r].quot].size, sizeof(int), cmp);
}

int blk_qry(int l, int r, int c)
{
	int i;
	int ans = -1;
	int cac;
	for (i = l; i <= r && D[i].rem != 0; ++i) {
		cac = blk[D[i].quot].org[D[i].rem] + blk[D[i].quot].add;
		if (ans < cac && cac < c)
			ans = cac;
	}
	for (r -= BLKSIZE; i <= r; i += BLKSIZE) {
		int ll = 0, rr = blk[D[i].quot].size, m;
		cac = D[i].quot;
		while (rr > ll) {
			m = ll + (rr - ll) / 2;
			if (blk[cac].sorted[m] + blk[cac].add < c)
				ll = m + 1;
			else
				rr = m;
		}
		if (ll == blk[cac].size || blk[cac].sorted[ll] + blk[cac].add >= c)
			--ll;
		if (ll >= 0) {
			cac = blk[cac].sorted[ll] + blk[cac].add;
			if (ans < cac && cac < c)
				ans = cac;
		}
	}
	for (r += BLKSIZE; i <= r; ++i) {
		cac = blk[D[i].quot].org[D[i].rem] + blk[D[i].quot].add;
		if (ans < cac && cac < c)
			ans = cac;
	}
	return ans;
}

int readint(void)
{
	int ch;
	int ans = 0;
	int lt0 = 0;
	while (!isdigit(ch = getchar()) && ch != '-');
	if (ch == '-')
		lt0 = 1;
	else
		ans = ch - '0';
	while (isdigit(ch = getchar()))
		ans = ans * 10 + ch - '0';
	if (lt0)
		return -ans;
	return ans;
}

int main(void)
{
	int n;
	int i, j;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	n = readint();
	BLKSIZE = (int)ceil(sqrt(n) + 5);
	div_init(n);
	for (i = 0; i < n; ++i)
		blk[D[i].quot].org[D[i].rem] = readint();
	for (i = 0; i < n; ++i)
		++blk[D[i].quot].size;
	for (i = 0; blk[i].size; ++i) {
		memcpy(blk[i].sorted, blk[i].org, sizeof(int) * blk[i].size);
		qsort(blk[i].sorted, blk[i].size, sizeof(int), cmp);
	}
	for (j = 0; j < n; ++j) {
		int op, l, r, c;
		op = readint();
		l = readint();
		r = readint();
		c = readint();
		--l, --r;
		if (op == 0)
			blk_add(l, r, c);
		else
			printf("%d\n", blk_qry(l, r, c));
	}
	return 0;
}
