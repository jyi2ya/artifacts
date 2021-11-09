#include <stdio.h>
#ifndef DEBUG
#define NDEBUG
#endif
#include <assert.h>

struct sp_node {
	int v;
	int s;
	int c;
	struct sp_node *ch[2];

	int addv;
};

struct sp_node* sp_new(int v)
{
	static struct sp_node pool[300009], *top = pool;
	assert(top != pool + 300009);
	top->v = v;
	top->s = 1;
	top->c = 1;
	top->ch[0] = NULL;
	top->ch[1] = NULL;
	top->addv = 0;
	return top++;
}

void sp_pushdown(struct sp_node *c)
{
	assert(c);
	if (c->ch[0])
		c->ch[0]->addv += c->addv;
	if (c->ch[1])
		c->ch[1]->addv += c->addv;
	c->v += c->addv;
	c->addv = 0;
}

void sp_maintain(struct sp_node *c)
{
	assert(c);
	c->s = c->c;
	if (c->ch[0])
		c->s += c->ch[0]->s;
	if (c->ch[1])
		c->s += c->ch[1]->s;
}

void sp_rotate(struct sp_node **c, int d)
{
	struct sp_node *t;

	assert(c);

	sp_pushdown(*c);
	sp_pushdown((*c)->ch[d]);

	t = (*c)->ch[d];
	(*c)->ch[d] = t->ch[d ^ 1];
	t->ch[d ^ 1] = (*c);
	(*c) = t;

	sp_maintain((*c)->ch[d ^ 1]);
	sp_maintain(*c);
}

void sp_splay(struct sp_node **c, int k)
{
	int d1, d2;
	int t;

	assert(c);

	sp_pushdown(*c);
	t = (*c)->ch[0] ? (*c)->ch[0]->s : 0;
	if (k <= t) {
		d1 = 0;
	} else if (k <= t + (*c)->c) {
		return;
	} else {
		d1 = 1;
		k -= t + (*c)->c;
	}

	sp_pushdown((*c)->ch[d1]);
	t = (*c)->ch[d1]->ch[0] ? (*c)->ch[d1]->ch[0]->s : 0;
	if (k <= t) {
		d2 = 0;
	} else if (k <= t + (*c)->ch[d1]->c) {
		sp_rotate(c, d1);
		return;
	} else {
		d2 = 1;
		k -= t + (*c)->ch[d1]->c;
	}

	sp_splay(&(*c)->ch[d1]->ch[d2], k);

	if (d1 == d2) /* zig-zag */
		sp_rotate(c, d1);
	else /* zig-zig */
		sp_rotate(&(*c)->ch[d1], d2);

	sp_rotate(c, d1);
}

int sp_insert(struct sp_node **c, int x)
{
	int id;

	assert(c);

	if (! *c) {
		*c = sp_new(x);
		id = 1;
	} else {
		int l = (*c)->ch[0] ? (*c)->ch[0]->s : 0;

		sp_pushdown(*c);

		if (x < (*c)->v) {
			id = sp_insert(&(*c)->ch[0], x);
		} else if ((*c)->v == x) {
			++(*c)->c;
			++(*c)->s;
			id = l + 1;
		} else {
			id = l + (*c)->c + sp_insert(&(*c)->ch[1], x);
		}

		sp_maintain(*c);
	}

	return id;
}

void prttree(struct sp_node *c)
{
	if (!c)
		return;
	sp_pushdown(c);
	prttree(c->ch[0]);
	printf("%d\n", c->v);
	fflush(stdout);
	prttree(c->ch[1]);
	fflush(stdout);
}

int main(void)
{
	char buf[3];
	int n;
	int min;
	int cnt = 0;
	int tot = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d", &n, &min);

	struct sp_node *root = NULL;

	while (n--) {
		int k;
		scanf("%s%d", buf, &k);
		switch (buf[0]) {
			case 'I' : {
					   if (k >= min) {
						   ++tot;
						   sp_splay(&root, sp_insert(&root, k));
					   }
					   break;
				   }
			case 'A' : {
					   if (root)
						   root->addv += k;
					   break;
				   }
			case 'S' : {
					   if (root)
						   root->addv -= k;
					   break;
				   }
			case 'F' : {
					   k = tot - cnt - k + 1;
					   if (root && k >= 1 && k <= tot - cnt) {
						   sp_splay(&root, k);
						   printf("%d\n", root->v);
					   } else {
						   puts("-1");
					   }
				   }
			default: break;
		}

		while (root) {
			sp_splay(&root, 1);
			if (root->v < min) {
				cnt += root->c;
				root = root->ch[1];
			} else {
				break;
			}
		}

		/*
		   printf("%s %d\n", buf, k); fflush(stdout);
		   puts("pod === ");
		   prttree(root);
		   puts(">>> cut");
		   fflush(stdout);
		   */
	}

	printf("%d\n", cnt);
	return 0;
}
