#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(long long *)a == *(long long *)b ? 0 :
		*(long long *)a < *(long long *)b ? -1 : 1;
}

int main(void)
{
	int n;
	int i;
	static long long val[100009];
	static long long pre_[100009], *pre = pre_ + 1;
	long long ans = 0;

#ifndef ONLINE_JUDGE
	freopen("sum.in", "r", stdin);
#ifndef DEBUG
	freopen("sum.out", "w", stdout);
#endif
#endif

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%lld", &val[i]);
	qsort(val, n, sizeof(val[0]), cmp);
	for (i = 0; i < n; ++i)
		pre[i] = pre[i - 1] + val[i];
	ans = pre[n - 1];
	for (i = n - 2; i >= 0; --i)
		if ((val[i + 1] + 1) / 2 > pre[i])
			ans -= (val[i + 1] + 1) / 2 - pre[i] - 1;
	ans -= (val[0] + 1) / 2 - 1;
	printf("%lld\n", ans);
	return 0;
}
