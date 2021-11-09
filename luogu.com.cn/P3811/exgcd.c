#include <stdio.h>

void exgcd(long long a, long long b, long long *x, long long *y);

long long n, p;

int main(void)
{
	long long x, y, i;
	scanf("%lld%lld", &n, &p);
	for (i = 1; i <= n; ++i) {
		exgcd(i, p, &x, &y);
		x = (x % p + p) % p;
		printf("%lld\n", x);
	}
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
