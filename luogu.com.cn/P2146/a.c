#include <stdio.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

struct {
	struct {
		int sum, set;
	} N[1000009 << 2];
	int n;
	int l, r;
	int val;
} S;

void s_pd(int rt, int l, int r)
{
	if (l < r && S.N[rt].set >= 0) {
		int m = l + (r - l) / 2;
		S.N[rt << 1].set = S.N[rt].set;
		S.N[rt << 1].sum = S.N[rt].set * (m - l + 1);
		S.N[rt << 1 | 1].set = S.N[rt].set;
		S.N[rt << 1 | 1].sum = S.N[rt].set * (r - m);
		S.N[rt].set = -1;
	}
}

void s_mt(int rt, int l, int r)
{
	if (l < r)
		S.N[rt].sum = S.N[rt << 1].sum + S.N[rt << 1 | 1].sum;
}

void s_set_r(int rt, int l, int r)
{
	if (S.l <= l && r <= S.r) {
		S.N[rt].set = S.val;
		S.N[rt].sum = S.val * (r - l + 1);
	} else {
		int m = l + (r - l) / 2;
		s_pd(rt, l, r);
		if (S.l <= m)
			s_set_r(rt << 1, l, m);
		if (m < S.r)
			s_set_r(rt << 1 | 1, m + 1, r);
		s_mt(rt, l, r);
	}
}

void s_set(int l, int r, int val)
{
	S.l = l;
	S.r = r;
	S.val = val;
	s_set_r(1, 1, S.n);
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

void s_ini(int n)
{
	int i;
	S.n = n;
	for (i = 1; i <= (n << 2); ++i)
		S.N[i].set = -1;
}

struct {
	struct {
		int edg, fa, top, siz, son, id, dpt;
	} N[1000009];
	struct {
		int dst, nxt;
	} E[2000009];
	int Nc, Ec;
	int n;
} T;

void t_ini(int n)
{
	T.n = n;
	T.Ec = 2;
	T.Nc = 1;
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

void t_set_path(int u, int v, int val)
{
	while (T.N[u].top != T.N[v].top) {
		if (T.N[T.N[u].top].dpt < T.N[T.N[v].top].dpt)
			swap(&u, &v);
		s_set(T.N[T.N[u].top].id, T.N[u].id, val);
		u = T.N[T.N[u].top].fa;
	}
	if (T.N[u].dpt > T.N[v].dpt)
		swap(&u, &v);
	s_set(T.N[u].id, T.N[v].id, val);
}

int t_qry_path(int u, int v)
{
	int ans = 0;
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

void t_set_tree(int x, int val)
{
	s_set(T.N[x].id, T.N[x].id + T.N[x].siz - 1, val);
}

int t_qry_tree(int x)
{
	return s_qry(T.N[x].id, T.N[x].id + T.N[x].siz - 1);
}

int ins(int x)
{
	int ans = T.N[x].dpt - t_qry_path(x, 1) + 1;
	t_set_path(x, 1, 1);
	return ans;
}

int rem(int x)
{
	int ans = t_qry_tree(x);
	t_set_tree(x, 0);
	return ans;
}

int main(void)
{
	int i;
	int n;
	int q;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
	
	scanf("%d", &n);
	t_ini(n);
	for (i = 2; i <= n; ++i) {
		int d;
		scanf("%d", &d);
		t_add2(i, d + 1);
	}
	t_dvd();
	scanf("%d", &q);
	while (q--) {
		char cmd[20];
		int x;
		scanf("%s%d", cmd, &x);
		++x;
		if (cmd[0] == 'i')
			printf("%d\n", ins(x));
		else
			printf("%d\n", rem(x));
	}
	return 0;
}
