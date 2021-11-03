#include <stdio.h>

long long p;
long long fac[100009];
long long facinv[100009];

long long llpow(long long a, long long x)
{
	long long ans = 1;
	for (a %= p; x; x /= 2, a = a * a % p)
		if (x & 1)
			ans = ans * a % p;
	return ans;
}

long long llinv(long long a)
{
	return llpow(a, p - 2);
}

long long C(long long n, long long m)
{
	return fac[m] * facinv[n] % p * facinv[m - n] % p;
}

long long lucas(long long n, long long m)
{
	return n == 0 ? 1 : lucas(n / p, m / p) * C(n % p, m % p) % p;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) {
		long long n, m;
		int i;
		scanf("%lld%lld%lld", &n, &m, &p);
		fac[0] = 1;
		for (i = 1; i < 100009; ++i)
			fac[i] = fac[i - 1] * i % p;
		for (i = 0; i < 100009; ++i)
			facinv[i] = llinv(fac[i]);
		printf("%lld\n", lucas(n, n + m));
	}
	return 0;
}
