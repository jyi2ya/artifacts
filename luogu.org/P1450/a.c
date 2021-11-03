/*
 * 显然，这个规模用多重背包会萎。
 * 因为这是容斥的套题所以考虑到用容斥来解决。
 *
 * 如果是完全背包，没有硬币数量限制，方案数可以做一次完全背包求出来。这一步整个
 * 程序只要做一次。
 *
 * 设 c_i 为硬币 i 的价值。
 * 设 d_i 为硬币 i 的数量限制。
 * 设 f(x) 为不考虑硬币数量限制，用 4 种硬币得到 x 的方案数。
 * 设 总价为 s 。
 *
 * 如果仅硬币 i 数量超过限制，那么产生的不合法的方案数为 f(s - c_i(d_i+1))
 * 然后进行容斥。
 */

#include <stdio.h>
#include <string.h>

#define SMAX 100009
#define CNUM 4

struct {
	int c[CNUM];
	long long f[SMAX];
} E;

int solve_main(void)
{
	int *c = E.c;
	long long *f = E.f;
	int d[4];
	int s;
	long long ans = 0;

	scanf("%d%d%d%d%d", &d[0], &d[1], &d[2], &d[3], &s);

#define magic(expr, sign) if ((expr) >= 0) ans += (sign) * f[expr]
#define ff(expr) c[expr] * (d[expr] + 1)

	magic(s, 1);

	magic(s - ff(0), -1);
	magic(s - ff(1), -1);
	magic(s - ff(2), -1);
	magic(s - ff(3), -1);

	magic(s - ff(0) - ff(1), 1);
	magic(s - ff(0) - ff(2), 1);
	magic(s - ff(0) - ff(3), 1);
	magic(s - ff(1) - ff(2), 1);
	magic(s - ff(1) - ff(3), 1);
	magic(s - ff(2) - ff(3), 1);

	magic(s - ff(3) - ff(2) - ff(1), -1);
	magic(s - ff(3) - ff(2) - ff(0), -1);
	magic(s - ff(3) - ff(0) - ff(1), -1);
	magic(s - ff(0) - ff(2) - ff(1), -1);

	magic(s - ff(0) - ff(1) - ff(2) - ff(3), 1);
#undef ff
#undef magic

	printf("%lld\n", ans);

	return 0;
}

int solve_start(void)
{
	return solve_main();
}

int main(void)
{
	int tot;
	int *c = E.c;
	long long *f = E.f;
	int i, j;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d%d%d%d", &c[0], &c[1], &c[2], &c[3], &tot);

	f[0] = 1;
	for (i = 0; i < 4; ++i)
		for (j = c[i]; j < SMAX; ++j)
			f[j] += f[j - c[i]];

	while (tot--)
		solve_start();

#ifdef DEBUG
	fclose(stdin);
#endif

	return 0;
}
