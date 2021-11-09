/*
 * 如果点 (x, y) 和 (0, 0) 之间存在点 (x_0, y_0) (x_0 < x, y_0 < y) ，
 * 那么 y * x_0 = x * y_0 ，即 x_0 / x = y_0 / y 。
 *   sum_(i=1)^(x-1) sum_(j=1)^(y-1) [x/i = y/j]
 * = gcd(x, y)
 *
 *   sum_(i=1)^n sum_(j=1)^m (2(gcd(i, j) - 1) + 1)
 * = sum_(i=1)^n sum_(j=1)^m (2gcd(i, j) - 2) + nm
 * = 2 sum_(i=1)^n sum_(j=1)^m gcd(i, j) - nm
 *
 * 这个式子可以用莫比乌斯反演做。但是我不会。所以看了题解，上面说可以容斥一下。
 * https://www.luogu.org/blog/PopulusEuphratica/post-xue-xi-bi-ji-mu-bi-wu-si-fan-yan-mian-xiang-oi-ban
 *
 * > 令 
 * > f(x) = sum_(i=1)^n sum_(j=1)^m [gcd(i, j) = x]
 * > g(x) = sum_(i=1)^n sum_(j=1)^m [x|i and x|j]
 * > g(x)=(n/x)*(m/x)
 * > 但是这些数对中有一些的最大公因数为2d,3d,4d,我们要把他们减掉
 * > 于是最终f[x]=(n/x)*(m/x)-Σ(2*x<=i*x<=min(m,n))f[i*x]
 *
 * 令 n > m
 * g(x) = sum_(i=1)^n sum_(j=1)^m [x|i and x|j]
 * g(x) = sum_(i=1)^n [x|i] * sum_(i=1)^m [x|j]
 * g(x) = (n/x)(m/x)
 *
 * f(x) = g(x) - sum_(i=2)^(m/x) f(ix)
 * f(x) = (n/x)(m/x) - sum_(i=2)^(m/x) f(ix)
 */

#include <stdio.h>
#include <string.h>

long long F[1000009];

void single_init(void)
{
	memset(F, 0, sizeof(F));
}

void solve_single(int n, int m)
{
	/*
	 * n < m
	 * f(x) = (n/x)(m/x) - sum_(i=2)^(m/x) f(ix)
	 */

	int i, j;
	long long ans = 0;

	single_init();

	if (n > m) {
		int t = n;
		n = m;
		m = t;
	}

	for (i = n; i >= 1; --i) {
		F[i] = (long long)(n / i) * (m / i);
		for (j = 2; j * i <= m; ++j)
			F[i] -= F[j * i];
		ans += i * F[i];
	}

	ans = ans * 2 - (long long)n * m;

	printf("%lld\n", ans);
}

void global_init(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
}

int main(void)
{
	int a, b;
	global_init();
	while (scanf("%d%d", &a, &b) != EOF)
		solve_single(a, b);
	return 0;
}
