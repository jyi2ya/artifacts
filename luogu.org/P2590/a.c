/*
 * 树链剖分模板题。
 *
 * 交 wa 了一次，因为没看到边权可以为负数，求最大值的时候 ans 赋了 0 的初值。
 */

#include <stdio.h>

#define MIN (-40000)

int max(int a, int b)
{
	return a > b ? a : b;
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

struct {
	struct {
		long long max, sum;
	} N[30009 << 2];
	int n;
	int l, r;
	long long val;
} S;

void s_ini(int n)
{
	S.n = n;
}

void s_mt(int rt, int l, int r)
{
	if (l < r) {
		S.N[rt].sum = S.N[rt << 1].sum + S.N[rt << 1 | 1].sum;
		S.N[rt].max = max(S.N[rt << 1].max, S.N[rt << 1 | 1].max);
	}
}

void s_add_r(int rt, int l, int r)
{
	if (S.l <= l && r <= S.r) {
		S.N[rt].sum += S.val * (r - l + 1);
		S.N[rt].max += S.val;
	} else {
		int m = l + (r - l) / 2;
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

long long s_qry_sum_r(int rt, int l, int r)
{
	long long ans = 0;
	if (S.l <= l && r <= S.r) {
		ans = S.N[rt].sum;
	} else {
		int m = l + (r - l) / 2;
		if (S.l <= m)
			ans += s_qry_sum_r(rt << 1, l, m);
		if (m < S.r)
			ans += s_qry_sum_r(rt << 1 | 1, m + 1, r);
	}
	return ans;
}

long long s_qry_sum(int l, int r)
{
	S.l = l;
	S.r = r;
	return s_qry_sum_r(1, 1, S.n);
}

long long s_qry_max_r(int rt, int l, int r)
{
	long long ans = MIN;
	if (S.l <= l && r <= S.r) {
		ans = S.N[rt].max;
	} else {
		int m = l + (r - l) / 2;
		if (S.l <= m)
			ans = max(ans, s_qry_max_r(rt << 1, l, m));
		if (m < S.r)
			ans = max(ans, s_qry_max_r(rt << 1 | 1, m + 1, r));
	}
	return ans;
}

long long s_qry_max(int l, int r)
{
	S.l = l;
	S.r = r;
	return s_qry_max_r(1, 1, S.n);
}

struct {
	struct {
		int top, edg, id, son, siz, fa, dpt;
	} N[30009];
	struct {
		int dst, nxt;
	} E[60009];
	int Ec;
	int Nc;
} T;

void t_ini(int n)
{
	T.Nc = 1;
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

void t_add_val(int u, int v, long long val)
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

long long t_qry_sum(int u, int v)
{
	long long ans = 0;
	while (T.N[u].top != T.N[v].top) {
		if (T.N[T.N[u].top].dpt < T.N[T.N[v].top].dpt)
			swap(&u, &v);
		ans += s_qry_sum(T.N[T.N[u].top].id, T.N[u].id);
		u = T.N[T.N[u].top].fa;
	}
	if (T.N[u].dpt > T.N[v].dpt)
		swap(&u, &v);
	ans += s_qry_sum(T.N[u].id, T.N[v].id);
	return ans;
}

void t_mdf_val(int pos, int val)
{
	long long v = t_qry_sum(pos, pos);
	t_add_val(pos, pos, -v);
	t_add_val(pos, pos, val);
}

long long t_qry_max(int u, int v)
{
	long long ans = MIN;
	while (T.N[u].top != T.N[v].top) {
		if (T.N[T.N[u].top].dpt < T.N[T.N[v].top].dpt)
			swap(&u, &v);
		ans = max(ans, s_qry_max(T.N[T.N[u].top].id, T.N[u].id));
		u = T.N[T.N[u].top].fa;
	}
	if (T.N[u].dpt > T.N[v].dpt)
		swap(&u, &v);
	ans = max(ans, s_qry_max(T.N[u].id, T.N[v].id));
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
	for (i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		t_add2(u, v);
	}
	t_dvd();
	for (i = 1; i <= n; ++i) {
		int w;
		scanf("%d", &w);
		t_add_val(i, i, w);
	}
	scanf("%d", &q);
	while (q--) {
		char buf[12];
		int op1, op2;
		scanf("%s%d%d", buf, &op1, &op2);
		if (buf[1] == 'M')
			printf("%lld\n", t_qry_max(op1, op2));
		else if (buf[1] == 'S')
			printf("%lld\n", t_qry_sum(op1, op2));
		else
			t_mdf_val(op1, op2);
	}
	return 0;
}
