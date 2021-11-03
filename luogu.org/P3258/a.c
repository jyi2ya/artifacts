#include <stdio.h>

struct {
	struct {
		int add, sum;
	} N[3000009];
	int l, r;
	int val;
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
		S.N[rt].sum += (r - l + 1) * S.val;
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

void s_add(int l, int r, int val)
{
	S.l = l;
	S.r = r;
	S.val = val;
	s_add_r(1, 1, S.n);
}

int s_qry_r(int rt, int l, int r)
{
	int ans = 0;
	if (S.l <= l && r <= S.r) {
		ans = S.N[rt].sum;
	} else {
		int m = l + (r - l) / 2;
		s_pd(rt, l, r);
		if (S.l <= m)
			ans += s_qry_r(rt << 1, l, m);
		if (m < S.r)
			ans += s_qry_r(rt << 1 | 1, m + 1, r);
	}
	return ans;
}

int s_qry(int l, int r)
{
	S.l = l;
	S.r = r;
	return s_qry_r(1, 1, S.n);
}

struct {
	struct {
		int fa, dpt, son, siz, id, edg, top;
	} N[3000009];
	int Nc;
	struct {
		int dst, nxt;
	} E[6000009];
	int Ec;
	int n;
} T;

void t_ini(int n)
{
	T.n = n;
	T.Ec = 2;
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
			T.N[t].fa = rt;
			T.N[t].dpt = T.N[rt].dpt + 1;
			t_dfs1(t);
			if (T.N[t].siz > T.N[T.N[rt].son].siz)
				T.N[rt].son = t;
			T.N[rt].siz += T.N[t].siz;
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
	T.Nc = 1;
	t_dfs1(1);
	T.N[1].fa = 1;
	T.N[1].top = 1;
	t_dfs2(1);
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void t_add_ln(int u, int v, int val)
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

int t_qry_pt(int u)
{
	return s_qry(T.N[u].id, T.N[u].id);
}

int main(void)
{
	int i;
	int n;
	static int order[3000009];

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	t_ini(n);
	for (i = 1; i <= n; ++i)
		scanf("%d", &order[i]);
	for (i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		t_add2(u, v);
	}
	t_dvd();

	for (i = 1; i < n; ++i)
		t_add_ln(order[i], order[i + 1], 1);
	for (i = 2; i <= n; ++i)
		t_add_ln(order[i], order[i], -1);

	for (i = 1; i <= n; ++i)
		printf("%d\n", t_qry_pt(i));
	return 0;
}
