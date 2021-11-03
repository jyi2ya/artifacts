#include <stdio.h>
#include <string.h>

struct {
	int n;
	char v[3009][300];
} N;

void n_ini(void)
{
	N.n = 0;
}

int exists(const char *str)
{
	int i;
	for (i = 0; i < N.n; ++i)
		if (strcmp(N.v[i], str) == 0)
			return 1;
	return 0;
}

int id(const char *str)
{
	int i;
	for (i = 0; i < N.n; ++i)
		if (strcmp(N.v[i], str) == 0)
			return i;
	strcpy(N.v[N.n], str);
	return N.n++;
}

struct {
	struct {
		int edg;
	} N[3009];
	struct {
		int dst, nxt, cap;
	} E[10009];
	int Ec;
} G;

void g_ini(void)
{
	memset(&G, 0, sizeof(G));
	G.Ec = 2;
}

void g_add(int u, int v, int w)
{
#ifdef DEBUG
	printf("add: %s %s %d\n", N.v[u], N.v[v], w);
#endif
	G.E[G.Ec].dst = v;
	G.E[G.Ec].cap = w;
	G.E[G.Ec].nxt = G.N[u].edg;
	G.N[u].edg = G.Ec++;
}

int dist[3009];


int min(int a, int b)
{
	return a < b ? a : b;
}

int g_dfs(int s, int lmt, int t)
{
	int f = 0, tf, i;
	if (s == t || lmt == 0)
		return lmt;
	for (i = G.N[s].edg; i; i = G.E[i].nxt)
		if (dist[G.E[i].dst] > dist[s]) {
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
	static int que[300009];
	int tp = 0, bt = 0;
	memset(dist, 0x3f, sizeof(dist));
	dist[s] = 0;
	que[tp++] = s;
	while (tp != bt) {
		int c = que[bt++];
		int i;
		for (i = G.N[c].edg; i; i = G.E[i].nxt)
			if (G.E[i].cap && dist[G.E[i].dst] > dist[c] + 1) {
				dist[G.E[i].dst] = dist[c] + 1;
				que[tp++] = G.E[i].dst;
			}
	}
	return (dist[t] == 0x3f3f3f3f) ? 1 : 0;
}

int main_(void)
{
	int n;
	int numeqp;
	int i;
	int ans = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		char buf[300];
		scanf("%s", buf);
		g_add(id(buf), id("__target"), 1);
		g_add(id("__target"), id(buf), 0);
	}
	scanf("%d", &n);
	numeqp = n;
	for (i = 0; i < n; ++i) {
		char buf[300];
		scanf("%*s%s", buf);
		g_add(id("__source"), id(buf), 1);
		g_add(id(buf), id("__source"), 0);
	}
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		char from[300], to[300];
		scanf("%s%s", from, to);
		g_add(id(from), id(to), 0x3f3f3f3f);
		g_add(id(to), id(from), 0);
	}
	while (g_bfs(id("__source"), id("__target")) == 0)
		ans += g_dfs(id("__source"), 0x3f3f3f3f, id("__target"));
	printf("%d\n", numeqp - ans);
	return 0;
}

int start_(void)
{
	n_ini();
	g_ini();
	return main_();
}

int main(void)
{
	int T;
	int i;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &T);
	for (i = 0; i < T; ++i) {
		if (i)
			putchar('\n');
		start_();
	}

	return 0;
}
