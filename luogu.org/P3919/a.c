/*
 * 模板：主席树。
 */

#include <stdio.h>

#define MAX (1000009)
struct {
	struct {
		int val;
		int l, r;
	} N[MAX << 5];
	int n;
	int V[MAX];
	int Vc;
	int Nc;
} P;

int p_alc(int val)
{
	P.N[P.Nc].val = val;
	P.N[P.Nc].l = 0;
	P.N[P.Nc].r = 0;
	return P.Nc++;
}

void p_ini(int n)
{
	P.Vc = 0;
	P.n = n;
	P.Nc = 1;
}

int p_dup(int old)
{
	return P.V[old];
}

int p_qry(int rt, int l, int r, int pos)
{
	int m;
	if (l == r)
		return P.N[rt].val;
	m = l + (r - l) / 2;
	if (pos <= m)
		return p_qry(P.N[rt].l, l, m, pos);
	return p_qry(P.N[rt].r, m + 1, r, pos);
}

int p_mdf(int rt, int l, int r, int pos, int val)
{
	int nr = p_alc(0);
	if (l == r) {
		P.N[nr].val = val;
	} else {
		int m = l + (r - l) / 2;
		if (pos <= m) {
			P.N[nr].r = P.N[rt].r;
			P.N[nr].l = p_mdf(P.N[rt].l, l, m, pos, val);
		} else {
			P.N[nr].l = P.N[rt].l;
			P.N[nr].r = p_mdf(P.N[rt].r, m + 1, r, pos, val);
		}
	}
	return nr;
}

int p_bld(int l, int r)
{
	int nr = p_alc(0);
	if (l == r) {
		int x;
		scanf("%d", &x);
		P.N[nr].val = x;
	} else {
		int m = l + (r - l) / 2;
		P.N[nr].l = p_bld(l, m);
		P.N[nr].r = p_bld(m + 1, r);
	}
	return nr;
}

int main(void)
{
	int n, m;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	p_ini(n);
	P.V[P.Vc++] = p_bld(1, n);

	while (m--) {
		int v, op;
		scanf("%d%d", &v, &op);
		if (op == 1) {
			int loc, val;
			scanf("%d%d", &loc, &val);
			P.V[P.Vc++] = p_mdf(P.V[v], 1, n, loc, val);
		} else {
			int loc;
			scanf("%d", &loc);
			P.V[P.Vc++] = p_dup(v);
			printf("%d\n", p_qry(P.V[P.Vc - 1], 1, n, loc));
		}
	}
	return 0;
}
