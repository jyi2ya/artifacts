#include <stdio.h>
#include <math.h>

#define MOD (1000000007ULL)

typedef unsigned long long ull;
typedef __uint128_t ulll;

ulll dfs(ulll n, ulll a, ulll b)
{
	ulll ret = n * n * n * b + (n - 1) * n * n * a;
	if ((n & 1) == 0) {
		ulll tmp = dfs(n / 2, a, b);
		tmp = tmp * 7 + 18 * (n / 2) * (n / 2) * a;
		if (tmp < ret)
			ret = tmp;
	}
	return ret;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) {
		ull n, a, b;
		scanf("%llu%llu%llu", &n, &a, &b);
		printf("%llu\n", (ull)(dfs(n, a, b) % MOD));
	}
	return 0;
}
