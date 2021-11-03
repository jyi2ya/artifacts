#include <stdio.h>
#include <string.h>

typedef struct bgi {
	int buf[100009];
	int top;
} bgi;

bgi* add(bgi *c, bgi *a, bgi *b);

bgi ans, tmp1, tmp2;

int main(void)
{
	int i, n;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	if (n == 0) {
		puts("0");
	} else if (n == 1) {
		puts("1");
	} else {
		tmp1.buf[0] = 1;
		tmp1.top = 1;
		tmp2.buf[0] = 1;
		tmp1.top = 1;
		for (i = 2; i <= n; ++i) {
			add(&ans, &tmp1, &tmp2);
			memcpy(&tmp2, &tmp1, sizeof(bgi));
			memcpy(&tmp1, &ans, sizeof(bgi));
		}
		for (i = ans.top - 1; i >= 0; --i)
			printf("%d", ans.buf[i]);
		putchar('\n');
	}
	return 0;
}

bgi tmp;
bgi* add(bgi *c, bgi *a, bgi *b)
{
	int i, tp = (a->top > b->top) ? a->top : b->top;
	memset(&tmp, 0, sizeof(tmp));
	for (i = 0; i < tp; ++i)
		tmp.buf[i] = a->buf[i] + b->buf[i];
	for (i = 0; i < tp; ++i)
		if (tmp.buf[i] > 9) {
			tmp.buf[i + 1] += tmp.buf[i] / 10;
			tmp.buf[i] %= 10;
		}
	while (tmp.buf[tp])
		++tp;
	tmp.top = tp;
	memcpy(c, &tmp, sizeof(tmp));
	return c;
}
