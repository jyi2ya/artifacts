/*
 * 这个题目好像是一道 Polya 计数的板子题。但是注意到 N 的值很大，用 O(nlogn) 的
 * 方法可能会萎。所以要想想优化方法。
 *
 *   1/N * sum_(i=1)^N N^gcd(i, N)
 * = 1/N * sum_(d|N) (N^d * sum_(i=1)^N [gcd(i, N) = d] )
 * = 1/N * sum_(d|N) (N^d * sum_(i=1)^N [gcd(i/d, N/d) = 1] )
 * = 1/N * sum_(d|N) (N^d * sum_(i=1)^(N/d) [gcd(i, N/d) = 1] )
 * = 1/N * sum_(d|N) (N^d * phi(N/d))
 * = sum_(d|N) (N^(d-1) * phi(N/d))
 *
 * 然后直接算就行了！
 */

long long N, MOD;

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

long long phi(long long x)
{
	long long i;
	long long ans = x;
	for (i = 2; i * i <= x; ++i)
		if (x % i == 0) {
			ans -= ans / i;
			while (x % i == 0)
				x /= i;
		}
	if (x > 1)
		ans -= ans / x;
	return ans;
}

/* N^(d-1) * phi(N/d) */
long long magic(long long d)
{
	return llpow(N, d - 1) * phi(N / d) % MOD;
}

#include <stdio.h>

int main(void)
{
	int T;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &T);
	while (T--) {
		long long i;
		long long ans = 0;

		scanf("%lld%lld", &N, &MOD);

		for (i = 1; i * i <= N; ++i)
			if (N % i == 0) {
				ans = (ans + magic(i)) % MOD;

				if (i * i != N)
					ans = (ans + magic(N / i)) % MOD;
			}

		printf("%lld\n", ans);
	}

	return 0;
}
