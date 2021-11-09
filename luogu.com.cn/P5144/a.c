#include <stdio.h>

int S[1009], E[1009][1009], dp[1009][1009], n, m;

int max(int a, int b);

int main(void)
{
	int i, j, k;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
		scanf("%d", S + i);
	for (i = 1; i <= n; ++i) {
		E[i][i] = S[i];
		for (j = i + 1; j <= n; ++j)
			E[i][j] = E[i][j - 1] ^ S[j];
	}

	for (i = 1; i <= n; ++i) {
		dp[i][0] = E[1][i];
		for (j = 1; j < m; ++j)
			for (k = 1; k <= i; ++k)
				dp[i][j] = max(dp[i][j], dp[i - k][j - 1] + E[i - k + 1][i]);
	}
	printf("%d\n", dp[n][m - 1]);
	return 0;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
