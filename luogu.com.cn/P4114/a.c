#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

struct {
	struct {
		int max;
	} N[400009];
	int n;
	int idx, chg;
	int l, r;
} S;

void s_ini(int n)
{
	memset(&S, 0, sizeof(S));
	S.n = n;
}

void s_chg_r(int rt, int l, int r)
{
	if (l == r) {
		S.N[rt].max = S.chg;
	} else {
		int m = l + (r - l) / 2;
		if (S.idx <= m)
			s_chg_r(rt << 1, l, m);
		if (m < S.idx)
			s_chg_r(rt << 1 | 1, m + 1, r);
		S.N[rt].max = max(S.N[rt << 1].max, S.N[rt << 1 | 1].max);
	}
}

void s_chg(int idx, int chg)
{
	S.idx = idx;
	S.chg = chg;
	s_chg_r(1, 1, S.n);
}

int s_qry_r(int rt, int l, int r)
{
	int ans = 0;
	if (S.l <= l && r <= S.r) {
		ans = S.N[rt].max;
	} else {
		int m = l + (r - l) / 2;
		if (S.l <= m)
			ans = s_qry_r(rt << 1, l, m);
		if (m < S.r)
			ans = max(ans, s_qry_r(rt << 1 | 1, m + 1, r));
	}
	return ans;
}

int s_qry(int l, int r)
{
	S.l = l;
	S.r = r;
	if (l > r)
		return 0;
	return s_qry_r(1, 1, S.n);
}

struct {
	struct {
		int dst, nxt, id;
	} E[200009];
	int Emap[200009];
	int Ec;
	struct {
		int edg, fa, dpt, son, siz, feg, top, id;
	} N[100009];
	int Nc;
	int n;
} G;

void g_ini(int n)
{
	s_ini(n);
	memset(&G, 0, sizeof(G));
	G.Ec = 1;
	G.Nc = 1;
	G.n = n;
}

void g_add(int u, int v, int id)
{
	G.E[G.Ec].id = id;
	G.E[G.Ec].dst = v;
	G.E[G.Ec].nxt = G.N[u].edg;
	G.N[u].edg = G.Ec++;
}

void g_dfs1(int rt)
{
	int i;
	G.N[rt].siz = 1;
	for (i = G.N[rt].edg; i; i = G.E[i].nxt)
		if (G.E[i].dst != G.N[rt].fa) {
			int t = G.E[i].dst;
			G.Emap[G.E[i].id] = G.E[i].dst;
			G.N[t].fa = rt;
			G.N[t].dpt = G.N[rt].dpt + 1;
			G.N[t].feg = G.E[i].id;
			g_dfs1(t);
			if (G.N[t].siz > G.N[G.N[rt].son].siz)
				G.N[rt].son = t;
			G.N[rt].siz += G.N[t].siz;
		}
}

void g_dfs2(int rt)
{
	int i;
	G.N[rt].id = G.Nc++;
	if (G.N[rt].siz > 1) {
		G.N[G.N[rt].son].top = G.N[rt].top;
		g_dfs2(G.N[rt].son);
	}
	for (i = G.N[rt].edg; i; i = G.E[i].nxt)
		if (G.E[i].dst != G.N[rt].fa && G.E[i].dst != G.N[rt].son) {
			G.N[G.E[i].dst].top = G.E[i].dst;
			g_dfs2(G.E[i].dst);
		}
}

void g_dvd(void)
{
	g_dfs1(1);
	G.N[1].top = 1;
	g_dfs2(1);
}

void g_chg(int edg, int chg)
{
	s_chg(G.N[G.Emap[edg]].id, chg);
}

void g_swp(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int g_qry(int x, int y)
{
	int ans = 0;
	if (x == y)
		return 0;
	while (G.N[x].top != G.N[y].top) {
		if (G.N[G.N[x].top].dpt < G.N[G.N[y].top].dpt)
			g_swp(&x, &y);
		ans = max(ans, s_qry(G.N[G.N[x].top].id, G.N[x].id));
		x = G.N[G.N[x].top].fa;
	}
	if (G.N[x].dpt > G.N[y].dpt)
		g_swp(&x, &y);
	ans = max(ans, s_qry(G.N[x].id + 1, G.N[y].id));
	return ans;
}

void solve(void)
{
	int n;
	int i;
	char cmd[109];
	static int w[100009];
	scanf("%d", &n);
	g_ini(n);
	for (i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d%d", &u, &v, &w[i]);
		g_add(u, v, i);
		g_add(v, u, i);
	}
	g_dvd();
	for (i = 1; i < n; ++i)
		g_chg(i, w[i]);
	while (scanf("%s", cmd) == 1 && cmd[0] != 'D') {
		int x, y;
		scanf("%d%d", &x, &y);
		if (cmd[0] == 'Q')
			printf("%d\n", g_qry(x, y));
		else
			g_chg(x, y);
	}
}

int main(void)
{
	/*
	   int T;
	   */
#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
	/*
	   scanf("%d", &T);
	   while (T--)
	   */
	solve();
	return 0;
}
