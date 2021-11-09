#include <stdio.h>
#include <string.h>

#define INF 10000000
#define SS 2003
#define ST 2004
typedef struct edge {
	int t, c, n;
} edge;

int D[3009];
edge E[3000009];
int Etop = 2008;

int min(int a, int b);
void addedge(int f, int t, int c);
void read(void);
int bfs(void);
int dfs(int s, int lmt);

int main(void)
{
	int ans = 0;
	read();
	while (bfs())
		ans += dfs(SS, INF);
	printf("%d\n", ans);
	return 0;
}

#define QMAX 10000000
int Q[QMAX], Qtop, Qbot, V[3009];

void push(int x)
{
	Q[Qtop++] = x;
	if (Qtop == QMAX)
		Qtop = 0;
}

int pop(void)
{
	int r = Q[Qbot++];
	if (Qbot == QMAX)
		Qbot = 0;
	return r;
}

int bfs(void)
{
	int c, i;

	memset(D, 0x7f, sizeof(D));
	memset(V, 0, sizeof(V));
	Qtop = 0, Qbot = 0, D[SS] = 0;
	push(SS);
	while (Qtop != Qbot) {
		c = pop();
		V[c] = 0;
		for (i = E[c].n; i; i = E[i].n)
			if (E[i].c && D[E[i].t] > D[c] + 1 && !V[E[i].t]) {
				D[E[i].t] = D[c] + 1;
				V[E[i].t] = 1;
				push(E[i].t);
			}
	}
	return D[ST] != 0x7f7f7f7f;
}

int dfs(int s, int lmt)
{
	int tf, f = 0, i;

	if (lmt == 0 || s == ST)
		return lmt;

	for (i = E[s].n; i && lmt; i = E[i].n)
		if (E[i].c && D[E[i].t] == D[s] + 1) {
			tf = dfs(E[i].t, min(lmt, E[i].c));

			f += tf;
			lmt -= tf;
			E[i].c -= tf;
			E[i ^ 1].c += tf;
		}

	return f;
}


void read(void)
{
	int n, m, e, i, u, v;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d%d", &n, &m, &e);
	for (i = 1; i <= n; ++i) {
		addedge(SS, i, 1);
		addedge(i, SS, 0);
	}
	for (i = 1; i <= m; ++i) {
		addedge(i + n, ST, 1);
		addedge(ST, i + n, 0);
	}
	for (i = 1; i <= e; ++i) {
		scanf("%d%d", &u, &v);
		addedge(u, v + n, 1);
		addedge(v + n, u, 0);
	}
}

void addedge(int f, int t, int c)
{
	E[Etop].t = t;
	E[Etop].c = c;
	E[Etop].n = E[f].n;
	E[f].n = Etop++;
}

int min(int a, int b)
{
	return a < b ? a : b;
}
