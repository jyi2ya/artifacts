#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item_t {
	long long a, b, c;
} item_t;

item_t item[59];
long long N, T;
long long M[100009][59];

int cmp(const void *a, const void *b);
long long dfs(long long t, long long p);
long long max(long long a, long long b);

int main(void)
{
	long long i;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%lld%lld", &T, &N);
	for (i = 0; i < N; ++i)
		scanf("%lld", &item[i].a);
	for (i = 0; i < N; ++i)
		scanf("%lld", &item[i].b);
	for (i = 0; i < N; ++i)
		scanf("%lld", &item[i].c);
	qsort(item, N, sizeof(item_t), cmp);
	memset(M, -1, sizeof(M));
	printf("%lld\n", dfs(0, 0));
	return 0;
}

long long dfs(long long t, long long p)
{
	return (p == N || t >= T) ?
		(0) :
		((M[t][p] >= 0) ?
		 (M[t][p]) :
		 (M[t][p] = max((dfs(t, p + 1)),
				((t + item[p].c > T) ?
				 (0) :
				 (dfs(t + item[p].c, p + 1) + item[p].a - item[p].b * (t + item[p].c))))));
}

int cmp(const void *a, const void *b)
{
	item_t *p = (item_t*)a, *q = (item_t*)b;
	return p->c * q->b - q->c * p->b;
}

long long max(long long a, long long b)
{
	return a > b ? a : b;
}
