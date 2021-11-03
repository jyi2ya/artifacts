#include <stdio.h>

long long exgcd(long long a, long long b, long long *x, long long *y)
{
	long long ans;
	if (b) {
		ans = exgcd(b, a % b, y, x);
		*y -= (a / b) * *x;
	} else {
		*y = 0;
		*x = 1;
		ans = 1;
	}
	return ans;
}

int main(void)
{
	long long n, p, w, d;
	long long x, y;
	long long c;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%lld%lld%lld%lld", &n, &p, &w, &d);
	c = p / w;
	for (x = c; x >= c - d; --x) {
		y = (p - x * w) / d;
		if (x * w + y * d == p)
			break;
		if (x + y > n)
			break;
	}

	if (x * w + y * d == p && x >= 0 && y >= 0 && n - x - y >= 0)
		printf("%lld %lld %lld\n", x, y, n - x - y);
	else
		puts("-1");
	return 0;
}
