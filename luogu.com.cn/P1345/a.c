#include <stdio.h>
#include <string.h>

#define INF 1000000
#define EMAX 60000
#define NMAX 1000

typedef struct edge {
	int t, c, n;
} edge;

edge E[EMAX];
int D[NMAX];
int Etop = NMAX;

void addedge(int f, int t, int c);
int bfs(int s, int t);
int dfs(int s, int t, int l);
int min(int a, int b);

int main(void)
{
	int N, M, c1, c2, i, u, v, a = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d%d%d", &N, &M, &c1, &c2);
	for (i = 1; i <= N; ++i) {
		addedge(i * 2, i * 2 + 1, 1);
		addedge(i * 2 + 1, i * 2, 0);
		/*
		addedge(i * 2 + 1, i * 2, 1);
		addedge(i * 2, i * 2 + 1, 0);
		*/
	}
	while (M--) {
		scanf("%d%d", &u, &v);
		addedge(u * 2 + 1, v * 2, INF);
		addedge(v * 2, u * 2 + 1, 0);
		addedge(v * 2 + 1, u * 2, INF);
		addedge(u * 2, v * 2 + 1, 0);
	}

	while (bfs(c1 * 2 + 1, c2 * 2))
		a += dfs(c1 * 2 + 1, c2 * 2, INF);

	printf("%d\n", a);
	return 0;
}

int Q[EMAX], Qtop, Qbot;

int dfs(int s, int t, int l)
{
	int f = 0, tf, i;

	if (l == 0 || s == t)
		return l;
	for (i = E[s].n; i; i = E[i].n)
		if (D[E[i].t] == D[s] + 1) {
			tf = dfs(E[i].t, t, min(E[i].c, l));

			E[i].c -= tf;
			E[i ^ 1].c += tf;
			f += tf;
			l -= tf;
		}
	return f;
}

int bfs(int s, int t)
{
	int c, i;

	memset(D, 0x7f, sizeof(D));
	Qtop = 0, Qbot = 0, Q[Qtop++] = s, D[s] = 0;
	while (Qtop != Qbot) {
		c = Q[Qbot++];
		for (i = E[c].n; i; i = E[i].n)
			if (E[i].c && D[E[i].t] > D[c] + 1) {
				Q[Qtop++] = E[i].t;
				D[E[i].t] = D[c] + 1;
			}
	}

	return D[t] != 0x7f7f7f7f;
}

void addedge(int f, int t, int c)
{
	E[Etop].c = c;
	E[Etop].t = t;
	E[Etop].n = E[f].n;
	E[f].n = Etop++;
}

int min(int a, int b)
{
	return a < b ? a : b;
}
