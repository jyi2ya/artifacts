#include <stdio.h>
#include <string.h>

#define NMAX 10009
#define MMAX 20009

#define PMAX (4 * NMAX + 9)
#define EMAX (16 * NMAX + 4 * MMAX + 18)

#define SS (4 * NMAX + 1)
#define ST (4 * NMAX + 2)

#define INF 20000000

typedef struct edge {
	int t, c, n;
} edge;

edge E[EMAX];
int Etop = PMAX - 1;
int D[PMAX];

void addedge(int f, int t, int c);
int min(int a, int b);
int dfs(int s, int l);
int bfs(void);

int main(void)
{
	int N1, N2, N3, a = 0, i, M, u, v;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d%d", &N1, &N2, &N3);

	for (i = 1; i <= N2; ++i) {
		addedge(SS, i, 1);
		addedge(i, SS, 0);
	}
	scanf("%d", &M);
	for (i = 1; i <= M; ++i) {
		scanf("%d%d", &u, &v);
		addedge(v, NMAX + u, 1);
		addedge(NMAX + u, v, 0);
	}
	for (i = 1; i <= N1; ++i) {
		addedge(NMAX + i, NMAX * 2 + i, 1);
		addedge(NMAX * 2 + i, NMAX + i, 0);
	}
	scanf("%d", &M);
	for (i = 1; i <= M; ++i) {
		scanf("%d%d", &u, &v);
		addedge(NMAX * 2 + u, NMAX * 3 + v, 1);
		addedge(NMAX * 3 + v, NMAX * 2 + u, 0);
	}
	for (i = 1; i <= N3; ++i) {
		addedge(NMAX * 3 + i, ST, 1);
		addedge(ST, NMAX * 3 + i, 0);
	}

	while (bfs())
		a += dfs(SS, INF);

	printf("%d\n", a);
	return 0;
}

int Q[PMAX], Qtop, Qbot;
void push(int x)
{
	Q[Qtop++] = x;
	if (Qtop == PMAX)
		Qtop = 0;
}
int pop(void)
{
	int r = Q[Qbot++];
	if (Qbot == PMAX)
		Qbot = 0;
	return r;
}

int bfs(void)
{
	int i, c;
	Qtop = 0, Qbot = 0;
	memset(D, 0x7f, sizeof(D));
	D[SS] = 0;
	push(SS);
	while (Qtop != Qbot) {
		c = pop();
		for (i = E[c].n; i; i = E[i].n)
			if (E[i].c && D[E[i].t] > D[c] + 1) {
				D[E[i].t] = D[c] + 1;
				push(E[i].t);
			}
	}
	return D[ST] != 0x7f7f7f7f;
}

int dfs(int s, int l)
{
	int i, f = 0, tf;
	if (l == 0 || s == ST)
		return l;

	for (i = E[s].n; i; i = E[i].n)
		if (D[E[i].t] == D[s] + 1 && E[i].c) {
			tf = dfs(E[i].t, min(E[i].c, l));
			f += tf;
			l -= tf;
			E[i].c -= tf;
			E[i ^ 1].c += tf;
			if (!l)
				break;
		}
	return f;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

void addedge(int f, int t, int c)
{
	E[Etop].t = t;
	E[Etop].c = c;
	E[Etop].n = E[f].n;
	E[f].n = Etop++;
}
