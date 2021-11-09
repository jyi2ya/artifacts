#include <stdio.h>

struct {
	struct {
		int edg, val, fa;
	} N[16009];
	struct {
		int dst, nxt;
	} E[32009];
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

int f[16009];

void t_dfs(int rt)
{
	int i;
	f[rt] = T.N[rt].val;
	for (i = T.N[rt].edg; i; i = T.E[i].nxt)
		if (T.E[i].dst != T.N[rt].fa) {
			T.N[T.E[i].dst].fa = rt;
			t_dfs(T.E[i].dst);
			if (f[T.E[i].dst] >= 0)
				f[rt] += f[T.E[i].dst];
		}
}

int main(void)
{
	int n;
	int i;
	int ans = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf("%d", &T.N[i].val);
	t_ini(n);
	for (i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		t_add2(u, v);
	}
	t_dfs(1);
	for (i = 1; i <= n; ++i)
		if (f[i] > ans)
			ans = f[i];
	printf("%d\n", ans);
	return 0;
}
