#include <stdio.h>
#include <string.h>

struct {
	struct {
		int edg, vis, can, can2;
	} N[1000009];
	struct {
		int dst, nxt;
	} E[2000009];
	int Ec;
} G;

void g_ini(void)
{
	G.Ec = 2;
}

void g_add(int u, int v)
{
	G.E[G.Ec].dst = v;
	G.E[G.Ec].nxt = G.N[u].edg;
	G.N[u].edg = G.Ec++;
}

void g_add2(int u, int v)
{
	g_add(u, v);
	g_add(v, u);
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int s, t;

void g_can(int cur)
{
	int i;
	if (G.N[cur].vis)
		return ;
	G.N[cur].vis = 1;
	G.N[cur].can2 = 1;
	for (i = G.N[cur].edg; i; i = G.E[i].nxt)
		if (i & 1)
			g_can(G.E[i].dst);
}

int g_dis(void)
{
	static int Q[1000009];
	static int dis[1000009];
	memset(dis, 0x3f, sizeof(dis));
	int top = 0, bot = 0;
	Q[top++] = s;
	dis[s] = 0;
	while (top != bot) {
		int i;
		int c = Q[bot++];
		for (i = G.N[c].edg; i; i = G.E[i].nxt)
			if (!(i & 1) && dis[G.E[i].dst] > dis[c] + 1 &&
					G.N[G.E[i].dst].can) {
				dis[G.E[i].dst] = dis[c] + 1;
				Q[top++] = G.E[i].dst;
			}
	}
	return dis[t];
}

int main(void)
{
	int n, m;
	int i, j;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d", &n, &m);
	g_ini();
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		g_add2(u, v);
	}
	scanf("%d%d", &s, &t);

	g_can(t);
	for (i = 1; i <= n; ++i) {
		G.N[i].can = G.N[i].can2;
		for (j = G.N[i].edg; j; j = G.E[j].nxt)
			if (!(j & 1) && !G.N[G.E[j].dst].can2)
				G.N[i].can = 0;
	}

	printf("%d\n", g_dis());
	return 0;
}
