#include <stdio.h>
#include <stdlib.h>
#ifndef DEBUG
#define NDEBUG
#endif
#include <assert.h>

#define INF (0x3f3f3f3f)
#define MOD (1000000)

struct s_node {
	int v;
	int c;
	int s;

	struct s_node *ch[2];
};

struct s_node* s_new(int x)
{
	static struct s_node pool[200009], *top = pool;
	assert(top != pool + 100009);
	top->v = x;
	top->c = 1;
	top->s = 1;
	top->ch[0] = NULL;
	top->ch[1] = NULL;
	return top++;
}

void s_maintain(struct s_node *c)
{
	assert(c);
	c->s = c->c;
	if (c->ch[0])
		c->s += c->ch[0]->s;
	if (c->ch[1])
		c->s += c->ch[1]->s;
}

void s_rotate(struct s_node **c, int d)
{
	struct s_node *t;
	assert(c);

	t = (*c)->ch[d];
	(*c)->ch[d] = t->ch[d ^ 1];
	t->ch[d ^ 1] = (*c);
	(*c) = t;

	s_maintain((*c)->ch[d ^ 1]);
	s_maintain(*c);
}

void s_splay(struct s_node **c, int k)
{
	int d1, d2;
	int l, t;

	assert(c);

	assert(*c);
	l = (*c)->ch[0] ? (*c)->ch[0]->s : 0;
	t = (*c)->c;
	if (k <= l) {
		d1 = 0;
	} else if (k <= l + t) {
		return;
	} else {
		d1 = 1;
		k -= l + t;
	}

	assert((*c)->ch[d1]);
	l = (*c)->ch[d1]->ch[0] ? (*c)->ch[d1]->ch[0]->s : 0;
	t = (*c)->ch[d1]->c;
	if (k <= l) {
		d2 = 0;
	} else if (k <= l + t) {
		s_rotate(c, d1);
		return;
	} else {
		d2 = 1;
		k -= l + t;
	}

	s_splay(&(*c)->ch[d1]->ch[d2], k);

	if (d1 == d2)
		s_rotate(c, d1);
	else
		s_rotate(&(*c)->ch[d1], d2);
	s_rotate(c, d1);
}

int s_rank(struct s_node **pc, int x)
{
	int ans = 1;
	struct s_node *c = *pc;

	if (!c) {
		ans = 0;
	} else {
		while (c) {
			int l = c->ch[0] ? c->ch[0]->s : 0;
			if (x < c->v) {
				c = c->ch[0];
			} else if (x == c->v) {
				ans += l;
				break;
			} else {
				ans += l + c->c;
				c = c->ch[1];
			}
		}
	}

	return ans;
}

void s_insert(struct s_node **c, int x)
{
	assert(c);

	if (*c) {
		if (x < (*c)->v)
			s_insert(&(*c)->ch[0], x);
		else if (x == (*c)->v)
			++(*c)->c;
		else
			s_insert(&(*c)->ch[1], x);
		s_maintain(*c);
	} else {
		*c = s_new(x);
	}
}

void s_delete(struct s_node **c, int x)
{
	assert(c);

	if (*c) {
		if (x < (*c)->v) {
			s_delete(&(*c)->ch[0], x);
		} else if (x == (*c)->v) {
			--(*c)->c;
			if ((*c)->c == 0) {
				if ((*c)->ch[0] == NULL) {
					*c = (*c)->ch[1];
				} else if ((*c)->ch[1] == NULL) {
					*c = (*c)->ch[0];
				} else {
					s_splay(&(*c)->ch[1], 1);
					(*c)->ch[1]->ch[0] = (*c)->ch[0];
					*c = (*c)->ch[1];
				}
			}
		} else {
			s_delete(&(*c)->ch[1], x);
		}

		if (*c)
			s_maintain(*c);
	}
}

int s_exist(struct s_node **c, int x)
{
	int ans;
	assert(c);
	s_insert(c, x);
	s_splay(c, s_rank(c, x));
	ans = ((*c)->c > 1);
	s_delete(c, x);
	return ans;
}

int s_prev(struct s_node **c, int x)
{
	int ans = -INF;
	struct s_node *i;

	assert(c);

	s_insert(c, x);
	s_splay(c, s_rank(c, x));
	for (i = (*c)->ch[0]; i; i = i->ch[1])
		ans = i->v;
	s_delete(c, x);
	return ans;
}

int s_next(struct s_node **c, int x)
{
	int ans = INF;
	struct s_node *i;

	assert(c);

	s_insert(c, x);
	s_splay(c, s_rank(c, x));
	for (i = (*c)->ch[1]; i; i = i->ch[0])
		ans = i->v;
	s_delete(c, x);
	return ans;
}

int main(void)
{
	int n;
	int type = 0;
	struct s_node *root = NULL;
	int ans = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);

	while (n--) {
		int op, x;
		scanf("%d%d", &op, &x);
		if (root) {
			if (type == op) {
				s_insert(&root, x);
				s_splay(&root, s_rank(&root, x));
			} else {
				if (s_exist(&root, x)) {
					s_delete(&root, x);
				} else {
					int prev = s_prev(&root, x);
					int next = s_next(&root, x);
					if (abs(next - x) < abs(prev - x))
						prev = next;
					ans = (ans + abs(prev - x)) % MOD;
					s_delete(&root, prev);
				}
			}
		} else {
			type = op;
			s_insert(&root, x);
			s_splay(&root, s_rank(&root, x));
		}
	}

	printf("%d\n", ans);
	return 0;
}
