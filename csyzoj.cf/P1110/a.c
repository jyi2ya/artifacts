#include <stdio.h>

#define MOD 1000000007LL

int main(void)
{
	static long long p2[1000009];
	static long long p3[1000009];
	static long long f[1000009][21][3];
	int n;
	int lg;
	int i, j, k;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d", &n);

	p2[0] = 1;
	for (i = 1; i < 1000009; ++i)
		p2[i] = p2[i - 1] * 2 % MOD;
	p3[0] = 1;
	for (i = 1; i < 1000009; ++i)
		p3[i] = p3[i - 1] * 3 % MOD;

	for (lg = 0; (1 << lg) <= n; ++lg);
	--lg;

	f[1][lg][0] = 1;
	if (p2[lg - 1] * 3 <= n)
		f[1][lg - 1][1] = 1;

	for (i = 2; i <= n; ++i)
		for (j = 0; j <= lg; ++j)
			for (k = 0; k < 2; ++k)
				f[i][j][k] = (
					f[i - 1][j][k] * (n / (p2[j] * p3[k]) - (i - 1)) % MOD +
					f[i - 1][j + 1][k] * (n / (p2[j] * p3[k]) - n / (p2[j + 1] * p3[k])) % MOD +
					f[i - 1][j][k + 1] * (n / (p2[j] * p3[k]) - n / (p2[j] * p3[k + 1])) % MOD
					) % MOD;
	printf("%lld\n", f[n][0][0]);
	return 0;
}
