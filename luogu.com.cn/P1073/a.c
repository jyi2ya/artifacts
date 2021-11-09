#include <stdio.h>
#include <limits.h>

enum {
	unvis = 0,
	vising = 1,
	vised = 2,
};

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

struct {
	struct {
		int edg, val, vis, min, max;
	} N[100009];
	struct {
		int dst, nxt;
	} E[1000009];
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

int gans = 0;

void g_dfs(int rt, int mn, int pre)
{
	int i;
	int is_ret = 1;
	int mx;

	mn = min(mn, G.N[rt].val);
	if (G.N[rt].min > mn) {
		G.N[rt].min = mn;
		is_ret = 0;
	}

	mx = max(G.N[pre].max, G.N[rt].val - G.N[rt].min);
	if (mx > G.N[rt].max) {
		G.N[rt].max = mx;
		is_ret = 0;
	}

	if (is_ret)
		return ;

	for (i = G.N[rt].edg; i; i = G.E[i].nxt)
		g_dfs(G.E[i].dst, mn, rt);
}

int main(void)
{
	int n, m;
	int i;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i) {
		scanf("%d", &G.N[i].val);
		G.N[i].min = INT_MAX;
	}
	G.N[0].min = INT_MAX;
	G.N[0].max = INT_MIN;
	g_ini(n);
	while (m--) {
		int u, v;
		int typ;
		scanf("%d%d%d", &u, &v, &typ);
		if (typ == 1)
			g_add(u, v);
		else
			g_add2(u, v);
	}
	g_dfs(1, INT_MAX, 0);
	printf("%d\n", G.N[n].max);
	return 0;
}
