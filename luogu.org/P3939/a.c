#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int org[300009];
int sorted[300009];
int *rabit[300009];
int top[300009];

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

#define swap(a, b) \
	do { \
		int t_ = a; \
		a = b; \
		b = t_; \
	} while (0)

int lb(int id, int x)
{
	int l = 0, r = top[id], m;
	while (l < r) {
		m = l + (r - l) / 2;
		if (rabit[id][m] < x)
			l = m + 1;
		else
			r = m;
	}
	return l;
}

int ub(int id, int x)
{
	int l = 0, r = top[id], m;
	while (l < r) {
		m = l + (r - l) / 2;
		if (rabit[id][m] <= x)
			l = m + 1;
		else
			r = m;
	}
	return l;
}

int main(void)
{
	int i;
	int n, m;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
		scanf("%d", &org[i]);
	memcpy(sorted + 1, org + 1, sizeof(int) * n);
	qsort(sorted + 1, n, sizeof(int), cmp);
	for (i = 1; i <= n; ++i)
		if (rabit[sorted[i]] == NULL)
			rabit[sorted[i]] = sorted + i;
	for (i = 1; i <= n; ++i)
		rabit[org[i]][top[org[i]]++] = i;
	for (i = 1; rabit[i] != NULL; ++i)
		qsort(rabit[i], top[i], sizeof(int), cmp);
	while (m--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int l, r, c;
			int bl, br;
			scanf("%d%d%d", &l, &r, &c);
			bl = lb(c, l);
			br = ub(c, r);
			printf("%d\n", br - bl);
		} else {
			int x;
			int a, b;
			int pa, pb;
			scanf("%d", &x);
			a = org[x], b = org[x + 1];
			if (a == b)
				continue;
			org[x + 1] = a, org[x] = b;
			pa = lb(a, x);
			pb = lb(b, x + 1);
			swap(rabit[a][pa], rabit[b][pb]);
		}
	}
	return 0;
}
