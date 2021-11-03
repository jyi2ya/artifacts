#include <stdio.h>

struct {
	struct {
		long long add, sum;
	} N[400009];
	int n;

	int l, r;
	long long add;
} S;

void s_ini(int n)
{
	S.n = n;
}

void s_pd(int rt, int l, int r)
{
	if (S.N[rt].add) {
		int m = l + (r - l) / 2;
		S.N[rt << 1].add += S.N[rt].add;
		S.N[rt << 1].sum += S.N[rt].add * (m - l + 1);
		S.N[rt << 1 | 1].add += S.N[rt].add;
		S.N[rt << 1 | 1].sum += S.N[rt].add * (r - m);
		S.N[rt].add = 0;
	}
}

void s_mt(int rt, int l, int r)
{
	if  (r >= l)
		S.N[rt].sum = S.N[rt << 1].sum + S.N[rt << 1 | 1].sum;
}

void s_add_r(int rt, int l, int r)
{
	if (S.l <= l && r <= S.r) {
		S.N[rt].add += S.add;
		S.N[rt].sum += S.add * (r - l + 1);
	} else {
		int m = l + (r - l) / 2;
		s_pd(rt, l, r);
		if (S.l <= m)
			s_add_r(rt << 1, l, m);
		if (m < S.r)
			s_add_r(rt << 1 | 1, m + 1, r);
		s_mt(rt, l, r);
	}
}

void s_add(int l, int r, long long add)
{
	S.l = l;
	S.r = r;
	S.add = add;
	s_add_r(1, 1, S.n);
}

long long s_qry_r(int rt, int l, int r)
{
	long long ans = 0;
	if (S.l <= l && r <= S.r) {
		ans = S.N[rt].sum;
	} else {
		int m = l + (r - l) / 2;
		s_pd(rt, l, r);
		if (S.l <= m)
			ans = s_qry_r(rt << 1, l, m);
		if (m < S.r)
			ans += s_qry_r(rt << 1 | 1, m + 1, r);
	}
	return ans;
}

long long s_qry(int l, int r)
{
	S.l = l;
	S.r = r;
	return s_qry_r(1, 1, S.n);
}

struct {
	struct {
		int dst, nxt;
	} E[200009];
	int Ec;
	struct {
		int fa, dpt, siz, son, edg, top, id;
	} N[100009];
	int Nc;
	int n;
} G;

void g_ini(int n)
{
	s_ini(n);
	G.Ec = 1;
	G.Nc = 1;
	G.n = n;
}

void g_add(int u, int v)
{
	G.E[G.Ec].dst = v;
	G.E[G.Ec].nxt = G.N[u].edg;
	G.N[u].edg = G.Ec++;
}

void g_dfs1(int rt)
{
	int i;
	G.N[rt].siz = 1;
	for (i = G.N[rt].edg; i; i = G.E[i].nxt)
		if (G.N[rt].fa != G.E[i].dst) {
			int t = G.E[i].dst;
			G.N[t].dpt = G.N[rt].dpt + 1;
			G.N[t].fa = rt;
			g_dfs1(t);
			G.N[rt].siz += G.N[t].siz;
			if (G.N[t].siz > G.N[G.N[rt].son].siz)
				G.N[rt].son = t;
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

void g_add_point(int x, long long add)
{
	s_add(G.N[x].id, G.N[x].id, add);
}

void g_add_tree(int x, long long add)
{
	s_add(G.N[x].id, G.N[x].id + G.N[x].siz - 1, add);
}

void g_swp(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

long long g_qry_path(int x)
{
	int y = 1;
	long long ans = 0;
	while (G.N[x].top != G.N[y].top) {
		if (G.N[G.N[x].top].dpt < G.N[G.N[y].top].dpt)
			g_swp(&x, &y);
		ans += s_qry(G.N[G.N[x].top].id, G.N[x].id);
		x = G.N[G.N[x].top].fa;
	}
	if (G.N[x].dpt > G.N[y].dpt)
		g_swp(&x, &y);
	ans += s_qry(G.N[x].id, G.N[y].id);
	return ans;
}

int main(void)
{
	int n, m;
	int i;
	static long long val[100009];
#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
		scanf("%lld", &val[i]);
	g_ini(n);
	for (i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g_add(u, v);
		g_add(v, u);
	}
	g_dvd();
	for (i = 1; i <= n; ++i)
		g_add_point(i, val[i]);
	while (m--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int x;
			long long a;
			scanf("%d%lld", &x, &a);
			g_add_point(x, a);
		} else if (op == 2) {
			int x;
			long long a;
			scanf("%d%lld", &x, &a);
			g_add_tree(x, a);
		} else {
			int x;
			scanf("%d", &x);
			printf("%lld\n", g_qry_path(x));
		}
	}
	return 0;
}
