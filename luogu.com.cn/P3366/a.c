#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
	int f, t, u;
} edge;

edge a[200009];

int find(int x);
void merge(int a, int b);
void init(void);
int count(void);

int N, M;

int cmp(const void *a, const void *b)
{
	return ((edge*)a)->u - ((edge*)b)->u;
}

int main(void)
{
	int i, ans = 0;
	scanf("%d%d", &N, &M);
	for (i = 0; i < M; ++i)
		scanf("%d%d%d", &a[i].f, &a[i].t, &a[i].u);
	init();
	qsort(a, M, sizeof(edge), cmp);
	for (i = 0; i < M; ++i)
		if (find(a[i].f) != find(a[i].t)) {
			merge(a[i].f, a[i].t);
			ans += a[i].u;
			if (count() == 1)
				break;
		}
	printf("%d\n", ans);
	return 0;
}

int ufs[5009], ufs_cnt;
void init(void)
{
	int i;
	for (i = 0; i <= N; ++i)
		ufs[i] = i;
	ufs_cnt = N;
}

int find(int x)
{
	if (ufs[x] == x)
		return x;
	return ufs[x] = find(ufs[x]);
}

void merge(int a, int b)
{
	if (find(a) == find(b))
		return;

	ufs[find(a)] = find(b);
	--ufs_cnt;
}

int count(void)
{
	return ufs_cnt;
}
