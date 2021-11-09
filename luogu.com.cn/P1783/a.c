#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct edge {
	double dist;
	int u, v;
};

struct point {
	int x, y;
};

struct point point[1009];
struct edge edge[2000009];
int etop;

double dist(int u, int v)
{
	double d1 = point[u].x - point[v].x;
	double d2 = point[u].y - point[v].y;
	return sqrt(d1 * d1 + d2 * d2) / 2;
}

void add_edge(int u, int v, double dst)
{
	edge[etop].u = u;
	edge[etop].v = v;
	edge[etop].dist = dst;
	++etop;
}

int cmp(const void *a, const void *b)
{
	return ((struct edge*)a)->dist < ((struct edge*)b)->dist ?
		-1 : 1;
}

int fa[1009];

int find(int x)
{
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

int main(void)
{
	int n, m;
	int i, j;
	double ans = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
	scanf("%d%d", &n, &m);

	for (i = 0; i < m; ++i)
		scanf("%d%d", &point[i].x, &point[i].y);

	for (i = 0; i < m; ++i)
		add_edge(i, m, point[i].x);
	for (i = 0; i < m; ++i)
		add_edge(i, m + 1, n - point[i].x);
	for (i = 0; i < m; ++i)
		for (j = i + 1; j < m; ++j)
			add_edge(i, j, dist(i, j));
	qsort(edge, etop, sizeof(edge[0]), cmp);

	for (i = 0; i < m + 2; ++i)
		fa[i] = i;
	for (i = 0; i < etop; ++i) {
		ans = edge[i].dist;
		fa[find(edge[i].u)] = find(edge[i].v);
		if (find(m) == find(m + 1))
			break;
	}

	printf("%.2f\n", ans);
	return 0;
}
