#include <stdio.h>

#define MOD (1000000007)

int main(void)
{
	long long G[1000009];
	int n;
	int i;
	G[1] = 1;
	G[2] = 2;
	scanf("%d", &n);
	for (i = 3; i <= n; ++i)
		G[i] = (G[i - 1] * 2 + G[i - 2]) % MOD;
	printf("%lld\n", G[n]);
	return 0;
}
