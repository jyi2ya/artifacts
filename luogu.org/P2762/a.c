/*
 * 这样建图：
 *
 * 源点  实验   设备   汇点
 *   .--->o------o----.
 *  /      ,----`      \
 * o----->o----->o----->o
 *  \           /
 *   `--->o----`
 *
 * 源点与实验间连容量为实验价值的边。
 * 实验和设备间连容量无限边。
 * 设备和汇点之间连容量为设备费用的边。
 *
 * 用实现总收益减去源点到汇点的最小割就行了。
 *
 * 源点：n + m + 3
 * 汇点：n + m + 4
 * 实验：1 .. m
 * 设备：m+1 .. m+n
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct {
	struct {
		int edg, vis;
	} N[10009];
	struct {
		int dst, nxt, cap;
	} E[50009];
	int dist[10009];
	int Ec;
} G;

void g_ini(void)
{
	G.Ec = 2;
}

void g_add(int u, int v, int w)
{
	G.E[G.Ec].dst = v;
	G.E[G.Ec].cap = w;
	G.E[G.Ec].nxt = G.N[u].edg;
	G.N[u].edg = G.Ec++;
}

void g_add2(int u, int v, int w)
{
	g_add(u, v, w);
	g_add(v, u, 0);
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int g_dfs(int s, int lmt, int t)
{
	int tf, f = 0, i;
	if (lmt == 0 || s == t)
		return lmt;
	for (i = G.N[s].edg; i; i = G.E[i].nxt)
		if (G.dist[G.E[i].dst] == G.dist[s] + 1) {
			tf = g_dfs(G.E[i].dst, min(lmt, G.E[i].cap), t);
			f += tf;
			lmt -= tf;
			G.E[i].cap -= tf;
			G.E[i ^ 1].cap += tf;
			if (lmt == 0)
				break;
		}
	return f;
}

int g_bfs(int s, int t)
{
	static int Q[50009];
	int top = 0, bot = 0;
	memset(G.dist, 0x3f, sizeof(G.dist));
	Q[top++] = s;
	G.dist[s] = 0;
	while (top != bot) {
		int c = Q[bot++];
		int i;
		for (i = G.N[c].edg; i; i = G.E[i].nxt)
			if (G.E[i].cap && G.dist[G.E[i].dst] > G.dist[c] + 1) {
				G.dist[G.E[i].dst] = G.dist[c] + 1;
				Q[top++] = G.E[i].dst;
			}
	}
	return G.dist[t] == 0x3f3f3f3f;
}

void g_final_dfs(int s)
{
	int i;
	if (G.N[s].vis)
		return ;
	G.N[s].vis = 1;
	for (i = G.N[s].edg; i; i = G.E[i].nxt)
		if (G.E[i].cap)
			g_final_dfs(G.E[i].dst);
}

int getint(void)
{
	int ans = 0;
	int ch;
	while (!isdigit(ch = getchar()) && ch != '\r' && ch != '\n')
		;
	if (ch == '\r' || ch == '\n')
		return EOF;
	ans = ch - '0';
	while (isdigit(ch = getchar()))
		ans = ans * 10 + ch - '0';
	ungetc(ch, stdin);
	return ans;
}

int main(void)
{
	int n, m;
	int ss, tt;
	int i;
	int ans = 0;
	int tot = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d", &m, &n);
	while (getint() != EOF)
		;
	ss = n + m + 3;
	tt = n + m + 4;
	g_ini();

	for (i = 1; i <= m; ++i) {
		int t;
		int val = getint();
		tot += val;
		g_add2(ss, i, val);
		while ((t = getint()) != EOF)
			g_add2(i, m + t, 0x3f3f3f3f);
	}

	for (i = 1; i <= n; ++i) {
		int val = getint();
		g_add2(m + i, tt, val);
	}

	while (g_bfs(ss, tt) == 0)
		ans += g_dfs(ss, 0x3f3f3f3f, tt);

	g_final_dfs(ss);
	for (i = 0; i <= m; ++i)
		if (G.N[i].vis)
			printf("%d ", i);
	putchar('\n');
	for (; i <= tt; ++i)
		if (G.N[i].vis && i != ss && i != tt)
			printf("%d ", i - m);
	putchar('\n');
	printf("%d\n", tot - ans);
	return 0;
}
