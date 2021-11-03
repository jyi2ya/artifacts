#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD (1000000007LL)

int val[100009];
int tmp[100009];
int cnt[100009];
long long fac[100009];
int n;

int cmp(const void *a, const void *b)
{
	return *(int *)a < *(int *)b ? -1 : 1;
}

int id(int x)
{
	int l = 0, r = n, m;
	while (l < r) {
		m = l + (r - l) / 2;
		if (tmp[m] < x)
			l = m + 1;
		else
			r = m;
	}
	return l;
}

void gao(void)
{
	int i;
	memcpy(tmp, val, sizeof(tmp));
	qsort(tmp, n, sizeof(tmp[0]), cmp);
	for (i = 0; i < n; ++i)
		val[i] = id(val[i]);
}

int main(void)
{
	int i;
	long long ans1, ans2;
	long long acc = 0;

#ifndef ONLINE_JUDGE
	freopen("poker.in", "r", stdin);
#ifndef DEBUG
	freopen("poker.out", "w", stdout);
#endif
#endif

	scanf("%d", &n);

	fac[0] = 1;
	for (i = 1; i <= n; ++i)
		fac[i] = fac[i - 1] * i % MOD;

	for (i = 0; i < n; ++i)
		scanf("%d", &val[i]);
	gao();
	for (i = 0; i < n; ++i)
		++cnt[val[i]];
	acc = 0;
	ans1 = 0;
	for (i = 0; i <= n; ++i) {
		ans1 += acc * cnt[i];
		acc += cnt[i];
	}
	ans1 = (ans1 * fac[n - 2]) % MOD;
	ans1 = (ans1 * n / 2) % MOD;
	ans2 = ((n / 2) * fac[n] % MOD - ans1 + MOD) % MOD;
	printf("%lld %lld\n", ans1, ans2);
	return 0;
}
