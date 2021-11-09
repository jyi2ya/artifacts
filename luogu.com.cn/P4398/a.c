#include <stdio.h>
#include <stdlib.h>

#define B1 (1323LL)
#define B2 (2333LL)
#define MOD (20030601523LL)

long long mtx[2][59][59];
int n;

long long get_hsh(int k, int i, int j, int siz)
{
	long long ans = 0;
	int u, v;

	for (u = i; u < i + siz; ++u) {
		long long lans = 0;
		for (v = j; v < j + siz; ++v)
			lans = (lans * B1 + mtx[k][u][v]) % MOD;
		ans = (ans * B2 + lans) % MOD;
	}

	return ans;
}

int cmp(const void *a, const void *b)
{
	long long p = *(long long *)a;
	long long q = *(long long *)b;
	if (p == q)
		return 0;
	return p < q ? -1 : 1;
}

int has_mtx(int siz)
{
	int i, j;
	int top = 0;
	static long long hsh[2559];
	for (i = 0; i + siz <= n; ++i)
		for (j = 0; j + siz <= n; ++j)
			hsh[top++] = get_hsh(0, i, j, siz);
	qsort(hsh, top, sizeof(hsh[0]), cmp);
	for (i = 0; i + siz <= n; ++i)
		for (j = 0; j + siz <= n; ++j) {
			long long tmp = get_hsh(1, i, j, siz);
			if (bsearch(&tmp, hsh, top, sizeof(hsh[0]), cmp) != NULL)
				return 1;
		}
	return 0;
}

int main(void)
{
	int i, j, k;
	int l, r;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (k = 0; k < 2; ++k)
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				scanf("%lld", &mtx[k][i][j]);
	l = 1, r = n + 1;
	while (l < r) {
		int m = l + (r - l) / 2;
		if (has_mtx(m))
			l = m + 1;
		else
			r = m;
	}
	printf("%d\n", l - 1);
	return 0;
}
