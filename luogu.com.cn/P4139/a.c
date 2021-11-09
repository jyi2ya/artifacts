/*
 * 根据扩展欧拉定理：a^b =- a^(b mod phi(p) + phi(p)) (mod p)
 * 设 f(p) = 2^2^2 ... mod p
 * f(1) = 0
 * f(p) = 2^(f(phi(p)) + phi(p)) mod p
 *
 * 筛法写错了一次。
 */

#include <stdio.h>

int phi[10000009];
int prime[1000009], top;
char is_not_prime[10000009];

long long llpow(long long a, long long x, long long mod)
{
	long long r = 1;
	while (x) {
		if (x & 1)
			r = r * a % mod;
		a = a * a % mod;
		x /= 2;
	}
	return r;
}

long long f(long long p)
{
	if (p == 1)
		return 0;
	return llpow(2, f(phi[p]) + phi[p], p);
}

int main(void)
{
	int T;
	int i, j;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	is_not_prime[0] = 1;
	is_not_prime[1] = 1;
	phi[1] = 1;
	for (i = 2; i < 10000009; ++i) {
		if (!is_not_prime[i]) {
			phi[i] = i - 1;
			prime[top++] = i;
		}
		for (j = 0; j < top && i * prime[j] < 10000009; ++j) {
			is_not_prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			} else {
				phi[i * prime[j]] = phi[i] * phi[prime[j]];
			}
		}
	}

	scanf("%d", &T);
	while (T--) {
		long long x;
		scanf("%lld", &x);
		printf("%lld\n", f(x));
	}

	return 0;
}
