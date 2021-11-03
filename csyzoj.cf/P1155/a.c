#include <stdio.h>
#ifndef DEBUG
#define NDEBUG
#endif
#include <assert.h>

int lson[1000009], rson[1000009];

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

int q_empty(struct queue *self)
{
	return self->top == self->bot;
}

void q_print(struct queue *self, char *prompt)
{
	int i;
	if (prompt)
		printf("%s ", prompt);
	for (i = self->bot; i != self->top; ++i) {
		printf("%d ", self->v[i]);
		if (i == Q_MAX)
			i = 0;
	}
	putchar('\n');
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
	static struct queue last[1];
	static struct queue cur[1];
	static struct {
		int min, max;
	} accept[300009];

#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
#ifndef DEBUG
	freopen("A.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &val[i]);
	for (i = 1; i <= n; ++i) {
		accept[i].min = 1;
		accept[i].max = n;
	}

	q_init(last);
	q_init(cur);
	q_push(last, val[0]);
	for (i = 1; i < n; ++i) {
		int rt = 0;

		/*
		printf("i = %d\n", i);
		q_print(last, "last:");
		q_print(cur, "cur :");
		*/
AGAIN:
		while (!q_empty(last)) {
			rt = q_top(last);
			if (accept[rt].min <= val[i]
					&& val[i] <= accept[rt].max)
				break;
			q_pop(last);
		}
		if (q_empty(last)) {
			while (!q_empty(cur)) {
				q_push(last, q_top(cur));
				q_pop(cur);
			}
			goto AGAIN;
		} else {
			if (val[i] < rt) {
				if (lson[rt]) {
					q_pop(last);
					goto AGAIN;
				}
				lson[rt] = val[i];
				accept[val[i]].max = rt;
				accept[val[i]].min = accept[rt].min;
			} else {
				rson[rt] = val[i];
				q_pop(last);
				accept[val[i]].min = rt;
				accept[val[i]].max = accept[rt].max;
			}
			q_push(cur, val[i]);
		}
	}

	print(val[0]);
	putchar('\n');

	return 0;
}
