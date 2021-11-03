#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NODE 100009
#define MAX_EDGE 1000009

typedef struct edge {
	int to;
	struct edge *next;
} edge;
edge *graph[MAX_NODE];
void addedge(int from, int to);
void prtgrp(void);

#define MAX_QUERY 200009
typedef struct query {
	int a, b, id;
} query;
void prtqry(void);
int qrycmp(const void *a, const void *b);
query qry[MAX_QUERY];

typedef struct quenode {
	int pos, step;
} quenode;
void init(void);
quenode* top(void);
void del(void);
void ins(int pos, int step);
int isempty(void);

void read(void);
void bfs(int start);

int N, M, Q, ans[MAX_QUERY], stspath[MAX_NODE];

int main(void)
{
	int i, j;
	read();
	for (i = 0; i < Q;) {
		for (j = i; qry[j].a == qry[i].a && j < Q; ++j);
		bfs(qry[i].a);
		for (; i < j; ++i) ans[qry[i].id] = stspath[qry[i].b];
	}
	for (i = 0; i < Q; ++i) printf("%d\n", ans[i]);
	return 0;
}

int vis[MAX_NODE];

void bfs(int start)
{
	memset(vis, 0, sizeof(vis));
	init();
	ins(start, 0);
	while (!isempty()) {
		edge *i;
		quenode *n = top(); del();
		if (vis[n -> pos]) continue;
		vis[n -> pos] = 1;
		stspath[n -> pos] = n -> step;
		for (i = graph[n -> pos]; i != NULL; i = i -> next)
			if (!vis[i -> to])
				ins(i -> to, n -> step + 1);
	}
}

void read(void)
{
	int i;
	scanf("%d%d%d", &N, &M, &Q);
	for (i = 0; i < M; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	for (i = 0; i < Q; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a > b) { int t = a; a = b; b = t; }
		qry[i].a = a; qry[i].b = b;
		qry[i].id = i;
	}
	qsort(qry, Q, sizeof(query), qrycmp);
}

quenode que[MAX_NODE * 10], *quetop, *quebot;
void init(void)
{
	quetop = que;
	quebot = que;
}
void ins(int pos, int step)
{
	quetop -> pos = pos;
	quetop -> step = step;
	++quetop;
}
void del(void)
{
	++quebot;
}
quenode* top(void)
{
	return quebot;
}
int isempty(void)
{
	return quetop == quebot;
}

void prtqry(void)
{
	int i;
	printf("%4s %4s\n", "from", "to");
	for (i = 0; i < Q; ++i) printf("%4d %4d\n", qry[i].a, qry[i].b);
}
int qrycmp(const void *a, const void *b)
{
	return (((query*)a) -> a) - (((query*)b) -> a);
}

edge* newedge(int to);
void addedge(int from, int to)
{
	edge *n = newedge(to);
	if (graph[from] == NULL) {
		graph[from] = n;
	} else {
		n -> next = graph[from] -> next;
		graph[from] -> next = n;
	}
}
void prtgrp(void)
{
	int i;
	for (i = 1; i <= N; ++i)
		if (graph[i] != NULL) {
			edge *j;
			printf("%d :", i);
			for (j = graph[i]; j != NULL; j = j -> next)
				printf("%d ", j -> to);
			putchar('\n');
		}
}
edge edge_memory_pool[MAX_EDGE], *edge_memory_top = edge_memory_pool;
edge* newedge(int to)
{
	edge *r = edge_memory_top++;
	r -> to = to;
	r -> next = NULL;
	return r;
}
