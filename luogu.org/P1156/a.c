#include <stdio.h>
#include <stdlib.h>

typedef struct g {
	int t, h, f;
} g;
g A[109];
#define INF 0x66ccff
int D, G, life;

int cmp(const void *a, const void *b);
int dfs(int t, int h, int hp);
int min(int a, int b);

int main(void)
{
	int i, a;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d", &D, &G);
	for (i = 0; i < G; ++i)
		scanf("%d%d%d", &A[i].t, &A[i].f, &A[i].h);
	qsort(A, G, sizeof(A[0]), cmp);
	A[G].t = INF;
	a = dfs(0, 0, 10 - A[0].t);
	if (a >= INF)
		printf("%d\n", life);
	else
		printf("%d\n", a);
	return 0;
}

int vis[109][109][1009];
int dfs(int p, int h, int hp)
{
	if (hp < 0)
		return INF;
	if (h + A[p].h >= D)
		return A[p].t;
	if (A[p].t + hp + A[p].f > life)
		life = A[p].t + hp + A[p].f;
	if (vis[p][h][hp])
		return vis[p][h][hp];
	return vis[p][h][hp] = min(
			dfs(p + 1, h, hp - (A[p + 1].t - A[p].t) + A[p].f),
			dfs(p + 1, h + A[p].h, hp - (A[p + 1].t - A[p].t))
			);
}

int cmp(const void *a, const void *b)
{
	return ((g*)a)->t - ((g*)b)->t;
}

int min(int a, int b)
{
	return a < b ? a : b;
}
