#include <stdio.h>
#include <stdlib.h>

struct {
	struct {
		int l, r;
		int siz;
	} N[8000009];
	int Nc;
	int n;
	int x;
} T;

int t_alc(void)
{
	return T.Nc++;
}

void t_ini(void)
{
	T.Nc = 3;
}

void t_ins_r(int rt)
{
	if (T.n < 0) {
		++T.N[rt].siz;
		return;
	}
	--T.n;
	if (T.x & (1 << (T.n + 1))) {
		if (!T.N[rt].r)
			T.N[rt].r = t_alc();
		t_ins_r(T.N[rt].r);
	} else {
		if (!T.N[rt].l)
			T.N[rt].l = t_alc();
		t_ins_r(T.N[rt].l);
	}
	++T.N[rt].siz;
}

void t_ins(int rt, int x)
{
	T.n = 30;
	T.x = x;
	t_ins_r(rt);
}

int t_dfs2(int r1, int r2)
{
	int ans = 0;
	int ls1 = T.N[r1].l, rs1 = T.N[r1].r;
	int ls2 = T.N[r2].l, rs2 = T.N[r2].r;
	--T.N[r1].siz;
	--T.N[r2].siz;
	if (T.n < 0)
		return 0;
	--T.n;
	if (T.N[ls1].siz && T.N[ls2].siz)
		ans = t_dfs2(ls1, ls2);
	else if (T.N[rs1].siz && T.N[rs2].siz)
		ans = t_dfs2(rs1, rs2);
	else if (T.N[ls1].siz && T.N[rs2].siz)
		ans = (1 << (T.n + 1)) + t_dfs2(ls1, rs2);
	else
		ans = (1 << (T.n + 1)) + t_dfs2(rs1, ls2);
	return ans;
}

int t_dfs(void)
{
	T.n = 30;
	return t_dfs2(1, 2);
}

int tmp[4000009];

int cmp(const void *a, const void *b)
{
	return *(int *)a < *(int *)b ? -1 : 1;
}

int main(void)
{
	int n;
	int i;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	t_ini();
	for (i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		t_ins(1, x);
	}
	for (i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		t_ins(2, x);
	}
	for (i = 0; i < n; ++i)
		tmp[i] = t_dfs();
	qsort(tmp, n, sizeof(tmp[0]), cmp);
	for (i = 0; i < n; ++i)
		printf("%d ", tmp[i]);
	putchar('\n');
	return 0;
}
