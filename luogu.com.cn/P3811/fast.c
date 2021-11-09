#include <stdio.h>

long long p, n;
long long inv(long long x);

int main(void)
{
	long long i;
	scanf("%lld%lld", &n, &p);
	for (i = 1; i <= n; ++i)
		printf("%lld\n", inv(i));
	return 0;
}

/* 
   inv(x) = -(p / x) * inv(p % x)
 */
long long inv(long long x)
{
	long long ans = 1;
	while (x != 1) {
		ans = (ans * -(p / x) % p + p) % p;
		x = p % x;
	}
	return ans;
}
