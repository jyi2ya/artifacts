#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

void solve(void)
{
	int i, j, k;
	int n, m;
	int ans = 0;
	static int val[1009];
	static int xorsum[1009][1009];
	static int dp[1009];

	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i)
		scanf("%d", &val[i]);

	/*
	printf("n = %d, m = %d\n", n, m);
	for (i = 0; i < n; ++i) {
		int x = val[i];
		printf("%d: ", x);
		for (j = 4; j >= 0; --j)
			printf("%d", x >> j & 1);
		putchar('\n');
	}
	*/

	for (i = 0; i < n; ++i)
		xorsum[i][i] = val[i];
	for (i = 0; i < n; ++i)
		for (j = i + 1; j < n; ++j)
			xorsum[i][j] = xorsum[i][j - 1] ^ val[j];
	for (i = 30; i >= 0; --i) {
		memset(dp, 0, sizeof(dp));
		for (j = 0; j < n; ++j) {
			if ((xorsum[0][j] & ans) >= ans &&
				(xorsum[0][j] >> i & 1))
				dp[j] = 1;
			for (k = 0; k < j; ++k)
				if (dp[k])
				if ((xorsum[k + 1][j] & ans) >= ans &&
					(xorsum[k + 1][j] >> i & 1))
					dp[j] = max(dp[j], dp[k] + 1);
		}

		if (dp[n - 1] >= m)
			ans |= 1 << i;

		/*
		if (i < 5) {
			printf("dp %d: ", i);
			for (j = 0; j < n; ++j)
				printf("%d ", dp[j]);
			putchar('\n');
		}
		*/
	}
	printf("%d\n", ans);
}

int main(void)
{
	int q;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d", &q);
	while (q--)
		solve();
	return 0;
}
