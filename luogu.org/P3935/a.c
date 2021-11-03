#include <stdio.h>

#define MOD (998244353LL)

long long calc(long long n)
{
	long long ans = 0;
	long long i, j;
	for (i = 1, j = 0; i <= n; i = j + 1) {
		j = n / (n / i);
		ans = (ans + (j - i + 1) * (n / i) % MOD) % MOD;
	}
	return ans;
}

int main(void)
{
	long long l, r;
	scanf("%lld%lld", &l, &r);
	printf("%lld\n", (calc(r) - calc(l - 1) % MOD + MOD) % MOD);
	return 0;
}
