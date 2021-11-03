#include <stdio.h>
#include <string.h>

#define MAX (50009)

int mu[MAX];
int mu_pre[MAX];
int prime[MAX];
int prime_top;
int is_prime[MAX];

int min(int a, int b)
{
	return a < b ? a : b;
}

int main(void)
{
	int i;
	int T;

	memset(is_prime, 0xcc, sizeof(is_prime));
	is_prime[2] = 1;
	mu[1] = 1;
	for (i = 2; i < MAX; ++i) {
		int j;
		if (is_prime[i]) {
			prime[prime_top++] = i;
			mu[i] = -1;
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
		mu_pre[i] = mu_pre[i - 1] + mu[i];

	scanf("%d", &T);
	while (T--) {
		int a, b, k;
		int lmt;
		int i, j;
		int ans = 0;

		scanf("%d%d%d", &a, &b, &k);
		a /= k, b /= k;
		lmt = min(a, b);
		for (i = 1, j = 0; i <= lmt; i = j + 1) {
			j = min(a / (a / i), b / (b / i));
			ans += (mu_pre[j] - mu_pre[i - 1]) * (a / i) * (b / i);
		}

		printf("%d\n", ans);
	}

	return 0;
}
