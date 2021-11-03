#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int val[300006];
int sz = 0;
int sorted = 0;

int lb(int x)
{
	register int l = 0, r = sz, m;
	while (l < r) {
		m = l + (r - l) / 2;
		if (val[m] < x)
			l = m + 1;
		else
			r = m;
	}
	return l;
}

int ub(int x)
{
	register int l = 0, r = sz, m;
	while (l < r) {
		m = l + (r - l) / 2;
		if (val[m] <= x)
			l = m + 1;
		else
			r = m;
	}
	return l;
}

int cmp(const void *a, const void *b)
{
	return *(int *)a < *(int *)b ? -1 : 1;
}

#define do_sort() if (!sorted) { qsort(val, sz, sizeof(int), cmp); sorted = 1; }
#define ri(x) { \
	register int ch_, lt_ = 0; \
	x = 0; \
	while (!isdigit(ch_ = getchar()) && ch_ != '-'); \
	if (ch_ == '-') \
		lt_ = 1; \
	else \
		x = ch_ - '0'; \
	while (isdigit(ch_ = getchar())) \
		x = x * 10 + ch_ - '0'; \
	if (lt_) \
		x = -x; \
}

#define pi(x) { \
	register int x_ = x, lt_ = 0; \
	char buf[23], *t = buf; \
	if (!x_) \
		*t++ = '0'; \
	if (x_ < 0) { \
		lt_ = 1; \
		x_ = -x_; \
	} \
	while (x_) { \
		div_t d = div(x_, 10); \
		*t++ = d.rem + '0'; \
		x_ = d.quot; \
	} \
	if (lt_) \
		putchar('-'); \
	while (t != buf) \
		putchar(*--t); \
	putchar('\n'); \
}

int main(void)
{
	register int n;
	ri(n);
	while (n--) {
		register int op, x;
		register int i;
		ri(op);
		ri(x);
		switch (op) {
			case 1: val[sz++] = x;
				if (sz >= 2 && val[sz - 1] < val[sz - 2])
					sorted = 0;
				break;
			case 2: do_sort();
				i = lb(x);
				if (val[i] == x) {
					memmove(val + i, val + i + 1, sizeof(int) * (sz - i));
					--sz;
				}
				break;
			case 3: do_sort();
				pi(lb(x) + 1);
				break;
			case 4: do_sort();
				pi(val[x - 1]);
				break;
			case 5: do_sort();
				pi(val[lb(x) - 1]);
				break;
			case 6: do_sort();
				pi(val[ub(x)]);
				break;
		}
	}
	return 0;
}
