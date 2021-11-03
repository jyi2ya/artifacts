#include <stdio.h>

#define MOD 1000000007LL

int main(void)
{
	static long long val[1009];
	static long long num1[20009];
	static long long num2[20009];
	static long long dp1[1009][20009];
	static long long dp2[1009][20009];
	int i, j, k;
	int n;
	long long X;
	long long ans = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%lld", &n, &X);
	for (i = n; i >= 1; --i)
		scanf("%lld%lld%lld", &val[i], &num1[i], &num2[i]);

	dp1[0][0] = 1;
	for (i = 1; i <= n; ++i) {
		for (j = 0; j < val[i] + X; ++j) {
			dp1[i][j] = dp1[i - 1][j];
			for (k = 1; k <= num1[i] && j - k * val[i] >= 0; ++k)
				dp1[i][j] =
					(dp1[i][j] + dp1[i - 1][j - k * val[i]])
					% MOD;
		}
		for (; j < val[1] + X; ++j)
			dp1[i][j] = dp1[i - 1][j];
	}

	dp2[0][0] = 1;
	for (i = 1; i <= n; ++i) {
		for (j = 0; j <= val[1]; ++j)
			for (k = 0; k <= num2[i] && j >= k * val[i]; ++k)
				dp2[i][j] =
					(dp2[i][j] + dp2[i - 1][j - k * val[i]])
					% MOD;
	}
	for (i = X; i - X <= val[1]; ++i)
		ans = (ans + dp1[n][i] * dp2[n][i - X] % MOD) % MOD;
	printf("%lld\n", ans);

	return 0;
}
