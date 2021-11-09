#include <stdio.h>

#define MOD 10007

long long f[1009][1009];
long long ipow(long long a, long long b);

int main(void)
{
	long long i, j;
	long long a, b, k, n, m;
	scanf("%lld%lld%lld%lld%lld", &a, &b, &k, &n, &m);
	for (i = 0; i < 1009; ++i)
		f[i][1] = 1;
	for (i = 1; i < 1009; ++i)
		for (j = 1; j <= i + 1; ++j)
			f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % MOD;
	printf("%lld\n", f[k][n + 1] * ipow(a, n) % MOD * ipow(b, m) % MOD);
	return 0;
}

long long ipow(long long a, long long b)
{
	long long ans = 1;
	while (b) {
		if (b & 1)
			ans = ans * a % MOD;
		a = a * a % MOD;
		b /= 2;
	}
	return ans;
}
