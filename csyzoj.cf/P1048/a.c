#include <stdio.h>
#include <string.h>

long long min(long long a, long long b)
{
	return a < b ? a : b;
}

void solve(void)
{
	long long n, k;
	long long i, j;
	static long long a[1009], p[1009], t[1009];
	static long long dp[10009]; /* dp[i]：分数为 i 的最早时间 */
	scanf("%lld%lld", &n, &k);
	for (i = 0; i < n; ++i)
		scanf("%lld%lld%lld", &a[i], &p[i], &t[i]);
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (i = 0; i <= k; ++i)
		for (j = 0; j < n; ++j)
			if (i >= a[j])
				dp[min(k, i + p[j])] = min(
					dp[min(k, i + p[j])], dp[i] + t[j]
					);
	printf("%lld\n", dp[k]);
}

int main(void)
{
	int T;

#ifndef ONLINE_JUDGE
	freopen("frenzy.in", "r", stdin);
#ifndef DEBUG
	freopen("frenzy.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
