#include <stdio.h>

int m, v, n;
int a[209], b[209], c[209];
int dp[209][209][209];
int pre[209][209][209], grand[209][209][209];
int buf[209], top;

int max(int a, int b);
int dfs(int pos, int vv, int mm, int nowans);

int main(void)
{
	int i, j, k;
	scanf("%d%d%d", &m, &v, &n);
	for (i = 1; i <= n; ++i)
		scanf("%d%d%d", a + i, b + i, c + i);

	for (i = 1; i <= n; ++i)
		for (j = 1; j <= v; ++j)
			for (k = 1; k <= m; ++k) {
				if (j < b[i] || k < a[i] || dp[i - 1][j][k] >= dp[i - 1][j - b[i]][k - a[i]] + c[i])
					dp[i][j][k] = dp[i - 1][j][k];
				else
					dp[i][j][k] = dp[i - 1][j - b[i]][k - a[i]] + c[i];
			}

	printf("%d\n", dp[n][v][m]);
	for (i = 1; i <= n; ++i) {
		top = 0;
		if (dfs(i, v, m, 0))
			break;
	}
	while (top)
		printf("%d ", buf[--top]);
	putchar('\n');
	return 0;
}

int dfs(int i, int j, int k, int nowans)
{
	if (i > n)
		return nowans == dp[n][v][m];
	if (j >= b[i] && k >= a[i])
		if (dfs(i + 1, j - b[i], k - a[i], nowans + c[i])) {
			buf[top++] = i;
			return 1;
		}
	return dfs(i + 1, j, k, nowans);
}

int max(int a, int b)
{
	return a > b ? a : b;
}
