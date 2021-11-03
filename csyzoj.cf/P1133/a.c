#include <stdio.h>

#define MOD 1000000007LL

long long llpow(long long a, long long x)
{
	long long r = 1;
	while (x) {
		if (x & 1)
			r = r * a % MOD;
		a = a * a % MOD;
		x /= 2;
	}
	return r;
}

int main(void)
{
	long long n;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%lld", &n);
	printf("%lld\n", ((llpow(2, n * 2 + 2) - (n * 2 + 1) * llpow(2, n + 1)
					- 2) % MOD + MOD) % MOD);
	return 0;
}
