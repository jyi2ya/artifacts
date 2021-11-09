#include <stdio.h>

int f[1009][1009];

struct {
	struct {
		int edg, val, fa;
	} N[1009];
	struct {
		int dst, nxt;
	} E[2009];
	int Ec;
	int n;
} T;

void t_ini(int n)
{
	T.n = n;
	T.Ec = 1;
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

int max(int a, int b)
{
	return a > b ? a : b;
}

int m;
void t_dfs(int rt)
{
	int i, j = 0, k;
	f[rt][1] = T.N[rt].val;
	for (i = T.N[rt].edg; i; i = T.E[i].nxt) {
		int d = T.E[i].dst;
		if (d != T.N[rt].fa) {
			t_dfs(d);
			for (j = m + 1; j >= 1; --j)
				for (k = 0; k < j; ++k)
					f[rt][j] = max(f[rt][j],
						       f[d][k] + f[rt][j - k]);
		}
	}
}

int main(void)
{
	int n;
	int i;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	t_ini(n);
	for (i = 1; i <= n; ++i) {
		int k, s;
		scanf("%d%d", &k, &s);
		t_add(k, i);
		T.N[i].fa = k;
		T.N[i].val = s;
	}
	T.N[0].fa = -1;
	t_dfs(0);
	printf("%d\n", f[0][m + 1]);
	return 0;
}
