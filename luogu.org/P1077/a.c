#include <stdio.h>

int dp[109][109];
int a[109];

int main(void)
{
	int i, j, n, m, k, MOD = 1000007;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
		scanf("%d", a + i);
	
	for (i = 0; i <= a[n]; ++i)
		dp[n][i] = 1;

	for (i = n; i >= 1; --i)
		for (j = 0; j <= m; ++j)
			for (k = 0; k <= a[i] && k <= j; ++k)
				dp[i][j] = (dp[i][j] + dp[i + 1][j - k]) % MOD;

	printf("%d\n", dp[1][m]);
	return 0;
}
