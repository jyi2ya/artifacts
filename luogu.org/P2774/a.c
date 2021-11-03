#include <stdio.h>
#include <string.h>

#define INF (0x3f3f3f3f)

struct {
	struct {
		int edg;
	} N[1000009];
	struct {
		int dst, nxt, cap;
	} E[2000009];
	int dist[1000009];
	int Ec;
} G;

void g_ini(void)
{
	G.Ec = 2;
}

void g_add(int u, int v, int w)
{
	G.E[G.Ec].dst = v;
	G.E[G.Ec].cap = w;
	G.E[G.Ec].nxt = G.N[u].edg;
	G.N[u].edg = G.Ec++;
}

void g_add2(int u, int v, int w)
{
	g_add(u, v, w);
	g_add(v, u, 0);
}

int g_bfs(int s, int t)
{
	static int Q[1000009];
	int top = 0, bot = 0;
	memset(G.dist, 0x3f, sizeof(G.dist));
	G.dist[s] = 0;
	Q[top++] = s;
	while (top != bot) {
		int c = Q[bot++];
		int i;
		for (i = G.N[c].edg; i; i = G.E[i].nxt)
			if (G.E[i].cap && G.dist[G.E[i].dst] > G.dist[c] + 1) {
				G.dist[G.E[i].dst] = G.dist[c] + 1;
				Q[top++] = G.E[i].dst;
			}
	}
	return G.dist[t] == INF;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int g_dfs(int s, int t, int lmt)
{
	int f = 0, tf, i;
	if (lmt == 0 || s == t)
		return lmt;
	for (i = G.N[s].edg; i; i = G.E[i].nxt)
		if (G.E[i].cap && G.dist[G.E[i].dst] == G.dist[s] + 1) {
			tf = g_dfs(G.E[i].dst, t, min(lmt, G.E[i].cap));
			f += tf;
			lmt -= tf;
			G.E[i].cap -= tf;
			G.E[i ^ 1].cap += tf;
			if (lmt == 0)
				break;
		}
	return f;
}

int n, m;

int pack(int w, int c)
{
	return w * n + c + 3;
}

int main(void)
{
	int i, j;
	int s = 1, t = 2;
	static int mtx[109][109];
	int ans = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif


	scanf("%d%d", &m, &n);

	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j) {
			scanf("%d", &mtx[i][j]);
			ans += mtx[i][j];
		}

	g_ini();

	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j) {
			if ((i ^ j) & 1) {
				g_add2(s, pack(i, j), mtx[i][j]);
				if (i - 1 >= 0)
					g_add2(pack(i, j), pack(i - 1, j), INF);
				if (i + 1 < m)
					g_add2(pack(i, j), pack(i + 1, j), INF);
				if (j + 1 < n)
					g_add2(pack(i, j), pack(i, j + 1), INF);
				if (j - 1 >= 0)
					g_add2(pack(i, j), pack(i, j - 1), INF);
			} else {
				g_add2(pack(i, j), t, mtx[i][j]);
			}
		}

	while (g_bfs(s, t) == 0)
		ans -= g_dfs(s, t, INF);

	printf("%d\n", ans);
	return 0;
}
