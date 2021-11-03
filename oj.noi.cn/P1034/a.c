#include <stdio.h>

#define MAX 10000009

int dp[MAX];
int p[] = {10, 20, 50};

int main(void)
{
	int i, j, n;
	scanf("%d", &n);
	for (i = 2; i >= 0; --i) {
		dp[0] = 1;
		for (j = p[i]; j <= n; ++j)
			dp[j] = dp[j - p[i]] + dp[j];
	}
	printf("%d\n", dp[n]);
	return 0;
}
