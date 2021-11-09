#include <stdio.h>

int phi[40009];

void init(int n);

int main(void)
{
	int i, ans = 0, n;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	init(n);
	for (i = 1; i <= n - 1; ++i)
		ans += phi[i];
	ans = ans * 2 + 1;
	if (n == 1)
		ans = 0;
	printf("%d\n", ans);
	return 0;
}

int not_prime[40009];
void init(int n)
{
	int i, j;
	for (i = 0; i <= n; ++i)
		phi[i] = i;
	for (i = 2; i <= n; ++i)
		if (!not_prime[i]) {
			for (j = i + i; j <= n; j += i) {
				not_prime[j] = 1;
				phi[j] -= phi[j] / i;
			}
			--phi[i];
		}
}
