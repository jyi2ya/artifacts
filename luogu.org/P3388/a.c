#include <stdio.h>

struct {
	struct {
		int edg, dfn, low, fa, is_cut;
	} N[20009];
	struct {
		int dst, nxt;
	} E[200009];
	struct {
		int id, num;
	} rt;
	int cnt;
	int Ec;
	int n;
} G;

void g_ini(int n)
{
	G.cnt = 1;
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

int min(int a, int b)
{
	return a < b ? a : b;
}

void g_dfs(int rt)
{
	int i;
	G.N[rt].low = G.N[rt].dfn = G.cnt++;
	for (i = G.N[rt].edg; i; i = G.E[i].nxt) {
		int t = G.E[i].dst;
		if (t != G.N[rt].fa) {
			if (!G.N[t].dfn) {
				G.N[t].fa = rt;
				g_dfs(t);
				G.N[rt].low = min(G.N[rt].low, G.N[t].low);
				if (G.N[t].low >= G.N[rt].dfn && rt != G.rt.id)
					G.N[rt].is_cut = 1;
				if (rt == G.rt.id)
					++G.rt.num;
			}
			G.N[rt].low = min(G.N[rt].low, G.N[t].dfn);
		}
	}
	if (G.rt.num >= 2 && rt == G.rt.id)
		G.N[rt].is_cut = 1;
}

int main(void)
{
	int n, m;
	int i;
	int cnt = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	g_ini(n);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		g_add2(u, v);
	}
	for (i = 1; i <= n; ++i)
		if (!G.N[i].dfn) {
			G.rt.id = i;
			G.rt.num = 0;
			g_dfs(i);
		}
	for (i = 1; i <= n; ++i)
		if (G.N[i].is_cut)
			++cnt;
	printf("%d\n", cnt);
	for (i = 1; i <= n; ++i)
		if (G.N[i].is_cut)
			printf("%d ", i);
	putchar('\n');
	return 0;
}
