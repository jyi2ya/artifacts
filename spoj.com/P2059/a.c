#include <stdio.h>
#include <stdlib.h>

typedef struct N {
	int v, id;
	int s, m, m_id; /* size, min */
	int f; /* flip */
	struct N *c[2];
} N;

void pushdown(N *c);
void maintain(N *c);
int find_min(N *c);
void append(N **p, int v, int id);
void splay(N **p, int k);
void split(N **l, N **r, N **src, int k);
void flip(N **p, int l, int r);
void merge(N **dest, N **l, N **r);

void print_tree(N *current)
{
	static int depth = 0;
	int i;
	if (!depth)
		puts("============== t r e e =================");

	if (current == NULL)
		return;
	++depth;
	print_tree(current->c[0]);
	--depth;
	putchar('|');
	for (i = 0; i < depth; ++i)
		printf(" |");
	printf("-[1;32m%d(%d,%d,%d,%d)[0m\n", current->v, current->f, current->m, current->m_id, current->id);
	++depth;
	print_tree(current->c[1]);
	--depth;
}

int main(void)
{
	int n;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	while (scanf("%d", &n) == 1 && n) {
		int i, x, p, f = 1;
		N *rt = NULL;
		for (i = 0; i < n; ++i) {
			scanf("%d", &x);
			append(&rt, x, i);
			splay(&rt, i + 1);
		}
		for (i = 0; i < n; ++i) {
			if (f)
				f = 0;
			else
				putchar(' ');

			p = find_min(rt);
			printf("%d", p + i);
			flip(&rt, 1, p);
			splay(&rt, 1);
			rt = rt->c[1];
		}
		putchar('\n');
	}
	return 0;
}

void maintain(N *c)
{
	if (!c)
		return;
	c->s = 1;
	c->m = c->v;
	c->m_id = c->id;
	if (c->c[0]) {
		c->s += c->c[0]->s;
		if (c->m > c->c[0]->m) {
			c->m = c->c[0]->m;
			c->m_id = c->c[0]->m_id;
		}
		if (c->m == c->c[0]->m && c->c[0]->m_id < c->m_id)
			c->m_id = c->c[0]->m_id;
	}
	if (c->c[1]) {
		c->s += c->c[1]->s;
		if (c->m > c->c[1]->m) {
			c->m = c->c[1]->m;
			c->m_id = c->c[1]->m_id;
		}
		if (c->m == c->c[1]->m && c->c[1]->m_id < c->m_id)
			c->m_id = c->c[1]->m_id;
	}
}

void pushdown(N *c)
{
	if (!c)
		return;
	if (c->f) {
		N *t;
		if (c->c[0])
			c->c[0]->f ^= 1;
		if (c->c[1])
			c->c[1]->f ^= 1;
		t = c->c[0];
		c->c[0] = c->c[1];
		c->c[1] = t;
		c->f = 0;

		maintain(c);
	}
}

int find_min(N *c)
{
	int l;
	pushdown(c);
	if (!c)
		return 0;
	l = (c->c[0] ? c->c[0]->s : 0);

	if (c->c[0] && c->m == c->c[0]->m && c->m_id == c->c[0]->m_id)
		return find_min(c->c[0]);
	if (c->m_id == c->id)
		return l + 1;
	return find_min(c->c[1]) + l + 1;
}


N* new_node(int v, int id)
{
	N *r = (N*)malloc(sizeof(N));
	r->v = v;
	r->id = id;
	r->m_id = id;
	r->s = 1;
	r->f = 0;
	r->m = v;
	r->c[0] = NULL;
	r->c[1] = NULL;
	return r;
}

void split(N **l, N **r, N **src, int k)
{
	if (k == 0) {
		*l = NULL;
		*r = *src;
	} else {
		splay(src, k);
		*r = (*src)->c[1];
		(*src)->c[1] = NULL;
		maintain(*src);

		*l = *src;
	}
}

void merge(N **dest, N **l, N **r)
{
	if (*r == NULL) {
		*dest = *l;
	} else {
		splay(r, 1);
		(*r)->c[0] = *l;
		maintain(*r);

		*dest = *r;
	}
}

#define cur (*p)
void rotate(N **p, int d)
{
	N *t;
	pushdown(cur);
	pushdown(cur->c[d]);
	t = cur->c[d];
	cur->c[d] = t->c[d ^ 1];
	t->c[d ^ 1] = cur;
	cur = t;
	maintain(cur->c[d ^ 1]);
	maintain(cur);
}

void splay(N **p, int k)
{
	int d, d2, l;

	pushdown(cur);
	l = (cur->c[0] ? cur->c[0]->s : 0);
	if (k <= l) {
		d = 0;
	} else if (k == l + 1) {
		return;
	} else {
		d = 1;
		k -= l + 1;
	}

	pushdown(cur->c[d]);
	l = (cur->c[d]->c[0] ? cur->c[d]->c[0]->s : 0);
	if (k <= l) {
		d2 = 0;
	} else if (k == l + 1) {
		rotate(&cur, d);
		return;
	} else {
		d2 = 1;
		k -= l + 1;
	}

	splay(&cur->c[d]->c[d2], k);

	if (d == d2)
		rotate(&cur, d);
	else
		rotate(&cur->c[d], d2);

	rotate(&cur, d);
}

void append(N **p, int v, int id)
{
	if (!cur) {
		cur = new_node(v, id);
	} else {
		pushdown(cur);
		append(&cur->c[1], v, id);
		maintain(cur);
	}
}

void flip(N **p, int l, int r)
{
	int i;
	N *ll, *rr, *m, *t;
	if (l == r)
		return;
	if (r < l) {
		i = l;
		l = r;
		r = i;
	}
	split(&t, &rr, p, r);
	split(&ll, &m, &t, l - 1);
	m->f ^= 1;
	merge(&t, &ll, &m);
	merge(p, &t, &rr);
}
#undef cur
