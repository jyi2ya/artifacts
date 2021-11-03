#include <stdio.h>
#include <string.h>
#include <assert.h>

struct {
	struct {
		int edg;
	} N[1009];
	struct {
		int dst, nxt;
	} E[4009];
	int Ec;
	int n;
} G;

void g_ini(int n)
{
	G.Ec = 1;
	G.n = n;
}

void g_add(int u, int v)
{
	G.E[G.Ec].dst = v;
	G.E[G.Ec].nxt = G.N[u].edg;
	G.N[u].edg = G.Ec++;
}

void g_add2(int u, int v)
{
	g_add(u, v);
	g_add(v, u);
}

int g_connected(int u, int v)
{
	int i;
	if (u == v)
		return 1;
	for (i = G.N[u].edg; i; i = G.E[i].nxt)
		if (G.E[i].dst == v)
			return 1;
	return 0;
}

void g_prt(void)
{
	int i;
	puts("=== G ===");
	for (i = 1; i <= G.n; ++i) {
		int j;
		printf("%d:", i);
		for (j = G.N[i].edg; j; j = G.E[j].nxt)
			printf("%d ", G.E[j].dst);
		putchar('\n');
	}
}

int g_sssp(int *dis, int s, int t)
{
	static int que[4009];
	int qtop = 0, qbot = 0;
	memset(dis + 1, 0x3f, sizeof(dis[0]) * G.n);
	que[qtop++] = s;
	dis[s] = 0;
	while (qtop != qbot) {
		int c = que[qbot++];
		int i;
		assert(qbot < 4009);
		for (i = G.N[c].edg; i; i = G.E[i].nxt)
			if (dis[G.E[i].dst] > dis[c] + 1) {
				dis[G.E[i].dst] = dis[c] + 1;
				que[qtop++] = G.E[i].dst;
			}
	}
	return dis[t];
}

int main(void)
{
	int n, m, s, t;
	int i, j;
	int org;
	int ans = 0;
	static int diss[1009], dist[1009];

	scanf("%d%d%d%d", &n, &m, &s, &t);
	g_ini(n);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		g_add2(u, v);
	}
	g_sssp(diss, s, t);
	org = g_sssp(dist, t, s);
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			if (!g_connected(i, j))
				if (diss[i] + dist[j] + 1 >= org &&
						dist[i] + diss[j] + 1 >= org)
					++ans;
	printf("%d\n", ans / 2);
	return 0;
}
