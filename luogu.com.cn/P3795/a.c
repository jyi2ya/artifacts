#include <stdio.h>

#define MOD 14233333LL

int main(void)
{
	long long a1, a2, a3;
	int i, k;
	scanf("%d", &k);

	a1 = 1, a2 = 1, a3 = 1;
	for (i = 2; i <= k; ++i) {
		a3 = a2 + a1 % MOD * (i - 1) % MOD;
		a1 = a2, a2 = a3;
	}

	printf("%lld\n", a3 % MOD);
	return 0;
}
