#include <stdio.h>
#define Z(x) printf x

struct trie {
	int siz;
	int l, r;
};

struct trie T[12000000];
int Tc = 1;

int t_new(void)
{
	T[Tc].siz = 1;
	T[Tc].l = 0;
	T[Tc].r = 0;
	return Tc++;
}

int t_ins(int rt, unsigned x, int lvl)
{
	int ret = t_new();
	if (rt)
		T[ret].siz += T[rt].siz;
	if (lvl < 0)
		return ret;

	if (x >> lvl & 1) {
		T[ret].r = t_ins(T[rt].r, x, lvl - 1);
		T[ret].l = T[rt].l;
	} else {
		T[ret].r = T[rt].r;
		T[ret].l = t_ins(T[rt].l, x, lvl - 1);
	}

	return ret;
}

int t_qry(int lt, int rt, unsigned x, int lvl)
{
	unsigned ans = 0;
	if (lvl < 0)
		return 0;
	if (x >> lvl & 1) {
		if (T[T[rt].l].siz - T[T[lt].l].siz > 0)
			ans |= (1 << lvl) | t_qry(T[lt].l, T[rt].l, x, lvl - 1);
		else
			ans |= t_qry(T[lt].r, T[rt].r, x, lvl - 1);
	} else {
		if (T[T[rt].r].siz - T[T[lt].r].siz > 0)
			ans |= (1 << lvl) | t_qry(T[lt].r, T[rt].r, x, lvl - 1);
		else
			ans |= t_qry(T[lt].l, T[rt].l, x, lvl - 1);
	}
	return ans;
}

int main(void)
{
	int n, q;
	int i;
	static int version[2000009];

#ifndef ONLINE_JUDGE
	freopen("hugclose.in", "r", stdin);
#ifndef DEBUG
	freopen("hugclose.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	scanf("%d%d", &n, &q);
	for (i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);
		if (i)
			version[i] = t_ins(version[i - 1], t, 30);
		else
			version[i] = t_ins(0, t, 30);
	}

	while (q--) {
		int x, l, r;
		scanf("%d%d%d", &x, &l, &r);
		if (l == 0)
			printf("%d\n", t_qry(0, version[r], x, 30));
		else
			printf("%d\n", t_qry(version[l - 1],
						version[r], x, 30));
	}

	return 0;
}
