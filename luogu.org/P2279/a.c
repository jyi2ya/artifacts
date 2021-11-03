#include <stdio.h>

int min(int a, int b)
{
	return a < b ? a : b;
}

struct {
	struct {
		int edg, mark, fa;
	} N[1009];
	struct {
		int dst, nxt;
	} E[2009];
	int Ec;
} G;

void g_ini(void)
{
	G.Ec = 1;
}

void g_add(int u, int v)
{
	G.E[G.Ec].dst = v;
	G.E[G.Ec].nxt = G.N[u].edg;
	G.N[u].edg = G.Ec++;
}

struct info {
	int id, dpt;
};

int g_is_covered(int rt, int cnt, int ref)
{
	int i;
	if (cnt < 0)
		return 0;
	if (G.N[rt].mark)
		return 1;
	for (i = G.N[rt].edg; i; i = G.E[i].nxt)
		if (G.E[i].dst != ref)
			if (g_is_covered(G.E[i].dst, cnt - 1, rt))
				return 1;
	return 0;
}

struct info g_dfs(int rt, int dpt)
{
	int i;
	struct info ans = { rt, dpt };
	if (g_is_covered(rt, 2, rt)) {
		ans.id = 0;
		ans.dpt = -1;
		if (G.N[rt].mark)
			return ans;
	}
	for (i = G.N[rt].edg; i; i = G.E[i].nxt)
		if (G.E[i].dst != G.N[rt].fa) {
			struct info tmp = g_dfs(G.E[i].dst, dpt + 1);
			if (tmp.dpt > ans.dpt)
				ans = tmp;
		}
	return ans;
}

void g_mark(int rt, int mk)
{
	int i;
	if (rt == mk) {
		G.N[rt].mark = 1;
		return ;
	}
	for (i = G.N[rt].edg; i; i = G.E[i].nxt)
		if (G.E[i].dst != G.N[rt].fa)
			g_mark(G.E[i].dst, mk);
}

int main(void)
{
	int n;
	int i;
	int ans = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d", &n);
	g_ini();
	G.N[1].fa = 1;
	for (i = 2; i <= n; ++i) {
		int fa;
		scanf("%d", &fa);
		g_add(fa, i);
		g_add(i, fa);
		G.N[i].fa = fa;
	}

	for (; ; ) {
		struct info cur = g_dfs(1, 0);
		if (cur.dpt < 0)
			break;
		g_mark(1, G.N[G.N[cur.id].fa].fa);
		++ans;
	}

	printf("%d\n", ans);
	return 0;
}
