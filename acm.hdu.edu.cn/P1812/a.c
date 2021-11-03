/*
 * 这个题可以用 Polya 计数来做。
 * 用棋盘的坐标来表示棋盘上的点，就可以算出循环节了。
 * 接着套用 Polya 计数的公式来做。
 * 要写高精，然后我就写了。
 */

#ifndef DEBUG
#define NDEBUG
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>

#define BGI_BASE (10000)
#define BGI_WIDTH (4)
#define BGI_SIZE (1000)

struct bgi {
	long long b[BGI_SIZE];
	int top;
};

void bgi_printf(const char *str, ...)
{
	va_list l;
	va_start(l, str);

	while (*str) {
		if (*str == '%' && str[1] == 'd') {
			struct bgi *x = va_arg(l, struct bgi *);
			if (x) {
				int i;
				printf("%lld", x->b[x->top - 1]);
				for (i = x->top - 2; i >= 0; --i)
					printf("%0*lld", BGI_WIDTH, x->b[i]);
			} else {
				printf("(nil)");
			}
			++str;
		} else {
			putchar(*str);
		}
		++str;
	}

	va_end(l);
}

struct bgi* bgi_cpy(struct bgi *d, struct bgi *s)
{
	memcpy(d, s, sizeof(struct bgi));
	return d;
}

struct bgi* bgi_init_ll(struct bgi *d, long long x)
{
	assert(d);
	memset(d, 0, sizeof(struct bgi));
	while (x) {
		d->b[d->top++] = x % BGI_BASE;
		x /= BGI_BASE;
	}
	return d;
}

struct bgi* bgi_carry(struct bgi *t)
{
	long long res = 0;
	int i;
	for (i = 0; i < t->top; ++i) {
		res += t->b[i];
		t->b[i] = res % BGI_BASE;
		res /= BGI_BASE;
	}

	while (res) {
		t->b[t->top++] = res % BGI_BASE;
		res /= BGI_BASE;
	}

	return t;
}

struct bgi* bgi_add_bgi(struct bgi *d, struct bgi *x1, struct bgi *x2)
{
	struct bgi t_base, *t = &t_base;
	int i;

	assert(d);
	assert(x1);
	assert(x2);

	bgi_init_ll(t, 0);
	t->top = ((x1->top > x2->top) ? (x1->top) : (x2->top));
	for (i = 0; i < t->top; ++i)
		t->b[i] = x1->b[i] + x2->b[i];

	return bgi_cpy(d, bgi_carry(t));
}

struct bgi* bgi_mul_bgi(struct bgi *d, struct bgi *x1, struct bgi *x2)
{
	struct bgi t_base, *t = &t_base;
	int i, j;

	assert(d);
	assert(x1);
	assert(x2);

	bgi_init_ll(t, 0);
	t->top = x1->top + x2->top - 1;
	for (i = 0; i < x1->top; ++i)
		for (j = 0; j < x2->top; ++j)
			t->b[i + j] += x1->b[i] * x2->b[j];
	return bgi_cpy(d, bgi_carry(t));
}

struct bgi* bgi_div_ll(struct bgi *d, struct bgi *x1, long long x2)
{
	struct bgi t_base, *t = &t_base;
	long long res = 0;
	int i;

	assert(d);
	assert(x1);
	assert(x2);

	bgi_cpy(t, x1);
	for (i = t->top - 1; i >= 0; --i) {
		res = res * BGI_BASE + t->b[i];
		t->b[i] = res / x2;
		res %= x2;
	}
	while (t->b[t->top] == 0 && t->top)
		--t->top;
	++t->top;
	return bgi_cpy(d, t);
}

int bgi_eq0(struct bgi *x)
{
	return x->top == 0 || (x->top == 1 && x->b[0] == 0);
}

int bgi_odd(struct bgi *x)
{
	return (x->top != 0) && (x->b[0] & 1);
}

struct bgi* bgi_pow_bgi(struct bgi *d, struct bgi *x1, struct bgi *x2)
{
	bgi_init_ll(d, 1);
	while (!bgi_eq0(x2)) {
		if (bgi_odd(x2))
			bgi_mul_bgi(d, d, x1);
		bgi_mul_bgi(x1, x1, x1);
		bgi_div_ll(x2, x2, 2);
	}
	return d;
}

struct bgi* bgi_pow_ll(struct bgi *d, struct bgi *x1, long long x2)
{
	struct bgi t_base, *t = &t_base;
	struct bgi x1_base, *x = &x1_base;
	bgi_init_ll(t, 1);
	bgi_cpy(x, x1);
	while (x2) {
		if (x2 & 1)
			bgi_mul_bgi(t, t, x);
		bgi_mul_bgi(x, x, x);
		x2 /= 2;
	}
	return bgi_cpy(d, t);
}

void bgi_test(void)
{
	struct bgi x, y;
	struct bgi a;
	bgi_init_ll(&x, 99999);
	bgi_init_ll(&y, 2);
	bgi_div_ll(&a, &x, 2);
	bgi_mul_bgi(&y, &y, &a);
	bgi_printf("x is %d, ans is %d, rev is %d\n", &x, &a, &y);
	exit(0);
}

int main(void)
{
	int n, c;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	while (scanf("%d%d", &n, &c) == 2) {
		struct bgi ans;
		struct bgi cc;
		struct bgi tmp;
		bgi_init_ll(&ans, 0);
		bgi_init_ll(&cc, c);

#define do_with_step(dx, dy) \
		do { \
			int x, y; \
			int i, j; \
			int t = 0; \
			int vis[32][32]; \
			memset(vis, 0, sizeof(vis)); \
			for (i = 0; i < n; ++i) \
			for (j = 0; j < n; ++j) { \
				if (!vis[i][j]) { \
					x = i, y = j; \
					do { \
						int nx, ny; \
						vis[x][y] = 1; \
						nx = dx; \
						ny = dy; \
						x = nx; \
						y = ny; \
					} while (!(x == i && y == j)); \
					++t; \
				} \
			} \
			bgi_add_bgi(&ans, &ans, bgi_pow_ll(&tmp, &cc, t)); \
		} while (0)

		/* 不变 */
		do_with_step(x, y);
		/* 转 pi/2 */
		do_with_step(y, n - x - 1);
		/* 转 pi */
		do_with_step(n - x - 1, n - y - 1);
		/* 转 pi * 3/2 */
		do_with_step(n - y - 1, x);

		/* 左右 */
		do_with_step(x, n - y - 1);
		/* 上下 */
		do_with_step(n - x - 1, y);
		/* 左上-右下 */
		do_with_step(n - y - 1, n - x - 1);
		/* 左下-右上 */
		do_with_step(y, x);
#undef do_with_step

		bgi_div_ll(&ans, &ans, 8);
		bgi_printf("%d\n", &ans);
	}

	return 0;
}
