#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX (2000009)

struct edge {
	int d;
	int w;
	int n;
};

struct node {
	int f;
	int s;
	int e;
};

struct edge E[NMAX * 4];
int Etop;
struct node G[NMAX];
int n;

void G_init(void)
{
	int i;
	for (i = 1; i <= n; ++i) {
		G[i].f = -1;
		G[i].s = 0;
		G[i].e = -1;
	}
}

void edge_add(int u, int v, int w)
{
	E[Etop].d = v;
	E[Etop].w = w;
	E[Etop].n = G[u].e;
	G[u].e = Etop++;
}

void dfs_info(int root)
{
	int i;
	G[root].s = 1;
	for (i = G[root].e; i != -1; i = E[i].n)
		if (E[i].d != G[root].f) {
			G[E[i].d].f = root;
			dfs_info(E[i].d);
			G[root].s += G[E[i].d].s;
		}
}

long long dfs_ans(int root)
{
	int i;
	long long ans = 0;
	for (i = G[root].e; i != -1; i = E[i].n)
		if (E[i].d != G[root].f) {
			ans += dfs_ans(E[i].d);
			ans += llabs((n - G[E[i].d].s) - G[E[i].d].s) * E[i].w;
		}
	return ans;
}

int main(void)
{
	int i;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d", &n);
	G_init();
	for (i = 1; i < n; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edge_add(u, v, w);
		edge_add(v, u, w);
	}

	dfs_info(1);
	printf("%lld\n", dfs_ans(1));

#ifdef DEBUG
	fclose(stdin);
#endif
	return 0;
}
