#include <stdio.h>
#ifndef DEBUG
#define NDEBUG
#endif
#include <assert.h>

int lson[300009], rson[300009];

#define Q_MAX 1000009

struct queue {
	int v[Q_MAX];
	int top, bot;
};

void q_init(struct queue *self)
{
	self->top = self->bot = 0;
}

void q_push(struct queue *self, int x)
{
	self->v[self->top++] = x;
	if (self->top == Q_MAX)
		self->top = 0;
}

void q_pop(struct queue *self)
{
	assert(self->top != self->bot);
	++self->bot;
	if (self->bot == Q_MAX)
		self->bot = 0;
}

int q_top(struct queue *self)
{
	return self->v[self->bot];
}

void print(int rt)
{
	if (!rt)
		return ;
	printf("%d ", rt);
	print(lson[rt]);
	print(rson[rt]);
}

int main(void)
{
	int n;
	int i;
	static int val[300009];
	static struct queue root[1];
	static struct {
		int min, max;
	} accept[300009];

#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
#ifndef DEBUG
	freopen("a.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	scanf("%d", &n);
	q_init(root);
	for (i = 0; i < n; ++i)
		scanf("%d", &val[i]);
	for (i = 1; i <= n; ++i) {
		accept[i].min = 1;
		accept[i].max = n;
	}

	q_push(root, val[0]);
	for (i = 1; i < n; ++i) {
		int rt = 0;
AGAIN:
		do {
			if (rt)
				q_push(root, rt);
			rt = q_top(root);
			q_pop(root);
		} while (accept[rt].min > val[i] || accept[rt].max < val[i]);

		if (rt > val[i]) {
			if (lson[rt])
				goto AGAIN;
			accept[val[i]].max = rt;
			lson[rt] = val[i];
			q_push(root, val[i]);
			if (!rson[rt])
				q_push(root, rt);
		} else {
			if (rson[rt])
				goto AGAIN;
			accept[val[i]].min = rt;
			rson[rt] = val[i];
			if (!lson[rt])
				q_push(root, rt);
			q_push(root, val[i]);
		}
	}

	print(val[0]);
	putchar('\n');

	return 0;
}
