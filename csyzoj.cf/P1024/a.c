/*
 * 题意：
 * 给定一个长为 n (n <= 1e6) 的 ab 串，每次操作可以把一个 'ab' 替换成 'bba'，求
 * 使串中所有 'b' 都在 'a' 前所需的最少操作数。答案模 1000000007 。
 *
 * 分析：
 * 开头的所有 'b' 都是无关紧要的，考虑去掉开头的 'b' 之后的字符串，若该串没有
 * 'b'，则只需要 0 步。
 * 否则它的模式应该满足： a{p}b{q}.*
 * 进行一次操作后：a{p-1}b{2}ab{q-1}.*
 * 进行 q 次操作后：a{p-1}b{2q}a.*
 * 发现：把 a{p} 最右边的 'a' 移动到 b{q} 右侧要 q 步操作，同时产生一个 b{2q}。
 *
 * 解决一个 a{p}b{q} 所要的操作数为：sum_(i=1)^p ( 2^(i-1) * q ) = q(2^p - 1)
 *
 * 因为解决 a{p}b{q} 时 a{p} 只是被挪到了右边，并没有删掉，所以下一个要解决的
 * a{p'}b{q'} 实际上要变成 a{p'+p}b{q'}
 *
 * 搞就是了。
 */

#include <stdio.h>

#define MOD (1000000007LL)

long long llpow(long long a, long long x)
{
	long long ans = 1;
	for (a %= MOD; x; a = a * a % MOD, x /= 2)
		if (x & 1)
			ans = ans * a % MOD;
	return ans;
}

int main(void)
{
	static char buf[1000009];
	int i;
	int p, q;
	int acc = 0;
	long long ans = 0;
#ifndef ONLINE_JUDGE
	freopen("string.in", "r", stdin);
#ifndef DEBUG
	freopen("string.out", "w", stdout);
#endif
#endif
	scanf("%s", buf);
	for (i = 0; buf[i] && buf[i] == 'b'; ++i)
		;
	while (buf[i]) {
		for (p = 0; buf[i + p] && buf[i + p] == 'a'; ++p)
			;
		for (q = 0; buf[i + p + q] && buf[i + p + q] == 'b'; ++q)
			;
		acc += p;
		ans = (ans + q * (llpow(2, acc) - 1) % MOD) % MOD;
		i += p + q;
	}
	printf("%lld\n", ans);
	return 0;
}
