#include <stdio.h>

long long ans[50009];

int main(void)
{
	long long i, n, m, l, r;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%lld%lld", &n, &m);

	l = 1, r = n;
	for (i = 1; i <= n; ++i) {
		if ((n - i) * (n - i - 1) / 2 >= m) {
			ans[l++] = i;
		} else {
			m -= r - l;
			ans[r--] = i;
		}
	}
	for (i = 1; i <= n; ++i)
		printf(i != 1 ? " %lld" : "%lld", ans[i]);
	putchar('\n');
	return 0;
}
