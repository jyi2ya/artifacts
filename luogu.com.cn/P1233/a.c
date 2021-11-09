#include <stdio.h>
#include <stdlib.h>

typedef struct stk {
	int l, w;
} stk;
int n, i, j, vis[5009], ans, last;
stk buf[5009];

int cmp(const void *a, const void *b)
{
	stk *p = (stk*)a, *q = (stk*)b;
	if (p->l == q->l)
		return q->w - p->w;
	return q->l - p->l;
}

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d%d", &buf[i].l, &buf[i].w);
	qsort(buf, n, sizeof(stk), cmp);

	for (i = 0; i < n; ++i) {
		if (vis[i])
			continue;
		++ans;
		last = buf[i].w;
		for (j = i; j < n; ++j)
			if (last >= buf[j].w && !vis[j]) {
				last = buf[j].w;
				vis[j] = 1;
			}
	}
	printf("%d\n", ans);
	return 0;
}
