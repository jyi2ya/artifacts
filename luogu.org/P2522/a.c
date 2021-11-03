#include <stdio.h>
#include <string.h>

#define MAX (50009)

int prime[MAX];
int prime_top;
int is_prime[MAX];
int mu[MAX];
int pre[MAX];

int min(int a, int b)
{
	return a < b ? a : b;
}

int calc(int x, int y, int k)
{
	int i, j;
	int lmt;
	int ans = 0;
	x /= k, y /= k;
	lmt = min(x, y);
	for (i = 1, j = 0; i <= lmt; i = j + 1) {
		j = min(x / (x / i), y / (y / i));
		ans += (pre[j] - pre[i - 1]) * (x / i) * (y / i);
	}
	return ans;
}

int main(void)
{
	int i;
	int n;

	memset(is_prime, 0xcc, sizeof(is_prime));
	is_prime[2] = 1;
	mu[1] = 1;
	for (i = 2; i < MAX; ++i) {
		int j;
		if (is_prime[i]) {
			mu[i] = -1;
			prime[prime_top++] = i;
		}
		for (j = 0; j < prime_top && i * prime[j] < MAX; ++j) {
			is_prime[i * prime[j]] = 0;
			if (i % prime[j] == 0)
				break;
			else
				mu[i * prime[j]] = mu[i] * mu[prime[j]];
		}
	}
	for (i = 1; i < MAX; ++i)
		pre[i] = pre[i - 1] + mu[i];

	scanf("%d", &n);
	while (n--) {
		int a, b, c, d, k;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		printf("%d\n", calc(b, d, k) - calc(a - 1, d, k)
				- calc(b, c - 1, k) + calc(a - 1, c - 1, k));
	}
	return 0;
}
