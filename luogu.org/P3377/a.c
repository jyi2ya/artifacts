#include <stdio.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

struct {
	struct {
		int dis, val, fa;
		int l, r;
	} N[1000009];
	int Nc;
} L;

void l_ini(void)
{
	L.Nc = 1;
}

#define ls L.N[x].l
#define rs L.N[x].r
int l_mgr(int x, int y)
{
	if (!x || !y)
		return x | y;
	if (L.N[x].val > L.N[y].val || (L.N[x].val == L.N[y].val && x > y))
		swap(&x, &y);
	rs = l_mgr(rs, y);
	if (L.N[ls].dis < L.N[rs].dis)
		swap(&ls, &rs);
	L.N[ls].fa = L.N[rs].fa = L.N[x].fa = x;
	L.N[x].dis = L.N[rs].dis + 1;
	return x;
}

int l_del(int x)
{
	L.N[x].val = -1;
	L.N[ls].fa = ls;
	L.N[rs].fa = rs;
	return L.N[x].fa = l_mgr(L.N[x].l, L.N[x].r);
}
#undef ls
#undef rs

int l_qry(int x)
{
	return L.N[x].val;
}

int l_fnd(int x)
{
	return L.N[x].fa == x ? x : (L.N[x].fa = l_fnd(L.N[x].fa));
}

void l_prt(int rt)
{
	if (!rt)
		return ;
	printf("%d(%d) ", L.N[rt].val, L.N[rt].fa);
	l_prt(L.N[rt].l);
	l_prt(L.N[rt].r);
}

int main(void)
{
	int i;
	static int rt[1000009];
	int n, m;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d", &n, &m);
	l_ini();
	for (i = 1; i <= n; ++i) {
		int t;
		scanf("%d", &t);
		L.N[i].fa = i;
		L.N[i].val = t;
	}

	while (m--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			if (L.N[x].val == -1 || L.N[y].val == -1 ||
					l_fnd(x) == l_fnd(y))
				continue;
			rt[y] = rt[x] = l_mgr(l_fnd(x), l_fnd(y));
		} else {
			int x;
			scanf("%d", &x);
			if (L.N[x].val == -1) {
				puts("-1");
				continue;
			}
			printf("%d\n", l_qry(l_fnd(x)));
			l_del(l_fnd(x));
		}
	}
	return 0;
}
