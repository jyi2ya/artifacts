#include <stdio.h> 
#include <math.h>

long long phi(long long x);

int main(void)
{
	long long n, i, ans = 0;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%lld", &n);
	for (i = 1; i * i <= n; ++i)
		if (n % i == 0) {
			ans += i * phi(n / i);
			if (i * i != n)
				ans += (n / i) * phi(i);
		}
	printf("%lld\n", ans);
	return 0;
}

long long phi(long long x)
{
	long long i, ans = x, lmt = floor(sqrt(x) + 0.5);

	for (i = 2; i <= lmt; ++i) {
		if (x % i == 0)
			ans -= ans / i;
		while (x % i == 0)
			x /= i;
	}

	if (x > 1)
		ans -= ans / x;
	return ans;
}
