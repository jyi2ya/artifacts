#include <stdio.h>

#define H_MAX (200009)
struct heap {
	int buf[200009];
	int top;
	int size;
	int FILL;

	int (*cmp)(int a, int b);
} heap;

void h_swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void h_init(struct heap *c, int FILL, int (*cmp)(int a, int b))
{
	int i;

	c->top = 1;
	c->size = 0;
	c->cmp = cmp;
	c->FILL = FILL;
	for (i = 0; i < H_MAX; ++i)
		c->buf[i] = c->FILL;
}

void h_push(struct heap *c, int x)
{
	int p = c->top;
	c->buf[c->top++] = x;
	while (p > 1) {
		int n = p / 2;
		if (c->cmp(c->buf[p], c->buf[n])) {
			h_swap(&c->buf[p], &c->buf[n]);
			p = n;
		} else {
			break;
		}
	}
	++c->size;
}

void h_pop(struct heap *c)
{
	int p = 1;
	c->buf[p] = c->FILL;
	while (p < c->top) {
		int n = p * 2;
		if (n + 1 < c->top && c->cmp(c->buf[n + 1], c->buf[n]))
			++n;
		c->buf[p] = c->buf[n];
		p = n;
	}
	--c->size;
}

int h_top(struct heap *c)
{
	return c->buf[1];
}

int h_size(struct heap *c)
{
	return c->size;
}

int h_lt(int a, int b)
{
	return a < b;
}

int h_gt(int a, int b)
{
	return a > b;
}

struct heap ht;
#include <string.h>
void h_print(struct heap *c)
{
	memcpy(&ht, c, sizeof(heap));
	while (h_size(&ht)) {
		printf("%d ", h_top(&ht));
		h_pop(&ht);
	}
}

struct heap lt, gt;

int main(void)
{
	int i;
	int n;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	h_init(&lt, 0x7f7f7f7f, h_lt);
	h_init(&gt, -0x7f7f7f7f, h_gt);

	scanf("%d", &n);

	scanf("%d", &i);
	h_push(&gt, i);

	for (i = 0; i < n; i += 2) {
		int x;

		printf("%d\n", h_top(&gt));

		scanf("%d", &x);
		h_push(&gt, x);
		scanf("%d", &x);
		h_push(&gt, x);

		while (h_size(&gt) > h_size(&lt)) {
			h_push(&lt, h_top(&gt));
			h_pop(&gt);
		}

		/*
		h_print(&gt); putchar('|');
		h_print(&lt); putchar('\n');
		*/

		h_push(&gt, h_top(&lt));
		h_pop(&lt);
	}

	return 0;
}
