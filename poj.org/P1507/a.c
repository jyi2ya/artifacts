/*
 * 每个手镯有 c 个珠子，可以旋转。相当于有 c 个置换。
 * 手镯的每个珠子可以染上 s 种颜色。
 * 这个题应该用 polya 做。
 * g_i 为置换 ( i in [0, c) )：
 * (1, 1 + i)(2, 2 + i) ... (c, (c + i - 1) mod c + 1)
 *
 * L = 1/n * sum_(i=0)^n s^c(g_i)
 *
 * 求出每一个 g_i 的循环节个数，再套用公式。
 * 求循环节个数可以 O(n^2) 解决。
 * 打表发现循环节个数是 i 和 s 的最大公约数。
 *
 * 手镯是可以翻转的（WA 了才知道）。
 * 还要加上翻转的情况。
 */
#include <stdio.h>


long long llpow(long long a, long long b)
{
	long long ans = 1;
	while (b) {
		if (b & 1)
			ans *= a;
		a *= a;
		b /= 2;
	}
	return ans;
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

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	while (scanf("%d%d", &c, &s) == 2 && c && s) {
		int i;
		long long ans = 0;

		for (i = 1; i <= s; ++i)
			ans += llpow(c, gcd(i, s));

		if (s & 1)
			ans += llpow(c, s / 2 + 1) * s;
		else
			ans += llpow(c, s / 2) * (s / 2) + llpow(c, s / 2 + 1) * (s / 2);

		printf("%lld\n", ans / 2 / s);
	}
	return 0;
}
