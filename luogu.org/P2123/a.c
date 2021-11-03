#include <stdio.h>
#include <stdlib.h>

typedef struct de {
	long long a, b;
} de;

long long max(long long a, long long b)
{
	return a > b ? a : b;
}

long long min(long long a, long long b)
{
	return a < b ? a : b;
}

int cmp(const void *a, const void *b)
{
	de *p = (de*)a, *q = (de*)b;
	if (min(p->a, q->b) == min(q->a, p->b)) {
		if (p->a < p->b && q->a < q->b)
			return q->a - p->a;
		return p->b - q->b;
	}
	return min(p->a, q->b) - min(q->a, p->b);
}

de P[20009];
long long C[20009];

int main(void)
{
	int n, i, T;
	long long ta;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (i = 0; i < n; ++i)
			scanf("%lld%lld", &P[i].a, &P[i].b);
		qsort(P, n, sizeof(de), cmp);
		ta = P[0].a, C[0] = P[0].a + P[0].b;
		for (i = 1; i < n; ++i) {
			ta += P[i].a;
			C[i] = max(C[i - 1], ta) + P[i].b;
		}
		printf("%lld\n", C[n - 1]);
	}
	return 0;
}
