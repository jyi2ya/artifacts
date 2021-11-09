#include <stdio.h>
#include <stdlib.h>

struct Q {
	int l, r, id;
} Q[1000009];

int cnt[1000009];
int val[1000009];
long long ans[1000009];
int bel[1000009];

int cmp(const void *a, const void *b)
{
	struct Q *p = (struct Q *)a;
	struct Q *q = (struct Q *)b;
	return bel[p->r] == bel[q->r] ? 
		((bel[p->r] & 1) ? p->l - q->l : q->l - p->l) :
		p->r - q->r;
}

int main(void)
{
	int n, m, k;
	int i;
	int l = 0, r = 0;
	long long sum;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d%d", &n, &m, &k);
	for (i = 1; i <= n; ++i)
		scanf("%d", &val[i]);

	++cnt[val[l]];
	sum = 1;
	for (i = 0; i < m; ++i) {
		Q[i].id = i;
		scanf("%d%d", &Q[i].l, &Q[i].r);
	}
	for (i = 0; i < m; ++i)
		bel[i] = i / 233;
	qsort(Q, m, sizeof(*Q), cmp);

	for (i = 0; i < m; ++i) {
		while (l < Q[i].l) {
			sum -= cnt[val[l]] * cnt[val[l]];
			--cnt[val[l]];
			sum += cnt[val[l]] * cnt[val[l]];
			++l;
		}
		while (l > Q[i].l) {
			--l;
			sum -= cnt[val[l]] * cnt[val[l]];
			++cnt[val[l]];
			sum += cnt[val[l]] * cnt[val[l]];
		}
		while (r < Q[i].r) {
			++r;
			sum -= cnt[val[r]] * cnt[val[r]];
			++cnt[val[r]];
			sum += cnt[val[r]] * cnt[val[r]];
		}
		while (r > Q[i].r) {
			sum -= cnt[val[r]] * cnt[val[r]];
			--cnt[val[r]];
			sum += cnt[val[r]] * cnt[val[r]];
			--r;
		}
		ans[Q[i].id] = sum;
	}

	for (i = 0; i < m; ++i)
		printf("%lld\n", ans[i]);

	return 0;
}
