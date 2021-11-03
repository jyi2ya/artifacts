#include <stdio.h>

#define MOD (1000000007LL)

long long a[1000009];
long long w[1000009];
long long p[1000009];
int n;

int main(void)
{
	int i;
	long long acc = 0;
	long long ans = 0;

#ifndef ONLINE_JUDGE
	freopen("avg.in", "r", stdin);
#ifndef DEBUG
	freopen("avg.out", "w", stdout);
#endif
#endif

	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf("%lld", &w[i]);
	for (i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	for (i = 1; i <= n; ++i)
		p[i] = p[i - 1] + w[i];
	for (i = 1; i <= (n + 1) / 2; ++i) {
		acc = (acc + p[n - i + 1] - p[i - 1]) % MOD;
		ans = (ans + acc * a[i]) % MOD;
	}
	acc = 0;
	for (i = 1; i <= (n + 1) / 2; ++i) {
		acc = (acc + p[n - i + 1] - p[i - 1]) % MOD;
		ans = (ans + acc * a[n - i + 1]) % MOD;
	}
	if (n & 1)
		ans = (ans - acc * a[(n + 1) / 2] % MOD + MOD) % MOD;
	printf("%lld\n", ans);
	return 0;
}
