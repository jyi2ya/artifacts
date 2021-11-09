#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void move(int k);
void insert(int n, char *s);
void reverse(int n);
void delete(int n);
void get(void);
void prev(void);
void next(void);

typedef struct N {
	int v;
	int s;
	int f;
	struct N *c[2];
} N;
void print_tree(N *r);

char buf[21000000];

int cur = 0;
N *root = NULL;

int main(void)
{
	int T, n, i;
	char c[100];

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	setvbuf(stdout, NULL, _IONBF, 0);

	scanf("%d", &T);
	while (T--) {
		scanf("%s", c);
		if (strcmp(c, "Insert") == 0) {
			scanf("%d", &n);
			while (getchar() != '\n');
			for (i = 0; i < n; ++i)
				buf[i] = getchar();
			buf[i] = '\0';
			insert(n, buf);
		} else if (strcmp(c, "Move") == 0) {
			scanf("%d", &n);
			move(n);
		} else if (strcmp(c, "Delete") == 0) {
			scanf("%d", &n);
			delete(n);
		} else if (strcmp(c, "Rotate") == 0) {
			scanf("%d", &n);
			reverse(n);
		} else if (strcmp(c, "Get") == 0) {
			get();
		} else if (strcmp(c, "Prev") == 0) {
			prev();
		} else if (strcmp(c, "Next") == 0) {
			next();
		}
	}
	return 0;
}

void maintain(N *c)
{
	if (!c)
		return;
	c->s = 1;
	if (c->c[0])
		c->s += c->c[0]->s;
	if (c->c[1])
		c->s += c->c[1]->s;
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

N* new_node(int v)
{
	N *r = (N*)malloc(sizeof(N));
	r->v = v;
	r->s = 1;
	r->c[0] = NULL;
	r->c[1] = NULL;
	return r;
}

void splay(N **p, int k)
{
	int l, d, d2;

	if (!cur)
		return;

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

void append(N **p, int v)
{
	if (!cur) {
		cur = new_node(v);
	} else {
		pushdown(cur);
		append(&cur->c[1], v);
		maintain(cur);
	}
}

#undef cur

void print_tree(N *r)
{
	if (!r)
		return;
	static int depth = 0;
	int i;
	pushdown(r);
	++depth;
	print_tree(r->c[0]);
	--depth;
	for (i = 0; i < depth; ++i)
		putchar(' ');
	printf("%c(%d)\n", r->v, r->s);
	++depth;
	print_tree(r->c[1]);
	--depth;
}

void split(N **l, N **r, N **src, int k)
{
	if (!k) {
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
	if (!(*r)) {
		*dest = *l;
		*l = NULL;
	} else {
		splay(r, 1);
		(*r)->c[0] = *l;
		maintain(*r);
		*dest = *r;
	}
}

N* build(char *str)
{
	int i;
	N *rt = NULL;
	for (i = 0; str[i] != '\0'; ++i) {
		append(&rt, str[i]);
		splay(&rt, i + 1);
	}
	return rt;
}

void reverse(int n)
{
	N *l, *r, *m, *t;
	split(&t, &r, &root, cur + n);
	split(&l, &m, &t, cur);
	m->f ^= 1;
	merge(&t, &l, &m);
	merge(&root, &t, &r);
}

void move(int k)
{
	/*
	   printf("Move:%d\n", k);
	 */
	cur = k;
}

void insert(int n, char *s)
{
	/*
	   printf("Insert:%d %s\n", n, s);
	 */
	N *l, *r, *i, *t;
	split(&l, &r, &root, cur);
	i = build(s);
	merge(&t, &l, &i);
	merge(&root, &t, &r);
}

void freemem(N *r)
{
	if (!r)
		return;
	freemem(r->c[0]);
	freemem(r->c[1]);
	free(r);
}

void delete(int n)
{
	/*
	   printf("Delete:%d\n", n);
	 */
	N *l, *r, *m, *t;
	split(&t, &r, &root, cur + n);
	split(&l, &m, &t, cur);
	merge(&root, &l, &r);
	freemem(m);
}

void print(N *r)
{
	if (!r)
		return;
	pushdown(r);
	print(r->c[0]);
	putchar(r->v);
	print(r->c[1]);
}

void get(void)
{
	/*
	   printf("Get:%d\n", n);
	 */
	splay(&root, cur + 1);
	if (root->v == '\n' || root->v == '\r')
		putchar(root->v);
	else
		printf("%c\n", root->v);
}

void prev(void)
{
	/*
	   puts("Prev");
	 */
	--cur;
}

void next(void)
{
	/*
	   puts("Next");
	 */
	++cur;
}
