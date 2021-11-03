#include <stdio.h>

int t[10009], v[10009], T, M, dp[100009];

int max(int a, int b);

int main(void)
{
	int i, j, ans = 0;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &T, &M);
	for (i = 0; i < M; ++i)
		scanf("%d%d", t + i, v + i);
	for (i = 0; i < M; ++i)
		for (j = t[i]; j <= T; ++j)
			dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
	for (i = 0; i < M; ++i)
		for (j = 0; j <= T; ++j)
			ans = max(ans, dp[j]);
	printf("%d\n", ans);
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
