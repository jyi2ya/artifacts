#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

struct {
	struct {
		int val, fa, edg;
	} N[6009];
	struct {
		int nxt, dst;
	} E[12009];
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

int mem[6009][2];

int t_dfs(int rt, int atd)
{
	int ans = 0;
	int i;
	if (mem[rt][atd] >= 0)
		return mem[rt][atd];
	if (atd == 1) {
		ans += T.N[rt].val;
		for (i = T.N[rt].edg; i; i = T.E[i].nxt)
			if (T.E[i].dst != T.N[rt].fa)
				ans += t_dfs(T.E[i].dst, 0);
	} else {
		for (i = T.N[rt].edg; i; i = T.E[i].nxt)
			if (T.E[i].dst != T.N[rt].fa)
				ans += max(t_dfs(T.E[i].dst, 0), t_dfs(T.E[i].dst, 1));
	}
	return mem[rt][atd] = ans;
}

int main(void)
{
	int n;
	int i;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	t_ini(n);
	for (i = 1; i <= n; ++i) {
		int v;
		scanf("%d", &v);
		T.N[i].val = v;
	}
	for (i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		t_add2(u, v);
		T.N[u].fa = v;
	}
	for (i = 1; i <= n; ++i)
		if (T.N[i].fa == 0) {
			memset(mem, -1, sizeof(mem));
			printf("%d\n", max(t_dfs(i, 1), t_dfs(i, 0)));
			break;
		}
	return 0;
}
