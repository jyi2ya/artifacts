#include <stdio.h>

int f[1000009];

int main(void)
{
	int n, k, i, j;
	scanf("%d%d", &n, &k);
	f[0] = 1;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= k && i - j >= 0; ++j)
			f[i] = (f[i] + f[i - j]) % 100003;
	printf("%d\n", f[n]);
	return 0;
}
