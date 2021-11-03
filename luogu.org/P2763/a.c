#include <stdio.h>
#include <string.h>

struct {
	struct {
		int edg;
	} N[10009];
	struct {
		int src, dst, nxt, cap;
	} E[50009];
	int dist[10009];
	int Ec;
} G;

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

void g_ini(void)
{
	G.Ec = 2;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int g_dfs(int s, int t, int lmt)
{
	int f = 0, tf, i;
	if (s == t || lmt == 0)
		return lmt;
	for (i = G.N[s].edg; i; i = G.E[i].nxt)
		if (G.dist[G.E[i].dst] == G.dist[s] + 1) {
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

int g_bfs(int s, int t)
{
	static int Q[50009];
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

int main(void)
{
	int n, m = 0, k;
	int S, T;
	int i;
	int flow = 0;
	static int ans[2009][2009];
	static int top[2009];

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d", &k, &n);
	g_ini();
	S = n + k + 3;
	T = n + k + 4;

	for (i = 1; i <= k; ++i) {
		int tmp;
		scanf("%d", &tmp);
		m += tmp;
		g_add2(i, T, tmp);
	}

	for (i = 1; i <= n; ++i) {
		int p;
		g_add2(S, i + k, 1);
		scanf("%d", &p);
		while (p--) {
			int tmp;
			scanf("%d", &tmp);
			g_add2(i + k, tmp, 1);
		}
	}

	while (g_bfs(S, T) == 0)
		flow += g_dfs(S, T, 0x3f3f3f3f);

	if (flow != m) {
		puts("No Solution");
	} else {
		int j;
		for (j = 2; j < G.Ec; j += 2)
			if (G.E[j].cap == 0) {
				int t = G.E[j].dst;
				ans[t][top[t]++] = G.E[j].src - k;
			}
		for (i = 1; i <= k; ++i) {
			printf("%d: ", i);
			for (j = 0; j < top[i]; ++j)
				printf("%d ", ans[i][j]);
			putchar('\n');
		}
	}
	return 0;
}
