#include <stdio.h>

long long inv[3000009];

int main(void)
{
	int i, n, p;
	scanf("%d%d", &n, &p);
	inv[1] = 1;
	for (i = 2; i <= n; ++i) inv[i] = ((p - p / i) * (inv[p % i])) % p;
	for (i = 1; i <= n; ++i) printf("%d\n", (int)inv[i]);
	return 0;
}
