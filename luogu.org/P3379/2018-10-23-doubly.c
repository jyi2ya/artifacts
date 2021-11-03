#include <stdio.h>
#include <string.h>

#define MAX 500009

int query_lca(int a, int b);
void init_lca(void);

typedef struct edge {
	int to;
	struct edge *next;
} edge;

edge* tree[MAX];

void read(void);

int n, m, s;

int main(void)
{
	read();
	init_lca();
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", query_lca(a, b));
	}
	return 0;
}

int jmp[32][MAX], depth[MAX], fa[MAX];
void addedge(int from, int to);
void prtgrp(void);

int query_lca(int a, int b)
{
	register int i;
	if (depth[a] < depth[b]) { i = a; a = b; b = i; }
	for (i = 30; i >= 0; --i)
		if (jmp[i][a] && depth[jmp[i][a]] >= depth[b])
			a = jmp[i][a];
	if (a == b) return a;
	for (i = 30; i >= 0; --i)
		if (jmp[i][a] && jmp[i][b] && jmp[i][a] != jmp[i][b]) {
			a = jmp[i][a];
			b = jmp[i][b];
		}
	return fa[a];
}

void dfs_lca(int pos, int dpt);

void init_lca(void)
{
	fa[s] = s;
	dfs_lca(s, 0);
}

void dfs_lca(int pos, int dpt)
{
	register int i;
	register edge *j;
	depth[pos] = dpt;
	jmp[0][pos] = fa[pos];
	for (i = 1; (1 << i) <= dpt; ++i)
		jmp[i][pos] = jmp[i - 1][jmp[i - 1][pos]];
	for (j = tree[pos]; j != NULL; j = j->next)
		if (j->to != fa[pos]) {
			fa[j->to] = pos;
			dfs_lca(j->to, dpt + 1);
		}
}

edge edges[MAX << 1], *pool = edges;
void addedge(int from, int to)
{
	pool->to = to;
	pool->next = tree[from];
	tree[from] = pool++;
}
void prtgrp(void)
{
	register int i;
	register edge *j;
	for (i = 1; i <= n; ++i)
		if (tree[i] != NULL) {
			printf("%d :", i);
			for (j = tree[i]; j != NULL; j = j->next)
				printf("%d ", j->to);
			putchar('\n');
		}
}

void read(void)
{
	register int i;
	scanf("%d%d%d", &n, &m, &s);
	for (i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		addedge(x, y);
		addedge(y, x);
	}
}
