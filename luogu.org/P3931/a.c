#include <stdio.h>
#include <string.h>

#define NMAX (100009)
#define INF (0x3f3f3f3f)

struct E {
	int d;
	int c;
	int n;
};

struct N {
	int f;
	int e;
};

int SS;
int ST;

struct N N[NMAX];
struct E E[NMAX * 4];
int Etop = 2;

void add_edge(int u, int v, int w)
{
	E[Etop].d = v;
	E[Etop].c = w;
	E[Etop].n = N[u].e;
	N[u].e = Etop++;
}

void dfs_info(int r)
{
	int i;
	int cnt = 0;
	static int vis[NMAX];
	vis[r] = 1;
	for (i = N[r].e; i; i = E[i].n)
		if (!vis[E[i].d]) {
			if (E[i].c == 0) {
				E[i].c = E[i ^ 1].c;
				E[i ^ 1].c = 0;
			}
			++cnt;
			N[E[i].d].f = i;
			dfs_info(E[i].d);
		}
	if (cnt == 0) {
		add_edge(r, ST, INF);
		add_edge(ST, r, 0);
	}
}

int D[NMAX];

int min(int a, int b)
{
	return a < b ? a : b;
}

int dfs(int c, int lmt)
{
	int f = 0;
	int i;
	if (c == ST)
		return lmt;
	for (i = N[c].e; i; i = E[i].n)
		if (E[i].c && D[E[i].d] == D[c] + 1) {
			int tf = dfs(E[i].d, min(lmt, E[i].c));
			f += tf;
			E[i ^ 1].c += tf;
			E[i].c -= tf;
			lmt -= tf;
			if (lmt == 0)
				break;
		}
	return f;
}

int bfs(void)
{
	static int que[NMAX];
	static int inq[NMAX];
	int top = 0, bot = 0;
	memset(D, 0x3f, sizeof(D));
	D[SS] = 0;
	que[top++] = SS;
	inq[SS] = 1;
	while (top != bot) {
		int c = que[bot++];
		int i;
		inq[c] = 0;
		if (bot == NMAX)
			bot = 0;
		for (i = N[c].e; i; i = E[i].n)
			if (!inq[E[i].d] && E[i].c && D[E[i].d] > D[c] + 1) {
				D[E[i].d] = D[c] + 1;
				que[top++] = E[i].d;
				inq[E[i].d] = 1;
				if (top == NMAX)
					top = 0;
			}
	}
	return D[ST] == INF;
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

	scanf("%d%d", &n, &SS);
	for (i = 1; i < n; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, 0);
	}

	N[SS].f = -1;
	dfs_info(SS);

	while (bfs() == 0) {
		int f;
		while ((f = dfs(SS, INF)) > 0)
			ans += f;
	}

	printf("%d\n", ans);

	return 0;
}
