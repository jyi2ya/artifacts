#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long llmax(long long a, long long b)
{
	return a > b ? a : b;
}

struct {
	struct {
		long long l, r;
		int e;
		int f;
	} N[200009];

	struct edge {
		int d;
		int n;
	} E[500009];

	int t;
	int n;
} G;

void g_init(int n)
{
	int i;
	for (i = 1; i <= n; ++i)
		G.N[i].e = -1;
	G.t = 0;
	G.n = n;
}

void g_add(int u, int v)
{
	G.E[G.t].d = v;
	G.E[G.t].n = G.N[u].e;
	G.N[u].e = G.t++;
}

long long mem[200009][2];
long long g_dfs(int r, int is_l)
{
	int i;
	long long ans = 0;
	long long cur = (is_l ? G.N[r].l : G.N[r].r);
	if (mem[r][is_l] >= 0)
		return mem[r][is_l];
	for (i = G.N[r].e; i >= 0; i = G.E[i].n)
		if (G.E[i].d != G.N[r].f) {
			G.N[G.E[i].d].f = r;
			ans += llmax(llabs(G.N[G.E[i].d].l - cur) + g_dfs(G.E[i].d, 1),
				llabs(G.N[G.E[i].d].r - cur) + g_dfs(G.E[i].d, 0));
		}
	return mem[r][is_l] = ans;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		int i;
		scanf("%d", &n);
		g_init(n);
		for (i = 1; i < n; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			g_add(u, v);
			g_add(v, u);
		}
		for (i = 1; i <= n; ++i)
			scanf("%lld%lld", &G.N[i].l, &G.N[i].r);
		memset(mem, -1, sizeof(mem));
		printf("%lld\n", llmax(g_dfs(1, 1), g_dfs(1, 0)));
	}
	return 0;
}
