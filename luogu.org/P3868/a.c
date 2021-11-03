#include <stdio.h>


long long exgcd(long long a, long long b, long long *x, long long *y);
long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
long long mul(long long a, long long b, long long mod);

int main(void)
{
	long long n, mod, gg, res, right, x, k, s, M;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%lld", &n);
	M = 1, x = 0;

	while (n--) {
		scanf("%lld%lld", &mod, &res);
		gg = exgcd(M, mod, &k, &s);
		right = (res - x + mod) % mod;
		k = mul(k, right / gg, mod);
		k = (k % mod + mod) % mod;
		x += M * k;
		M = lcm(M, mod);
		x = (x % M + M) % M;
	}
	printf("%lld\n", x);
	return 0;
}

long long exgcd(long long a, long long b, long long *x, long long *y)
{
	long long ret = a;
	if (!b) {
		*x = 1;
		*y = 0;
	} else {
		ret = exgcd(b, a % b, y, x);
		*y -= (a / b) * *x;
	}
	return ret;
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

long long lcm(long long a, long long b)
{
	return a / gcd(a, b) * b;
}

long long mul(long long a, long long b, long long mod)
{
	long long ans = 0;
	int lt0 = 0;
	if (a < 0) {
		lt0 ^= 1;
		a = -a;
	}
	if (b < 0) {
		lt0 ^= 1;
		b = -b;
	}
	while (b) {
		if (b & 1)
			ans = (ans + a) % mod;
		a = (a + a) % mod;
		b /= 2;
	}
	if (lt0)
		return -ans;
	return ans;
}
