#include <stdio.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

struct {
	struct {
		long long sum, add;
	} N[1000009 << 2];
	int l, r;
	long long val;
	int n;
} S;

void s_ini(int n)
{
	S.n = n;
}

void s_pd(int rt, int l, int r)
{
	if (l < r) {
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
	if (l < r)
		S.N[rt].sum = S.N[rt << 1].sum + S.N[rt << 1 | 1].sum;
}

void s_add_r(int rt, int l, int r)
{
	if (S.l <= l && r <= S.r) {
		S.N[rt].add += S.val;
		S.N[rt].sum += S.val * (r - l + 1);
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

void s_add(int l, int r, long long val)
{
	S.l = l;
	S.r = r;
	S.val = val;
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
			ans += s_qry_r(rt << 1, l, m);
		if (m < S.r)
			ans += s_qry_r(rt << 1 | 1, m + 1, r);
		s_mt(rt, l, r);
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
		int top, edg, id, siz, son, dpt, fa;
	} N[1000009];
	struct {
		int dst, nxt;
	} E[2000009];
	int Nc, Ec;
} T;

void t_ini(int n)
{
	T.Nc = 1;
	T.Ec = 1;
	s_ini(n);
}

void t_add(int u, int v)
{
	T.E[T.Ec].dst = v;
	T.E[T.Ec].nxt = T.N[u].edg;
	T.N[u].edg = T.Ec++;
}

void t_add2(int u, int v)
{
	t_add(u, v);
	t_add(v, u);
}

void t_dfs1(int rt)
{
	int i;
	T.N[rt].siz = 1;
	for (i = T.N[rt].edg; i; i = T.E[i].nxt)
		if (T.E[i].dst != T.N[rt].fa) {
			int t = T.E[i].dst;
			T.N[t].dpt = T.N[rt].dpt + 1;
			T.N[t].fa = rt;
			t_dfs1(t);
			T.N[rt].siz += T.N[t].siz;
			if (T.N[t].siz > T.N[T.N[rt].son].siz)
				T.N[rt].son = t;
		}
}

void t_dfs2(int rt)
{
	int i;
	T.N[rt].id = T.Nc++;
	if (T.N[rt].siz > 1) {
		T.N[T.N[rt].son].top = T.N[rt].top;
		t_dfs2(T.N[rt].son);
	}
	for (i = T.N[rt].edg; i; i = T.E[i].nxt)
		if (T.E[i].dst != T.N[rt].fa && T.E[i].dst != T.N[rt].son) {
			T.N[T.E[i].dst].top = T.E[i].dst;
			t_dfs2(T.E[i].dst);
		}
}

void t_dvd(void)
{
	t_dfs1(1);
	T.N[1].top = 1;
	T.N[1].fa = 1;
	t_dfs2(1);
}

void t_add_path(int u, int v, long long val)
{
	while (T.N[u].top != T.N[v].top) {
		if (T.N[T.N[u].top].dpt < T.N[T.N[v].top].dpt)
			swap(&u, &v);
		s_add(T.N[T.N[u].top].id, T.N[u].id, val);
		u = T.N[T.N[u].top].fa;
	}
	if (T.N[u].dpt > T.N[v].dpt)
		swap(&u, &v);
	s_add(T.N[u].id, T.N[v].id, val);
}

long long t_qry_path(int u, int v)
{
	long long ans = 0;
	while (T.N[u].top != T.N[v].top) {
		if (T.N[T.N[u].top].dpt < T.N[T.N[v].top].dpt)
			swap(&u, &v);
		ans += s_qry(T.N[T.N[u].top].id, T.N[u].id);
		u = T.N[T.N[u].top].fa;
	}
	if (T.N[u].dpt > T.N[v].dpt)
		swap(&u, &v);
	ans += s_qry(T.N[u].id, T.N[v].id);
	return ans;
}

void t_add_tree(int x, long long val)
{
	s_add(T.N[x].id, T.N[x].id + T.N[x].siz - 1, val);
}

int main(void)
{
	int n, m;
	static long long val[1000009];
	int i;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d", &n, &m);
	t_ini(n);
	for (i = 1; i <= n; ++i)
		scanf("%lld", &val[i]);
	for (i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		t_add2(u, v);
	}
	t_dvd();
	for (i = 1; i <= n; ++i)
		t_add_path(i, i, val[i]);
	while (m--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int x;
			long long a;
			scanf("%d%lld", &x, &a);
			t_add_path(x, x, a);
		} else if (op == 2) {
			int x;
			long long a;
			scanf("%d%lld", &x, &a);
			t_add_tree(x, a);
		} else {
			int x;
			scanf("%d", &x);
			printf("%lld\n", t_qry_path(1, x));
		}
	}
	return 0;
}
