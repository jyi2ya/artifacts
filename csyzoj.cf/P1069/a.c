/*
 * 设猪 i 在第 j 个点被卖掉。
 * 该猪收益为 w_i p_j - w_i d_j t = w_i(p_j - d_j t) 。
 * 令 q_i = p_j - d_j t 。
 * 题目要求排列 w_i ，使 sum_(i=1)^n (w_i q_i) 最大。
 * 将 w ， q 分别从小到大排序，此时 sum_(i=1)^n (w_i q_i) 最大。
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(long long *)a == *(long long *)b ? 0 :
		*(long long *)a < *(long long *)b ? -1 : 1;
}

int main(void)
{
	int n;
	int i;
	long long t;
	static long long w[100009];
	static long long q[100009];
	static long long d[100009];
	static long long p[100009];
	long long ans = 0;

#ifndef ONLINE_JUDGE
	freopen("pig.in", "r", stdin);
#ifndef DEBUG
	freopen("pig.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	scanf("%d%lld", &n, &t);
	for (i = 1; i <= n; ++i)
		scanf("%lld", &w[i]);
	for (i = 1; i <= n; ++i)
		scanf("%lld", &d[i]);
	for (i = 1; i <= n; ++i)
		scanf("%lld", &p[i]);
	for (i = 1; i <= n; ++i)
		q[i] = p[i] - t * d[i];
	qsort(w + 1, n, sizeof(w[0]), cmp);
	qsort(q + 1, n, sizeof(q[0]), cmp);
	for (i = 1; i <= n; ++i)
		ans += w[i] * q[i];

	printf("%lld\n", ans);
	return 0;
}
