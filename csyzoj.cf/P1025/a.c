/*
 * 组合数 nb 。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD (1000000007LL)

long long llpow(long long a, long long x)
{
	long long ans = 1;
	for (; x; a = a * a % MOD, x /= 2)
		if (x & 1)
			ans = ans * a % MOD;
	return ans;
}

long long llinv(long long x)
{
	return llpow(x, MOD - 2);
}

long long fac[1009], facinv[1009];
long long g[1009];

long long C(int n, int m)
{
	if (n < m || m < 0 || n < 0)
		return 0;
	return fac[n] * facinv[m] % MOD * facinv[n - m] % MOD;
}

int main(void)
{
	int i, j;
	int len;
	long long ans = 0;
	static char n[1009];
	int k;
	scanf("%s%d", n, &k);
	len = strlen(n);
	fac[0] = 1;
	for (i = 1; i <= len; ++i)
		fac[i] = fac[i - 1] * i % MOD;
	facinv[0] = 1;
	for (i = 1; i <= len; ++i)
		facinv[i] = llinv(fac[i]);
	g[1] = 0;
	for (i = 2; i < 1009; ++i) {
		for (j = i; j; j -= (j & -j))
			++g[i];
		g[i] = g[g[i]] + 1;
	}
	for (i = 1; i <= len; ++i)
		if (g[i] == k - 1) {
			int cnt = 0;
			ans = (ans + C(len, i)) % MOD;
			for (j = 0; j < len; ++j) {
				if (n[j] == '1')
					++cnt;
				else
					ans = ((ans - C(len - j - 1, i - cnt - 1)) %
							MOD + MOD) % MOD;
			}
		}
	if (k == 1)
		--ans;
	if (k == 0)
		ans = 1;
	printf("%lld\n", ans);
	return 0;
}
