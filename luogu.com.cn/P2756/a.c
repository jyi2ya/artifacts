#include <stdio.h>
#include <string.h>
#include <limits.h>

struct edge {
	int s;
	int d;
	int c;
	int n;
};

struct node {
	int e;
};

struct node N[209];
struct edge E[200009];
int Etop = 0;

void add_edge(int u, int v, int w)
{
	E[Etop].s = u;
	E[Etop].c = w;
	E[Etop].d = v;
	E[Etop].n = N[u].e;
	N[u].e = Etop++;
}

int dist[209];

int min(int a, int b)
{
	return a < b ? a : b;
}

int dfs(int s, int t, int lmt)
{
	int f = 0, tf, i;
	if (s == t)
		return lmt;
	for (i = N[s].e; i >= 0; i = E[i].n)
		if (E[i].c && dist[E[i].d] == dist[s] + 1) {
			tf = dfs(E[i].d, t, min(lmt, E[i].c));
			f += tf;
			lmt -= tf;
			E[i].c -= tf;
			E[i ^ 1].c += tf;
			if (lmt == 0)
				break;
		}
	return f;
}

int bfs(int s, int t)
{
	static int que[209];
	int qtop = 0, qbot = 0;
	memset(dist, 0x3f, sizeof(dist));
	dist[s] = 0;
	que[qtop++] = s;
	while (qtop != qbot) {
		int c = que[qbot++];
		int i;
		if (qbot == 209)
			qbot = 0;
		for (i = N[c].e; i >= 0; i = E[i].n)
			if (dist[E[i].d] > dist[c] + 1 && E[i].c) {
				dist[E[i].d] = dist[c] + 1;
				que[qtop++] = E[i].d;
				if (qtop == 209)
					qtop = 0;
			}
	}
	return dist[t] == 0x3f3f3f3f;
}

int save[209][209];

int main(void)
{
	int m, n;
	int u, v;
	int i, j;
	int ans = 0;
	scanf("%d%d", &m, &n);
	memset(N, -1, sizeof(N));
	for (i = 1; i <= m; ++i) {
		add_edge(0, i, 1);
		add_edge(i, 0, 0);
	}
	for (i = m + 1; i <= m + n; ++i) {
		add_edge(i, m + n + 1, 1);
		add_edge(m + n + 1, i, 0);
	}
	while (scanf("%d%d", &u, &v) == 2 && !(u == -1 && v == -1)) {
		add_edge(u, v + m, 1);
		add_edge(v + m, u, 0);
	}

	while (bfs(0, n + m + 1) == 0)
		ans += dfs(0, n + m + 1, INT_MAX);

	if (ans == 0)
		puts("No Solution!");
	else
		printf("%d\n", ans);
	for (i = 0; i < Etop; i += 2)
		if (E[i].c == 0)
			save[E[i].s][E[i].d] = 1;
	for (i = 1; i <= m; ++i)
		for (j = m + 1; j <= m + n; ++j)
			if (save[i][j])
				printf("%d %d\n", i, j - m);
	return 0;
}
