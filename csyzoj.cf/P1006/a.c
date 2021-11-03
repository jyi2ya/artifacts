#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

struct orz_t {
	double a, b;
} val[300009], pre[300009], suf[300009];

int cmp(const void *a, const void *b)
{
	return -((struct orz_t *)a)->b / ((struct orz_t *)a)->a >
		-((struct orz_t *)b)->b / ((struct orz_t *)b)->a ?
		1 : -1;
}

int main(void)
{
	int i;
	int n;
	double ans = LLONG_MAX;
	double zero = 0;
	int t = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		double a, b;
		scanf("%lf%lf", &a, &b);
		if (a < 0) {
			a = -a;
			b = -b;
		}
		if (a < 1e-6) {
			zero += fabs(b);
		} else {
			val[t].a = a;
			val[t++].b = b;
		}
	}
	n = t;
	qsort(val, n, sizeof(struct orz_t), cmp);
	pre[0].a = val[0].a;
	pre[0].b = val[0].b;
	for (i = 1; i < n; ++i) {
		pre[i].a = pre[i - 1].a + val[i].a;
		pre[i].b = pre[i - 1].b + val[i].b;
	}
	suf[n - 1].a = val[n - 1].a;
	suf[n - 1].b = val[n - 1].b;
	for (i = n - 2; i >= 0; --i) {
		suf[i].a = suf[i + 1].a + val[i].a;
		suf[i].b = suf[i + 1].b + val[i].b;
	}
	for (i = 0; i < n; ++i) {
		double x = -val[i].b / val[i].a;
		double lans = zero + pre[i].a * x + pre[i].b - suf[i].a * x - suf[i].b;
		if (lans < ans)
			ans = lans;
	}
	printf("%f\n", ans);
	return 0;
}
