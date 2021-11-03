/*
 * 题意
 * ====
 * 给定 a, b, c, d, k ，求 sum_(x=a)^b sum_(y=c)^d [gcd(x, y) = k]
 * (x, y) 和 (y, x) 被认为是一种。
 *
 * a = 1, c = 1
 *
 * 令 b < d
 *
 * 设 g(x) = sum_(i=2)^(x) phi(i)
 * s = sum_(i=1)^b sum_(j=i)^d [gcd(i, j) = k]
 * = sum_(i=1)^(b/k) sum_(j=i)^(d/k) [gcd(i, j) = 1]
 * = sum_(i=1)^(b/k) sum_(j=1)^(d/k) [gcd(i, j) = 1] -
 *   sum_(i=1)^(b/k) sum_(j=1)^(i-1) [gcd(i, j) = 1]
 * = sum_(i=1)^(b/k) sum_(j=1)^(d/k) [gcd(i, j) = 1] - g(b/k)
 *
 * g(b/k) 可以预处理出来。所以不重点考虑。
 *
 * 设 b_1 = b/k, d_1 = d/k
 * 设 f(x) = sum_(i=1)^(d_1) [gcd(x, i) = 1]
 * sum_(i=1)^(b_1) sum_(j=1)^(d_1) [gcd(i, j) = 1]
 * = sum_(i=1)^(b_1) f(i)
 *
 * d_1 = p_1^(a_1) p_2^(a_2) ... p_k^(a_k)
 * P = { p_1, p_2, ..., p_k }
 *
 * f(x) = sum_(i=1)^(d_1) [gcd(x, i) = 1]
 * = d_1 - sum_(i=1)^(d_1) [gcd(x, i) != 1]
 * = d_1 - sum_(i=1)^(d_1) [gcd(x, i) != 1]
 * = d_1 - sum_(S sube P) ((-1)^(abs(S) - 1) * d_1 / (prod_(i in S) i))
 *
 * s = (sum_(i=1)^(b_1) f(i)) - g(b_1)
 */

#include <stdio.h>

#define NMAX 1000000
struct {
	int case_cnt;
	int b, d;
	int phi[NMAX];
	int is_not_prime[NMAX];
	long long prime[NMAX];
	long long phisum[NMAX];
} S;

long long llgcd(long long a, long long b)
{
	while (b) {
		long long t = a % b;
		a = b;
		b = t;
	}
	return a;
}

long long llphi(long long x)
{
	long long a = x;
	long long i;
	for (i = 2; i * i <= x; ++i)
		if (x % i == 0) {
			a -= a / i;
			while (x % i == 0)
				x /= i;
			if (x == 1)
				break;
		}
	if (x > 1)
		a -= a / x;
	return a;
}

/*
 * g(x) = sum_(i=2)^(x) phi(i)
 */
#define g(x) (S.phisum[x])

int factor(long long *ans, long long x)
{
	int k = 0;
	long long *p;
	for (p = S.prime; *p * *p <= x; ++p)
		if (x % *p == 0) {
			ans[k++] = *p;
			while (x % *p == 0)
				x /= *p;
		}
	if (x > 1)
		ans[k++] = x;
	return k;
}

/*
 * f(x) = sum_(i=1)^(d_1) [gcd(x, i) = 1]
 */
long long f(long long x)
{
	long long fac[64];
	int fac_num;
	unsigned int mask;
	long long ans = S.d;

	fac_num = factor(fac, x);

	for (mask = 1; mask < (1U << fac_num); ++mask) {
		int cnt = 0;
		int i;
		long long prod = 1;

		for (i = 0; i < fac_num; ++i)
			if (mask & (1U << i)) {
				++cnt;
				prod *= fac[i];
			}

		ans += ((cnt & 1) ? (-1) : (1)) * (S.d / prod);
	}

	return ans;
}

int main_(void)
{
	long long i;
	long long a, b, c, d, k;
	long long ans = 0;

	scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &k);

	if (b > d) {
		long long t = b;
		b = d;
		d = t;
	}

	if (k != 0) {
		b /= k;
		d /= k;

		S.b = b;
		S.d = d;

		/* s = (sum_(i=1)^(b_1) f(i)) - g(b_1) */
		for (i = 1; i <= b; ++i)
			ans += f(i);
		ans -= g(b);
	}

	printf("Case %d: %lld\n", S.case_cnt, ans);

	return 0;
}

int start_(void)
{
	return main_();
}

int main(void)
{
	int t;
	int i, j, k = 0;
	int *phi = S.phi;
	int *is_not_prime = S.is_not_prime;
	long long *phisum = S.phisum;
	long long *prime = S.prime;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	for (i = 0; i < NMAX; ++i)
		phi[i] = i;
	for (i = 2; i < NMAX; ++i)
		if (!is_not_prime[i]) {
			prime[k++] = i;
			phi[i] = i - 1;
			for (j = i + i; j < NMAX; j += i) {
				is_not_prime[j] = 1;
				phi[j] -= phi[j] / i;
			}
		}

	for (i = 2; i < NMAX; ++i)
		phisum[i] = phisum[i - 1] + phi[i];

	scanf("%d", &t);

	for (S.case_cnt = 1; S.case_cnt <= t; ++S.case_cnt)
		start_();

#ifdef DEBUG
	fclose(stdin);
#endif

	return 0;
}
