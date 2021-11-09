#include <stdio.h>
#include <stdlib.h>

int cmp_lt(const void *p1, const void *p2)
{
	return *(int*)p1 < *(int*)p2 ? -1 : 1;
}

int t[2009], q[2009];

int main_(void)
{
	int n;
	int i;
	int lt, lq, rt, rq;
	int ans = 0;

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", t + i);
	for (i = 0; i < n; ++i)
		scanf("%d", q + i);

	qsort(t, n, sizeof(t[0]), cmp_lt);
	qsort(q, n, sizeof(q[0]), cmp_lt);

	lt = 0, lq = 0, rt = n - 1, rq = n - 1;

	while (lt <= rt) {
		if (t[rt] > q[rq]) {
			ans += 200;
			--rt, --rq;
		} else if (t[rt] < q[rq]) {
			ans -= 200;
			++lt, --rq;
		} else {
			if (t[lt] > q[lq]) {
				ans += 200;
				++lt, ++lq;
			} else {
				if (t[lt] < q[rq])
					ans -= 200;
				++lt, --rq;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}

int start_(void)
{
	return main_();
}

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	start_();

#ifdef DEBUG
	fclose(stdin);
#endif
	
	return 0;
}
