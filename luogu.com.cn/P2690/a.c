#include <stdio.h>

int id[1009];
int dp[1009][39]; /* dp[range][move] */

int max(int a, int b);

int main(void)
{
	int T, W, i, j, ans = 0;
	scanf("%d%d", &T, &W);
	for (i = 0; i < T; ++i)
		scanf("%d", id + i);
	dp[0][0] = (id[0] == 1) ? 1 : 0;
	dp[0][1] = (id[0] == 1) ? 0 : 1;
	for (i = 1; i < T; ++i)
		for (j = 0; j <= W; ++j) {
			int now = (j & 1) ? 2 : 1;
			dp[i][j] = 0;
			dp[i][j] = max(dp[i - 1][j], dp[i][j]);
			if (j)
				dp[i][j] = max(dp[i - 1][j - 1], dp[i][j]);
			dp[i][j] += (now == id[i]) ? 1 : 0;
		}
	for (i = 0; i < T; ++i)
		for (j = 0; j <= W; ++j)
			ans = max(ans, dp[i][j]);
	printf("%d\n", ans);
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
