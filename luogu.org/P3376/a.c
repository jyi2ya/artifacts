#include <stdio.h>
#include <string.h>

typedef struct edge {
	int c, t, n;
} edge;

int D[10009], V[10009];

edge E[300009];
int Etop = 10003;

int bfs_order(int s, int t);
int dfs_flow(int s, int t, int lmt);
void addedge(int u, int v, int w);
void prtgrp(void);
int min(int a, int b);

int main(void)
{
	int n, m, s, t, u, v, w, ans = 0;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d%d%d", &n, &m, &s, &t);
	while (m--) {
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
	}

	while (bfs_order(s, t) == 0) {
		int flow;
		do {
			memset(V, 0, sizeof(V));
			flow = dfs_flow(s, t, 0x7f7f7f7f);
			ans += flow;
		} while (flow);
	}

	printf("%d\n", ans);
	return 0;
}

int dfs_flow(int s, int t, int lmt)
{
	int i, flow = 0, tf;

	if (lmt == 0)
		return 0;

	V[s] = 1;
	for (i = E[s].n; i; i = E[i].n)
		if (!V[E[i].t] && D[E[i].t] > D[s]) {
			if (E[i].t == t)
				tf = min(lmt, E[i].c);
			else
				tf = dfs_flow(E[i].t, t, min(lmt, E[i].c));

			E[i].c -= tf;
			E[i ^ 1].c += tf;

			lmt -= tf;
			flow += tf;
		}
	V[s] = 0;

	return flow;
}

typedef struct queue {
	int p, d;
} queue;
queue S[1000009];
int Stop, Sbot;
int bfs_order(int s, int t)
{
	int fail = 1;
	Stop = 0;
	Sbot = 0;
	memset(V, 0, sizeof(V));
	S[Stop].p = s;
	S[Stop++].d = 0;
	while (Stop != Sbot) {
		int p = S[Sbot].p, d = S[Sbot++].d, i;
		if (p == t)
			fail = 0;
		D[p] = d;
		V[p] = 1;
		for (i = E[p].n; i; i = E[i].n)
			if (!V[E[i].t] && (i & 1) && E[i].c) {
				S[Stop].p = E[i].t;
				S[Stop++].d = d + 1;
			}
	}
	return fail;
}

void addedge(int u, int v, int c)
{
	E[Etop].t = v;
	E[Etop].c = c;
	E[Etop].n = E[u].n;
	E[u].n = Etop;

	Etop ^= 1;

	E[Etop].t = u;
	E[Etop].c = 0;
	E[Etop].n = E[v].n;
	E[v].n = Etop;

	Etop ^= 1;
	Etop += 2;
}

void prtgrp(void)
{
	int i, j;
	for (i = 1; i < 20; ++i) {
		printf("%d :", i);
		for (j = E[i].n; j; j = E[j].n)
			printf("%d(%d) ", E[j].t, E[j].c);
		putchar('\n');
	}
}

int min(int a, int b)
{
	return a < b ? a : b;
}
