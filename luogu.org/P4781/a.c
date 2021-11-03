#include <stdio.h>

long long xx[2009], yy[2009];

long long lagrange(int n, long long *x, long long *y, long long k, long long mod);

int main(void)
{
	int i, n;
	long long k;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%lld", &n, &k);
	for (i = 0; i < n; ++i)
		scanf("%lld%lld", xx + i, yy + i);

	printf("%lld\n", lagrange(n, xx, yy, k, 998244353));
	return 0;
}

void exgcd(long long a, long long b, long long *x, long long *y)
{
	if (!b) {
		*x = 1;
		*y = 0;
	} else {
		exgcd(b, a % b, y, x);
		*y -= (a / b) * *x;
	}
}

long long inv(long long a, long long mod)
{
	long long x, y;
	exgcd(a, mod, &x, &y);
	x = (x % mod + mod) % mod;
	return x;
}

long long lagrange(int n, long long *x, long long *y, long long k, long long mod)
{
	int i, j;
	long long ans = 0;
	for (i = 0; i < n; ++i) {
		long long s1 = y[i] % mod, s2 = 1;

		for (j = 0; j < n; ++j) {
			if (i == j)
				continue;
			s1 = s1 * (k - x[j]) % mod;
			s2 = s2 * (x[i] - x[j]) % mod;
		}

		if (s2 < 0) {
			s1 = -s1;
			s2 = -s2;
		}

		ans = (ans + s1 % mod * inv(s2, mod) % mod) % mod;
	}
	return (ans + mod) % mod;
}
