#include <stdio.h>
#include <string.h>

#define NMAX (5009)
#define MMAX (50009)
#define QMAX (50009)

int min(int a, int b)
{
	return a < b ? a : b;
}

struct queue {
	int que[QMAX];
	int in_que[NMAX];

	int que_top;
	int que_bot;

	void (*push)(struct queue *self, int x);
	int (*pop)(struct queue *self);
	int (*empty)(struct queue *self);
	void (*clear)(struct queue *self);
};

void queue_push(struct queue *self, int x)
{
	if (!self->in_que[x]) {
		self->que[self->que_top++] = x;
		if (self->que_top == QMAX)
			self->que_top = 0;
		self->in_que[x] = 1;
	}
}

int queue_pop(struct queue *self)
{
	int ret = self->que[self->que_bot++];
	if (self->que_bot == QMAX)
		self->que_bot = 0;
	self->in_que[ret] = 0;
	return ret;
}

int queue_empty(struct queue *self)
{
	return self->que_top == self->que_bot;
}

void queue_clear(struct queue *self)
{
	self->que_top = 0;
	self->que_bot = 0;
}

struct queue queue = {
	{ },
	{ },
	0,
	0,
	queue_push,
	queue_pop,
	queue_empty,
	queue_clear
};

struct edge {
	int dest;
	int cap, cost;
	struct edge *next, *rev;
};

struct graph {
	struct edge pool[MMAX * 2];
	struct edge *pool_top;
	struct edge *graph[NMAX];

	struct edge* (*get)(struct graph *self, int dest, int cap, int cost);
	void (*add)(struct graph *self, int u, int v, int cap, int cost);
	void (*print)(struct graph *self);
};

struct edge* graph_get(struct graph *self, int dest, int cap, int cost)
{
	self->pool_top->dest = dest;
	self->pool_top->cap = cap;
	self->pool_top->cost = cost;
	return self->pool_top++;
}

void graph_add(struct graph *self, int u, int v, int cap, int cost)
{
	struct edge *n = self->get(self, v, cap, cost);
	struct edge *r = self->get(self, u, 0, -cost);
	n->rev = r;
	n->next = self->graph[u];
	self->graph[u] = n;

	r->rev = n;
	r->next = self->graph[v];
	self->graph[v] = r;
}

void graph_print(struct graph *self)
{
	int i;
	struct edge *j;
	for (i = 0; i < NMAX; ++i)
		if (self->graph[i]) {
			printf("%d: ", i);
			for (j = self->graph[i]; j; j = j->next)
				printf("%d ", j->dest);
			putchar('\n');
		}
}

struct graph graph = {
	{ },
	graph.pool,
	{ },
	graph_get,
	graph_add,
	graph_print
};

struct flow {
	int dist[NMAX];
	int fa_node[NMAX];
	struct edge *fa_edge[NMAX];
	struct graph *graph;

	int (*dfs)(struct flow *self, int s, int t, int lmt);
	int (*spfa)(struct flow *self, int s, int t);
	int (*flow)(struct flow *self, int s, int t);

	int min_cost;
	int max_flow;
};

int flow_dfs(struct flow *self, int s, int t, int lmt)
{
	struct edge *i;
	int f, cf = 0;

	if (s == t || lmt == 0)
		return lmt;

	for (i = self->graph->graph[s]; i; i = i->next)
		if (self->dist[i->dest] > self->dist[s]) {
			f = self->dfs(self, i->dest, t, min(lmt, i->cap));

			self->min_cost += f * i->cost;

			cf += f;
			lmt -= f;
			i->cap -= f;
			i->rev->cap += f;

			if (!lmt)
				break;
		}

	return cf;
}

int flow_spfa(struct flow *self, int s, int t)
{
	queue.clear(&queue);
	memset(self->dist, 0x3f, sizeof(int) * NMAX);

	self->dist[s] = 0;
	queue.push(&queue, s);
	self->fa_node[s] = 0;
	self->fa_edge[s] = NULL;
	while (!queue.empty(&queue)) {
		int cur = queue.pop(&queue);
		struct edge *i;
		for (i = self->graph->graph[cur]; i; i = i->next)
			if (i->cap > 0 && self->dist[i->dest] >
					self->dist[cur] + i->cost) {
				self->dist[i->dest] = self->dist[cur] + i->cost;
				self->fa_node[i->dest] = cur;
				self->fa_edge[i->dest] = i;
				queue.push(&queue, i->dest);
			}
	}

	return (self->dist[t] == 0x3f3f3f3f) ? (0) : (1);
}

int flow_flow(struct flow *self, int s, int t)
{
	while (self->spfa(self, s, t)) {
		int i, tf = 0x3f3f3f3f;
		for (i = t; self->fa_edge[i]; i = self->fa_node[i])
			tf = min(tf, self->fa_edge[i]->cap);
		self->max_flow += tf;

		for (i = t; self->fa_edge[i]; i = self->fa_node[i]) {
			self->fa_edge[i]->cap -= tf;
			self->fa_edge[i]->rev->cap += tf;
			self->min_cost += tf * self->fa_edge[i]->cost;
		}
	}
	return self->max_flow;
}

struct flow flow = {
	{ },
	{ },
	{ },
	&graph,
	flow_dfs,
	flow_spfa,
	flow_flow
};

int main(void)
{
	int n, m, s, t;
	int i;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (i = 0; i < m; ++i) {
		int u, v, w, f;
		scanf("%d%d%d%d", &u, &v, &w, &f);
		flow.graph->add(flow.graph, u, v, w, f);
	}

	flow.flow(&flow, s, t);
	printf("%d %d\n", flow.max_flow, flow.min_cost);
	return 0;
}
