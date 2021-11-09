#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int V, R, s;
	int f;
	struct node *c[2];
} node;

node* new_node(int V)
{
	node *r = (node*)malloc(sizeof(node));
	r->V = V, r->R = rand(), r->s = 1, r->c[0] = NULL, r->c[1] = NULL;
	r->f = 0;
	return r;
}

void pushdown(node *p)
{
	node *t;
	if (p->f) {
		if (p->c[0])
			p->c[0]->f ^= 1;
		if (p->c[1])
			p->c[1]->f ^= 1;
		t = p->c[0], p->c[0] = p->c[1], p->c[1] = t;
		p->f = 0;
	}
}

void maintain(node *p)
{
	p->s = 1;
	p->s += ((p->c[0]) ? (p->c[0]->s) : (0));
	p->s += ((p->c[1]) ? (p->c[1]->s) : (0));
}

void split(node **l, node **r, node **s, int k)
{
	int ls;
	node *ll, *rr;
	if (!(*s)) {
		ll = NULL, rr = NULL;
	} else {
		pushdown(*s);
		ls = ((*s)->c[0]) ? ((*s)->c[0]->s) : (0);
		if (ls < k) {
			ll = *s;
			split(&(*s)->c[1], &rr, &(*s)->c[1], k - ls - 1);
		} else {
			rr = *s;
			split(&ll, &(*s)->c[0], &(*s)->c[0], k);
		}
		maintain(*s);
	}
	*l = ll, *r = rr;
}

void merge(node **d, node **l, node **r)
{
	node *t;
	if (!(*l) || !(*r)) {
		t = (*r) ? (*r) : (*l);
	} else {
		pushdown(*l);
		pushdown(*r);
		if ((*l)->R < (*r)->R) {
			t = *l;
			merge(&(*l)->c[1], &(*l)->c[1], r);
		} else {
			t = *r;
			merge(&(*r)->c[0], l, &(*r)->c[0]);
		}
		maintain(t);
	}
	*d = t;
}

void append(node **d, int k)
{
	node *n = new_node(k);
	merge(d, d, &n);
}

void flip(int l, int r, node **s)
{
	node *ll, *rr, *m;
	split(&m, &rr, s, r);
	split(&ll, &m, &m, l - 1);
	m->f ^= 1;
	merge(&m, &ll, &m);
	merge(&rr, &m, &rr);
}

void dfs(node *p)
{
	if (p) {
		pushdown(p);
		dfs(p->c[0]);
		printf("%d ", p->V);
		dfs(p->c[1]);
	}
}

int main(void)
{
	node *root = NULL;
	int n, m, i, l, r;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
		append(&root, i);
	while (m--) {
		scanf("%d%d", &l, &r);
		flip(l, r, &root);
	}
	dfs(root);
	putchar('\n');
	return 0;
}
