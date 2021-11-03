/*
 * 项链有 3 种颜色，n 个珠子，可以旋转、翻转。
 *
 * 分析项链变形的情况，实际上都是珠子的置换。有两种：
 *
 * 1. 旋转。
 * 可以看成有 n 个置换，第 i 个置换 g_i (i in [0, n) ) 为：
 * (p ((p+i-1) mod n +1) )
 * 这一部分可以很方便地用 Ploya 计数解决。
 *
 * 2. 翻转。
 * 奇数和偶数的情况分别考虑。因为翻转两边对称时会有『在置换下不改变的方案』，
 * 所以统计这个部分用 Burnside 引理比较方便。
 *
 * 对于奇数，对称轴必然过其中一个珠子，所以置换有 n 个。因为当且仅当项链关于珠子
 * 对称时置换才不会改变方案，所以方案数有 3^((n-1)/2) * 3 = 3^((n+1)/2) 种。
 *
 * 对于偶数，要考虑对称轴过珠子和不过珠子两种情况。过珠子时方案有
 * 3^(n/2-1) * 3^2 = 3^(n/2+1) 种，置换有 n/2 个。不过珠子时方案有 3^(n/2) 种，
 * 置换有 n/2 个。
 *
 * 根据公式
 * L = 1/|G| * sum_(i=1)^|G| D(g_i)
 * L = 1/|G| * sum_(i=1)^|G| m^c(g_i)
 * 计算答案。
 */

#include <stdio.h>

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

long long llpow(long long a, long long b)
{
	return b ? llpow(a * a, b / 2) * ((b & 1) ? a : 1) : 1;
}

int main(void)
{
	int n;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	while (scanf("%d", &n) == 1 && n >= 0) {
		int i;
		long long ans = 0;

		if (n == 0) {
			puts("0");
			continue;
		}

		for (i = 1; i <= n; ++i)
			ans += llpow(3, gcd(i, n));

		if (n & 1)
			ans += llpow(3, (n + 1) / 2) * n;
		else
			ans += llpow(3, n / 2 + 1) * (n / 2) +
				llpow(3, n / 2) * (n / 2);

		printf("%lld\n", ans / 2 / n);
	}

	return 0;
}
