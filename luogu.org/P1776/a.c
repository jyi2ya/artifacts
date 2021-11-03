#include <stdio.h>

#define MAX (1000009)
int top = 1;

int w[MAX], v[MAX];

int dp[10000009];

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int n, ww;
	int i, j;
	scanf("%d%d", &n, &ww);
	for (i = 0; i < n; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		for (j = 0; c >= (1 << j); ++j) {
			v[top] = a * (1 << j);
			w[top] = b * (1 << j);
			++top;
			c -= (1 << j);
		}
		if (c) {
			v[top] = a * c;
			w[top] = b * c;
			++top;
		}
	}
	for (i = 1; i < top; ++i)
		for (j = ww; j >= 0; --j)
			if (j >= w[i])
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	printf("%d\n", dp[ww]);
	return 0;
}
