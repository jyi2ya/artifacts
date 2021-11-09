#include <stdio.h>

int cnt[1000009], largest[1000009];

int max(int a, int b);

int main(void)
{
	int n, i, x, j;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);

	for (i = 0; i < n; ++i) {
		scanf("%d", &x);
		for (j = 1; j * j <= x; ++j)
			if (x % j == 0) {
				++cnt[j];
				if (j * j != x)
					++cnt[x / j];
			}
	}

	for (i = 1000000; i >= 1; --i)
		if (!largest[cnt[i]])
			largest[cnt[i]] = i;
	for (i = 1000000; i >= 1; --i)
		largest[i] = max(largest[i], largest[i + 1]);

	for (i = 1; i <= n; ++i)
		printf("%d\n", largest[i]);
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
