#include <stdio.h>
#include <stdlib.h>

struct ele {
	int val, id;
} ele[500009];

int pre[500009][32];
int head[500009];
int top[500009];

int cmp(const void *a, const void *b)
{
	struct ele *p = (struct ele *)a;
	struct ele *q = (struct ele *)b;
	return p->val == q->val ? p->id - q->id : p->val - q->val;
}

int ub(struct ele *s, int n, int x)
{
	int l = 0, r = n, m;
	while (l < r) {
		m = l + (r - l) / 2;
		if (x < s[m].id)
			r = m;
		else
			l = m + 1;
	}
	return l;
}

int lb(struct ele *s, int n, int x)
{
	int l = 0, r = n, m;
	while (l < r) {
		m = l + (r - l) / 2;
		if (s[m].id < x)
			l = m + 1;
		else
			r = m;
	}
	return l;
}

int main(void)
{
	int n, q;
	int i, j;
	scanf("%d%d", &n, &q);
	for (i = 1; i <= n; ++i) {
		scanf("%d", &ele[i].val);
		ele[i].id = i;
	}
	for (i = 1; i <= n; ++i)
		for (j = 0; j < 32; ++j)
			pre[i][j] = pre[i - 1][j] + (ele[i].val >> j & 1);
	qsort(ele + 1, n, sizeof(ele[0]), cmp);
	for (i = 1; i <= n; ++i) {
		if (head[ele[i].val] == 0)
			head[ele[i].val] = i;
		++top[ele[i].val];
	}
	while (q--) {
		int l, r;
		int ans = 0;
		scanf("%d%d", &l, &r);
		for (i = 0; i < 32; ++i) {
			if ((pre[r][i] - pre[l - 1][i]) * 2 > (r - l + 1))
				ans |= (1 << i);
			if ((pre[r][i] - pre[l - 1][i]) * 2 == (r - l + 1))
				ans = 0;
		}
		if (ans < 0 || ans > n) {
			ans = 0;
		} else {
			int ll = lb(ele + head[ans], top[ans], l);
			int rr = ub(ele + head[ans], top[ans], r);
			if ((rr - ll) * 2 <= (r - l + 1))
				ans = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}
