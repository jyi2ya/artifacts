/*
 * phi(n) = n (1 - 1/p_1) (1 - 1/p_2) ... (1 - 1/p_k)
 * n = phi(n) (p_1 / (p_1 - 1))(p_2 / (p_2 - 1)) ... (p_k / (p_k - 1))
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

int is_prime[50009];
int prime[50009];
int top;

int n;
long long ans = -1;

long long llmin(long long a, long long b)
{
	if (a == -1)
		return b;
	return a < b ? a : b;
}

int is_prim(int x)
{
	int i;
	if (x == 2 || x == 3 || x == 5)
		return 1;
	for (i = 0; prime[i] * prime[i] <= x; ++i)
		if (x % prime[i] == 0)
			return 0;
	return 1;
}

void dfs(int pos, long long phi, long long num)
{
	int i;
	if (num == 1) {
		ans = llmin(ans, phi);
		return;
	}
	/* prune */
	if (num > 47009 && is_prim(num + 1)) {
		ans = llmin(ans, phi * (num + 1));
		return;
	}
	for (i = pos; i < top && (prime[i] - 1) <= num; ++i)
		if (num % (prime[i] - 1) == 0) {
			long long num_ = num / (prime[i] - 1);
			long long phi_ = phi * prime[i];
			dfs(i + 1, phi_, num_);
			while (num_ % prime[i] == 0) {
				num_ /= prime[i];
				phi_ *= prime[i];
				dfs(i + 1, phi_, num_);
			}
		}
}

int main(void)
{
	int i, j;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	memset(is_prime, 0xcc, sizeof(is_prime));
	is_prime[0] = 0;
	is_prime[1] = 0;
	for (i = 2; i < 50009; ++i)
		if (is_prime[i]) {
			prime[top++] = i;
			for (j = i + i; j < 50009; j += i)
				is_prime[j] = 0;
		}

	scanf("%d", &n);
	dfs(0, 1, n);
	printf("%lld\n", ans);
	return 0;
}
