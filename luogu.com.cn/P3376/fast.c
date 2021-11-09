#include <stdio.h>
#include <string.h>
#include <limits.h>

struct edge {
	int dest;
	int cap;
	int next;
};

struct node {
	int edge;
};

struct edge E[200009];
struct node N[10009];
int Etop;

void add_edge(int s, int t, int w)
{
	E[Etop].dest = t;
	E[Etop].cap = w;
	E[Etop].next = N[s].edge;
	N[s].edge = Etop++;
}

int dist[10009];
int que[10009];

int min(int a, int b)
{
	return a < b ? a : b;
}

int dfs(int s, int t, int lmt)
{
	int f = 0, tf, i;
	if (lmt == 0 || s == t)
		return lmt;
	for (i = N[s].edge; i >= 0; i = E[i].next)
		if (dist[E[i].dest] == dist[s] + 1 && E[i].cap) {
			tf = dfs(E[i].dest, t, min(lmt, E[i].cap));
			E[i].cap -= tf;
			E[i ^ 1].cap += tf;
			lmt -= tf;
			f += tf;
			if (lmt == 0)
				break;
		}
	return f;
}

int bfs(int s, int t)
{
	int qtop = 0, qbot = 0;
	memset(dist, 0x3f, sizeof(dist));
	dist[s] = 0;
	que[qtop++] = s;
	while (qtop != qbot) {
		int c = que[qbot++];
		int i;
		if (qbot == 10009)
			qbot = 0;
		for (i = N[c].edge; i >= 0; i = E[i].next)
			if (E[i].cap && dist[E[i].dest] > dist[c] + 1) {
				dist[E[i].dest] = dist[c] + 1;
				que[qtop++] = E[i].dest;
				if (qtop == 10009)
					qtop = 0;
			}
	}
	return dist[t] == 0x3f3f3f3f;
}

int main(void)
{
	int n, m, s, t;
	int i;
	int ans = 0;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	memset(N, -1, sizeof(N));
	for (i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, 0);
	}
	while (bfs(s, t) == 0)
		ans += dfs(s, t, INT_MAX);
	printf("%d\n", ans);
	return 0;
}
