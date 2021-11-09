#include <stdio.h>
#include <stdlib.h>

long long gcd(long long a, long long b)
{
	while (b) {
		long long t = a % b;
		a = b;
		b = t;
	}
	return a;
}

struct Q {
	int l, r, id;
} Q[1000009];

int cnt[1000009];
int val[1000009];
struct {
	long long a, b;
} ans[1000009];
int n, m;
int blk[1000009];

int cmp(const void *a, const void *b)
{
	struct Q *p = (struct Q *)a;
	struct Q *q = (struct Q *)b;
	return blk[p->r] == blk[q->r] ?
		((blk[p->r] & 1) ? p->l - q->l : q->l - p->l) :
		p->r - q->r;
}

int main(void)
{
	int i;
	int l, r;
	long long sum = 0;
	long long g;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
		scanf("%d", &val[i]);
	for (i = 0; i < m; ++i) {
		scanf("%d%d", &Q[i].l, &Q[i].r);
		Q[i].id = i;
		blk[i] = i / 233;
	}
	qsort(Q, m, sizeof(*Q), cmp);

	l = 1, r = 1;
	cnt[val[1]] = 1;
	sum = 1 * (1 - 1);
	for (i = 0; i < m; ++i) {
		if (Q[i].l == Q[i].r) {
			ans[Q[i].id].a = 0;
			ans[Q[i].id].b = 1;
			continue;
		}
		while (l < Q[i].l) {
			sum -= cnt[val[l]] * (cnt[val[l]] - 1);
			--cnt[val[l]];
			sum += cnt[val[l]] * (cnt[val[l]] - 1);
			++l;
		}
		while (l > Q[i].l) {
			--l;
			sum -= cnt[val[l]] * (cnt[val[l]] - 1);
			++cnt[val[l]];
			sum += cnt[val[l]] * (cnt[val[l]] - 1);
		}
		while (r < Q[i].r) {
			++r;
			sum -= cnt[val[r]] * (cnt[val[r]] - 1);
			++cnt[val[r]];
			sum += cnt[val[r]] * (cnt[val[r]] - 1);
		}
		while (r > Q[i].r) {
			sum -= cnt[val[r]] * (cnt[val[r]] - 1);
			--cnt[val[r]];
			sum += cnt[val[r]] * (cnt[val[r]] - 1);
			--r;
		}
		ans[Q[i].id].a = sum;
		ans[Q[i].id].b = (r - l + 1LL) * (r - l);
		g = gcd(ans[Q[i].id].a, ans[Q[i].id].b);
		ans[Q[i].id].a /= g;
		ans[Q[i].id].b /= g;
	}

	for (i = 0; i < m; ++i)
		printf("%lld/%lld\n", ans[i].a, ans[i].b);

	return 0;
}
