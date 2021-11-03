/*
 * 直接蒯题解了。
 * ans 改变的次数相当于有多少 i 满足 p_i = min_(j=1)^i p_j 。
 * p_i = min_(j=1)^i p_j 的概率为 1/i 。
 * 设 f(p, i) = [ p_i = min_(j=1)^i p_j ] ，
 * 那么 val(p) = (sum_(i=1)^n f(p, i))^2 
 * = sum_(i=1)^n sum_(j=1)^n f(p, i) f(p, j) 。
 * 当 i != j 时， f(p, i) f(p, j) 的期望是 1/(ij) 。
 * 当 i = j 时， f(p, i) f(p, j) 的期望为 1/i 。
 * val(p) 的期望为 (sum_(i=1)^n 1/i)^2 - sum_(i=1)^n (1/i^2) + sum_(i=1)^n 1/i 。
 * 答案为 val(p) * n! 。
 * 考虑实现，可以预处理 i 和 i^2 的逆元的前缀和，查询时随便整整就成。
 */

#include <stdio.h>

#define MOD (998244353LL)

long long llpow(long long a, long long x)
{
	long long r = 1;
	a %= MOD;
	while (x) {
		if (x & 1)
			r = r * a % MOD;
		a = a * a % MOD;
		x /= 2;
	}
	return r;
}

long long llinv(long long x)
{
	return llpow(x, MOD - 2);
}

long long inv_i_pre[100009];
long long inv_i2_pre[100009];
long long fac[100009];

int main(void)
{
	long long i;
	int q;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	fac[0] = 1;
	for (i = 1; i < 100009; ++i)
		fac[i] = fac[i - 1] * i % MOD;
	for (i = 1; i < 100009; ++i)
		inv_i_pre[i] = (inv_i_pre[i - 1] + llinv(i)) % MOD;
	for (i = 1; i < 100009; ++i)
		inv_i2_pre[i] = (inv_i2_pre[i - 1] + llinv(i * i)) % MOD;
	scanf("%d", &q);
	while (q--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n",
		       (((inv_i_pre[n] * inv_i_pre[n] % MOD - inv_i2_pre[n] +
			  inv_i_pre[n]) % MOD + MOD) % MOD) * fac[n] % MOD);
	}
	return 0;
}
