#include <stdio.h>
#include <assert.h>

struct splay_node {
	int size;
	int value;
	struct splay_node *ch[2];
};

int magic_flag = 0;

void splay_print(struct splay_node *r)
{
	static int depth = 0;

	if (depth == 0)
		puts("== tree ==");

	++depth;
	if (r != NULL) {
		int i;
		splay_print(r->ch[0]);
		for (i = 0; i < depth; ++i)
			putchar('_');
		printf("%d(%d)\n", r->value, r->size);
		splay_print(r->ch[1]);
	}
	--depth;

	if (depth == 0)
		puts("== end ==");
}

void splay_maintain(struct splay_node *r)
{
	if (r != NULL) {
		r->size = 1;
		if (r->ch[0] != NULL)
			r->size += r->ch[0]->size;
		if (r->ch[1] != NULL)
			r->size += r->ch[1]->size;
	}
}

void splay_rotate(struct splay_node **r, int type)
{
	struct splay_node *t;
	assert(r != NULL);
	assert((*r)->ch[type] != NULL);
	t = (*r)->ch[type];
	(*r)->ch[type] = t->ch[type ^ 1];
	t->ch[type ^ 1] = *r;
	*r = t;
	splay_maintain((*r)->ch[type ^ 1]);
	splay_maintain(*r);
}

void splay_splay(struct splay_node **r, int k)
{
	int d1, d2;
	int l;
	struct splay_node *c;

	assert(r != NULL);
	assert(k < (*r)->size);

	c = *r;
	l = c->ch[0] == NULL ? 0 : c->ch[0]->size;
	if (k < l) {
		d1 = 0;
	} else if (k == l) {
		return;
	} else {
		d1 = 1;
		k -= l + 1;
	}

	c = c->ch[d1];
	l = c->ch[0] == NULL ? 0 : c->ch[0]->size;
	if (k < l) {
		d2 = 0;
	} else if (k == l) {
		splay_rotate(r, d1);
		return;
	} else {
		d2 = 1;
		k -= l + 1;
	}
	
	splay_splay(&(*r)->ch[d1]->ch[d2], k);

	if (d1 == d2)
		splay_rotate(r, d1);
	else
		splay_rotate(&(*r)->ch[d1], d2);
	splay_rotate(r, d1);
}

void splay_split(struct splay_node **l, struct splay_node **r,
		struct splay_node **s, int k)
{
	assert(l != NULL);
	assert(r != NULL);
	assert(s != NULL);
	if (*s == NULL) {
		*l = NULL;
		*r = NULL;
	} else if (k == (*s)->size) {
		*l = *s;
		*r = NULL;
	} else {
		splay_splay(s, k);
		*l = (*s)->ch[0];
		(*s)->ch[0] = NULL;
		splay_maintain(*s);
		*r = *s;
	}
}

void splay_merge(struct splay_node **d, struct splay_node **l, 
		struct splay_node **r)
{
	assert(d != NULL);
	assert(l != NULL);
	assert(r != NULL);
	if (*r == NULL) {
		*d = *l;
	} else {
		splay_splay(r, 0);
		(*r)->ch[0] = *l;
		splay_maintain(*r);
		*d = *r;
	}
}

int splay_rank(struct splay_node **r, int x)
{
	struct splay_node *c;
	int rk = 0;
	assert(r != NULL);
	c = *r;

	if (c == NULL)
		return 0;

	while (c != NULL) {
		if (x < c->value) {
			c = c->ch[0];
		} else if (c->value == x) {
			rk += (c->ch[0] == NULL ? 0 : c->ch[0]->size);
			break;
		} else {
			rk += (c->ch[0] == NULL ? 0 : c->ch[0]->size) + 1;
			c = c->ch[1];
		}
	}

	if (rk < (*r)->size)
		splay_splay(r, rk);
	return rk;
}

int splay_kth(struct splay_node **r, int k)
{
	assert(r != NULL);
	assert(*r != NULL);
	assert(k < (*r)->size);
	splay_splay(r, k);
	return (*r)->value;
}

struct splay_node* splay_node_new(int x)
{
	static struct splay_node pool[200009], *top = pool;
	top->value = x;
	top->size = 1;
	top->ch[1] = top->ch[0] = NULL;
	return top++;
}

void splay_insert(struct splay_node **r, int x)
{
	struct splay_node *n, *l, *t, *m;
	int rk;

	assert(r != NULL);

	rk = splay_rank(r, x);
	splay_split(&l, &t, r, rk);
	n = splay_node_new(x);
	splay_merge(&m, &l, &n);
	splay_merge(r, &m, &t);
}

struct splay_node *root = NULL;

void add(int x)
{
	splay_insert(&root, x);
}

int get(void)
{
	static int i = 0;
	int ret = splay_kth(&root, i);
	++i;
	return ret;
}

int main(void)
{
	int m, n;
	int i;
	static int buf[200009];
	static int op[200009];
	int optop = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d", &m, &n);
	for (i = 1; i <= m; ++i)
		scanf("%d", &buf[i]);
	for (i = 0; i < n; ++i)
		scanf("%d", &op[i]);

	for (i = 1; i <= m; ++i) {
		add(buf[i]);
		while (op[optop] == i) {
			printf("%d\n", get());
			++optop;
		}
	}
	return 0;
}
