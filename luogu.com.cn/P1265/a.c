#include <stdio.h>
#include <math.h>

long long x[5009], y[5009];

double dist(long long x1, long long y1, long long x2, long long y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int v[5009];
double d[5009];

int main(void)
{
	int n;
	int i, j;
	double ans = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf("%lld%lld", &x[i], &y[i]);
	for (i = 0; i <= n; ++i)
		d[i] = 0xccff66ccff66ccff;
	d[1] = 0;
	for (i = 1; i <= n; ++i) {
		int k = 0;
		for (j = 1; j <= n; ++j)
			if (!v[j] && d[j] < d[k])
				k = j;
		v[k] = 1;
		for (j = 1; j <= n; ++j)
			if (!v[j] && dist(x[k], y[k], x[j], y[j]) < d[j])
				d[j] = dist(x[k], y[k], x[j], y[j]);
	}
	for (i = 1; i <= n; ++i)
		ans += d[i];
	printf("%.2f\n", ans);
	return 0;
}
