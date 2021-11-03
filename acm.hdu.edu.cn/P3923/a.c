/*
 * 题意
 * ====
 * 一个环有 n 个点，最多可以使用 m 种颜色进行染色。旋转和翻转相同的环视作同样的
 * 环。求本质不同的染色方案数。
 *
 * 祼题……直接 Polya 计数就成。
 */
#include <stdio.h>

#define MOD 1000000007

long long llpow(long long a, long long b)
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

long long inv(long long x)
{
	return llpow(x, MOD - 2);
}

long long gcd(long long a, long long b)
{
	while (b) {
		long long t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main(void)
{
	int s, c;
	int cases = 0;
	int t;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &t);
	while (t--) {
		int i;
		long long ans = 0;

		scanf("%d%d", &c, &s);
		for (i = 1; i <= s; ++i)
			ans = (ans + llpow(c, gcd(i, s))) % MOD;

		if (s & 1)
			ans = (ans + llpow(c, s / 2 + 1) * s % MOD) % MOD;
		else
			ans = (ans + llpow(c, s / 2) * (s / 2) % MOD +
					llpow(c, s / 2 + 1) * (s / 2) % MOD) 
				% MOD;

		printf("Case #%d: %lld\n", ++cases, ans * 500000004 % MOD * inv(s) % MOD);
	}
	return 0;
}
