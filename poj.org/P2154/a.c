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

#include <stdio.h>
#include <math.h>

int MOD;

int llpow(int a, int b)
{
	int ans = 1;
	a %= MOD;
	while (b) {
		if (b & 1)
			ans = ans * a % MOD;
		a = a * a % MOD;
		b /= 2;
	}
	return ans;
}

#define PMAX (1000000)
char is_not_p[PMAX];
int p[PMAX];
void sieve(void)
{
	int i, j, k = 0;
	for (i = 2; i < PMAX; ++i)
		if (!is_not_p[i]) {
			p[k++] = i;
			for (j = i + i; j < PMAX; j += i)
				is_not_p[j] = 1;
		}
}

int phi(int x)
{
	int i;
	int ans = x;
	int lmt = sqrt(x) + 2;
	for (i = 0; p[i] <= lmt; ++i)
		if (x % p[i] == 0) {
			ans -= ans / p[i];
			while (x % p[i] == 0)
				x /= p[i];
		}
	if (x > 1)
		ans -= ans / x;
	return ans % MOD;
}

/* N^(d-1) * phi(N/d) */
int N;
int magic(int d)
{
	return llpow(N, d - 1) * phi(N / d) % MOD;
}

int main(void)
{
	int T;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	sieve();

	scanf("%d", &T);
	while (T--) {
		int i;
		int ans = 0;

		scanf("%d%d", &N, &MOD);

		for (i = 1; i * i <= N; ++i)
			if (N % i == 0) {
				ans = (ans + magic(i)) % MOD;

				if (i * i != N)
					ans = (ans + magic(N / i)) % MOD;
			}

		printf("%d\n", ans);
	}

	return 0;
}
