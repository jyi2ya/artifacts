#include <stdio.h>

long long A[19], B[19], K;
long long exgcd(long long a, long long b, long long *x, long long *y);
long long lcm(long long a, long long b);
long long gcd(long long a, long long b);
long long mul(long long a, long long b, long long p);
long long inv(long long x, long long p);

int main(void)
{
	int i;
	long long BB, a;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%lld", &K);
	for (i = 0; i < K; ++i)
		scanf("%lld", A + i);
	for (i = 0; i < K; ++i)
		scanf("%lld", B + i);
	for (i = 0; i < K; ++i)
		A[i] = (A[i] % B[i] + B[i]) % B[i];

	BB = 1;
	for (i = 0; i < K; ++i)
		BB = lcm(BB, B[i]);

	a = 0;
	for (i = 0; i < K; ++i)
		a = (a + mul(mul(A[i] % BB, (BB / B[i]) % BB, BB), inv(BB / B[i], B[i]), BB)) % BB;

	printf("%lld\n", a);
	return 0;
}

long long exgcd(long long a, long long b, long long *x, long long *y)
{
	long long r;
	if (!b) {
		*x = 1, *y = 0, r = a;
	} else {
		r = exgcd(b, a % b, y, x);
		*y -= (a / b) * *x;
	}
	return r;
}

long long lcm(long long a, long long b)
{
	return a / gcd(a, b) * b;
}

long long gcd(long long a, long long b)
{
	long long x, y;
	return exgcd(a, b, &x, &y);
}

long long inv(long long a, long long p)
{
	long long x, y;
	a %= p;
	exgcd(a, p, &x, &y);
	return (x % p + p) % p;
}

long long mul(long long a, long long b, long long p)
{
	long long ans = 0;
	while (b) {
		if (b & 1)
			ans = (ans + a) % p;
		a = (a + a) % p;
		b /= 2;
	}
	return ans;
}
