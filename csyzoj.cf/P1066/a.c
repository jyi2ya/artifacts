#include <stdio.h>

struct {
	struct {
		int edg, val;
	} N[10009];
	struct {
		int dst, nxt;
	} E[20009];
	int Ec;
	int vis[10009];
} T;

void t_ini(void)
{
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

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

struct {
	int u, v;
} ans[1000009];
int top = 0;

void t_pul(int rt, int dst, int fa)
{
	int i;
	for (i = T.N[rt].edg; i; i = T.E[i].nxt)
		if (T.E[i].dst != fa)
			t_pul(T.E[i].dst, dst, rt);
	if (fa == -1)
		return ;
	if (T.N[rt].val == dst) {
		ans[top].u = rt;
		ans[top].v = fa;
		++top;
		swap(&T.N[rt].val, &T.N[fa].val);
	}
}

void t_dfs(int rt, int fa)
{
	int i;
	for (i = T.N[rt].edg; i; i = T.E[i].nxt)
		if (T.E[i].dst != fa)
			t_dfs(T.E[i].dst, rt);
	t_pul(rt, rt, -1);
}

int main(void)
{
	int n;
	int i;

#ifndef ONLINE_JUDGE
	freopen("tree.in", "r", stdin);
#ifndef DEBUG
	freopen("tree.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	t_ini();

	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf("%d", &T.N[i].val);
	for (i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		t_add2(u, v);
	}

	t_dfs(1, -1);

	printf("%d\n", top);
	for (i = 0; i < top; ++i)
		printf("%d %d\n", ans[i].u, ans[i].v);

	return 0;
}
