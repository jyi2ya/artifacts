#include <stdio.h>
#include <string.h>

struct {
	struct {
		int edg, vis;
	} N[300009];
	struct {
		int src, dst, nxt, cap;
	} E[300009];
	int dist[300009];
	int Ec;
	int n;
} G;

void g_ini(int n)
{
	G.n = n;
	G.Ec = 2;
}

void g_add(int u, int v, int w)
{
	G.E[G.Ec].src = u;
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

int min(int a, int b)
{
	return a < b ? a : b;
}

int g_dfs(int s, int lmt, int t)
{
	int f = 0, tf, i;
	if (s == t || lmt == 0)
		return lmt;
	for (i = G.N[s].edg; i; i = G.E[i].nxt)
		if (G.dist[G.E[i].dst] == G.dist[s] + 1) {
			tf = g_dfs(G.E[i].dst, min(lmt, G.E[i].cap), t);
			G.E[i].cap -= tf;
			G.E[i ^ 1].cap += tf;
			f += tf;
			lmt -= tf;
			if (lmt == 0)
				break;
		}
	return f;
}

int g_bfs(int s, int t)
{
	static int Q[300009];
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
	return G.dist[t] == 0x3f3f3f3f;
}

void g_dfs_path(int c)
{
	int i;
	G.N[c].vis = 1;
	printf("%d ", c);
	for (i = G.N[c].edg; i; i = G.E[i].nxt)
		g_dfs_path(G.E[i].dst);
}

int main(void)
{
	int n, m;
	int ss, st;
	int i;
	int ans = 0;
	int top;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d", &n, &m);

	ss = n * 2 + 3;
	st = n * 2 + 4;

	g_ini(n);

	for (i = 1; i <= n; ++i) {
		g_add2(ss, i, 1);
		g_add2(i + n, st, 1);
	}

	for (i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g_add2(u, v + n, 1);
	}

	while (g_bfs(ss, st) == 0)
		ans += g_dfs(ss, 0x3f3f3f3f, st);

	top = G.Ec;
	memset(G.N + 1, 0, sizeof(G.N[0]) * n);
	for (i = 2; i < top; i += 2)
		if (G.E[i].src <= n && G.E[i].dst > n && G.E[i].dst <= n * 2
		    && G.E[i].cap == 0)
			g_add(G.E[i].src, G.E[i].dst - n, 0);

	for (i = 1; i <= n; ++i)
		if (!G.N[i].vis) {
			g_dfs_path(i);
			putchar('\n');
		}

	printf("%d\n", n - ans);
	return 0;
}
