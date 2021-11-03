#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	return *(double *)a < *(double *)b ? -1 : 1;
}

void solve(int n, int k)
{
	int i;
	static double value[1009];
	static double cost[1009];
	static double tmp[1009];
	double l = 0, r = 100, m;
	int cnt = 100;
	for (i = 0; i < n; ++i)
		scanf("%lf", &value[i]);
	for (i = 0; i < n; ++i)
		scanf("%lf", &cost[i]);
	while (cnt--) {
		double t = 0;
		m = (l + r) / 2;
		for (i = 0; i < n; ++i)
			tmp[i] = value[i] - m * cost[i];
		qsort(tmp, n, sizeof(tmp[0]), cmp);
		for (i = k; i < n; ++i)
			t += tmp[i];
		if (t > 1e-4)
			l = m;
		else
			r = m;
	}
	printf("%.0f\n", l * 100);
}

int main(void)
{
	int n, k;
	while (scanf("%d%d", &n, &k) == 2 && n && k)
		solve(n, k);
	return 0;
}
