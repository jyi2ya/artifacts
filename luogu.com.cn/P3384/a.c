#include <stdio.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

long long mod;

struct {
	struct {
		long long sum, add;
	} N[400009];
	int n, l, r;
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
		S.N[rt << 1].add = (S.N[rt << 1].add + S.N[rt].add) % mod;
		S.N[rt << 1].sum = (S.N[rt << 1].sum + S.N[rt].add * (m - l + 1) % mod) % mod;
		S.N[rt << 1 | 1].add = (S.N[rt << 1 | 1].add + S.N[rt].add) % mod;
		S.N[rt << 1 | 1].sum = (S.N[rt << 1 | 1].sum + S.N[rt].add * (r - m) % mod)
				% mod;
		S.N[rt].add = 0;
	}
}

void s_mt(int rt, int l, int r)
{
	if (r > l)
		S.N[rt].sum = (S.N[rt << 1].sum + S.N[rt << 1 | 1].sum) % mod;
}

void s_add_r(int rt, int l, int r)
{
	if (S.l <= l && r <= S.r) {
		S.N[rt].add = (S.N[rt].add + S.add) % mod;
		S.N[rt].sum = (S.N[rt].sum + S.add * (r - l + 1) % mod) % mod;
	} else {
		int m = l + (r - l) / 2;
		s_pd(rt, l, r);
		if (S.l <= m)
			s_add_r(rt << 1, l, m);
		if (S.r > m)
			s_add_r(rt << 1 | 1, m + 1, r);
		s_mt(rt, l, r);
	}
}

void s_add(int l, int r, long long add)
{
	S.l = l;
	S.r = r;
	S.add = add % mod;
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
		if (S.r > m)
			ans += s_qry_r(rt << 1 | 1, m + 1, r);
	}
	return ans % mod;
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
		int edg, dpt, siz, fa, son, id, top;
	} N[100009];
	int Nc;
	int n;
	int rt;
} G;

void g_dfs1(int rt)
{
	int i;
	G.N[rt].siz = 1;
	for (i = G.N[rt].edg; i; i = G.E[i].nxt)
		if (G.E[i].dst != G.N[rt].fa) {
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
	s_ini(G.n);
	g_dfs1(G.rt);
	G.N[G.rt].top = G.rt;
	g_dfs2(G.rt);
}

void g_ini(int n, int rt)
{
	G.Ec = 1;
	G.Nc = 1;
	G.n = n;
	G.rt = rt;
}

void g_add(int u, int v)
{
	G.E[G.Ec].dst = v;
	G.E[G.Ec].nxt = G.N[u].edg;
	G.N[u].edg = G.Ec++;
}

void g_add_path(int u, int v, long long add)
{
	add %= mod;
	while (G.N[u].top != G.N[v].top) {
		if (G.N[G.N[u].top].dpt < G.N[G.N[v].top].dpt)
			swap(&u, &v);
		s_add(G.N[G.N[u].top].id, G.N[u].id, add);
		u = G.N[G.N[u].top].fa;
	}
	if (G.N[u].dpt > G.N[v].dpt)
		swap(&u, &v);
	s_add(G.N[u].id, G.N[v].id, add);
}

void g_add_tree(int x, long long add)
{
	s_add(G.N[x].id, G.N[x].id + G.N[x].siz - 1, add % mod);
}

long long g_qry_path(int u, int v)
{
	long long ans = 0;
	while (G.N[u].top != G.N[v].top) {
		if (G.N[G.N[u].top].dpt < G.N[G.N[v].top].dpt)
			swap(&u, &v);
		ans = (ans + s_qry(G.N[G.N[u].top].id, G.N[u].id)) % mod;
		u = G.N[G.N[u].top].fa;
	}
	if (G.N[u].dpt > G.N[v].dpt)
		swap(&u, &v);
	ans = (ans + s_qry(G.N[u].id, G.N[v].id)) % mod;
	return ans;
}

long long g_qry_tree(int x)
{
	return s_qry(G.N[x].id, G.N[x].id + G.N[x].siz - 1) % mod;
}

int main(void)
{
	int n, m, r;
	int i;
	static long long val[100009];
#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
	scanf("%d%d%d%lld", &n, &m, &r, &mod);
	for (i = 1; i <= n; ++i)
		scanf("%lld", &val[i]);
	g_ini(n, r);
	for (i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g_add(u, v);
		g_add(v, u);
	}
	g_dvd();
	for (i = 1; i <= n; ++i)
		g_add_path(i, i, val[i] % mod);
	while (m--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int x, y;
			long long z;
			scanf("%d%d%lld", &x, &y, &z);
			g_add_path(x, y, z);
		} else if (op == 2) {
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%lld\n", g_qry_path(x, y) % mod);
		} else if (op == 3) {
			int x;
			long long z;
			scanf("%d%lld", &x, &z);
			g_add_tree(x, z);
		} else if (op == 4) {
			int x;
			scanf("%d", &x);
			printf("%lld\n", g_qry_tree(x) % mod);
		}
	}
	return 0;
}
