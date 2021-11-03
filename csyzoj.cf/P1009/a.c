/*
 * 题意：
 * 给定一棵大小为 n 的树，求一种方案将其一分为二，使其一大小为 a ，另一大小为 b 。
 * 无解输出 -1 。
 *
 * 实际上就是求一棵树中有无大小为 a 或 b 的子树。假设该树有一子树大小为 a ，需对此树以 [1, a]
 * 编号。对所有子树，保证其根上的编号大于其子树中编号的最大值。以此，在其子树被吃完前可保证树根
 * 不断。为避免重复，可在递归时给每一子树分配一个区间 [l, r] ，规定该子树中所有结点的编号必须在
 * [l, r] 内。
 *
 * 可以 O(n) 实现。
 */

#include <stdio.h>

struct {
	struct {
		int dst, nxt;
	} E[200009];
	int Ec;
	struct {
		int siz, edg, fa, id;
	} N[100009];
	int n;
	int flag;
} G;

void g_ini(int n)
{
	G.n = n;
	G.Ec = 1;
}

void g_add(int u, int v)
{
	G.E[G.Ec].dst = v;
	G.E[G.Ec].nxt = G.N[u].edg;
	G.N[u].edg = G.Ec++;
}

void g_dfs_info(int rt)
{
	int i;
	G.N[rt].siz = 1;
	for (i = G.N[rt].edg; i; i = G.E[i].nxt)
		if (G.E[i].dst != G.N[rt].fa) {
			int t = G.E[i].dst;
			G.N[t].fa = rt;
			g_dfs_info(t);
			G.N[rt].siz += G.N[t].siz;
		}
}

void g_dfs_number(int rt, int l, int r)
{
	int i;
	G.N[rt].id = r * G.flag;
	for (i = G.N[rt].edg; i; i = G.E[i].nxt)
		if (G.E[i].dst != G.N[rt].fa) {
			int t = G.E[i].dst;
			g_dfs_number(t, l, l + G.N[t].siz - 1);
			l += G.N[t].siz;
		}
}

int main(void)
{
	int n, a, b;
	int i;

	scanf("%d%d%d", &n, &a, &b);
	g_ini(n);
	for (i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g_add(u, v);
		g_add(v, u);
	}
	g_dfs_info(1);
	for (i = 1; i <= n; ++i)
		if (G.N[i].siz == a || G.N[i].siz == b)
			break;
	if (G.N[i].siz == a) {
		G.flag = 1;
		g_dfs_number(i, 1, a);
		G.N[G.N[i].fa].fa = i;
		g_dfs_info(G.N[i].fa);
		G.flag = -1;
		g_dfs_number(G.N[i].fa, 1, b);
		for (i = 1; i <= n; ++i)
			printf("%d\n", G.N[i].id);
	} else if (G.N[i].siz == b) {
		G.flag = -1;
		g_dfs_number(i, 1, b);
		G.N[G.N[i].fa].fa = i;
		g_dfs_info(G.N[i].fa);
		G.flag = 1;
		g_dfs_number(G.N[i].fa, 1, a);
		for (i = 1; i <= n; ++i)
			printf("%d\n", G.N[i].id);
	} else {
		puts("-1");
	}
	return 0;
}
