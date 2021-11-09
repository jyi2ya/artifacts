#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void move(int k);
void insert(int n, char *s);
void delete(int n);
void get(int n);
void prev(void);
void next(void);

char buf[21000000];

int main(void)
{
	int T, n, i, ch;
	char c[100];

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &T);
	while (T--) {
		scanf("%s", c);
		if (strcmp(c, "Insert") == 0) {
			scanf("%d", &n);
			for (i = 0; i < n; ++i) {
				while ((ch = getchar()) < 32 || ch > 126);
				buf[i] = ch;
			}
			buf[i] = '\0';
			insert(n, buf);
		} else if (strcmp(c, "Move") == 0) {
			scanf("%d", &n);
			move(n);
		} else if (strcmp(c, "Delete") == 0) {
			scanf("%d", &n);
			delete(n);
		} else if (strcmp(c, "Get") == 0) {
			scanf("%d", &n);
			get(n);
		} else if (strcmp(c, "Prev") == 0) {
			prev();
		} else if (strcmp(c, "Next") == 0) {
			next();
		}
	}
	return 0;
}

typedef struct N {
	int v;
	int s;
	struct N *c[2];
} N;

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

#define cur (*p)
void rotate(N **p, int d)
{
	N *t = cur->c[d];
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

	l = (cur->c[0] ? cur->c[0]->s : 0);
	if (k <= l) {
		d = 0;
	} else if (k == l + 1) {
		return;
	} else {
		d = 1;
		k -= l + 1;
	}

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

int cur = 0;
N *root = NULL;

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

void delete(int n)
{
	/*
	printf("Delete:%d\n", n);
	*/
	N *l, *r, *m, *t;
	split(&t, &r, &root, cur + n);
	split(&l, &m, &t, cur);
	merge(&root, &l, &r);
}

void print(N *r)
{
	if (!r)
		return;
	print(r->c[0]);
	putchar(r->v);
	print(r->c[1]);
}

void get(int n)
{
	/*
	printf("Get:%d\n", n);
	*/
	N *l, *r, *m, *t;
	split(&t, &r, &root, cur + n);
	split(&l, &m, &t, cur);
	print(m);
	putchar('\n');
	merge(&t, &l, &m);
	merge(&root, &t, &r);
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
