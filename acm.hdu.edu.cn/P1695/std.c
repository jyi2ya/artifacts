/*
 * 题意
 * ====
 * 给定 a, b, c, d, k ，求 sum_(x=a)^b sum_(y=c)^d [gcd(x, y) = k]
 * (x, y) 和 (y, x) 被认为是一种。
 *
 * a = 1, c = 1
 *
 * sum_(i=1)^b sum_(j=1)^d [gcd(i, j) = k]
 */

#include <stdio.h>

struct {
	int case_cnt;
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

int main_(void)
{
	long long i, j;
	long long a, b, c, d, k;
	long long ans = 0;

	scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &k);

	if (b > d) {
		long long t = b;
		b = d;
		d = t;
	}

	b /= k;
	d /= k;

	for (i = 1; i <= b; ++i)
		for (j = i; j <= d; ++j)
			if (llgcd(i, j) == 1)
				++ans;

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

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &t);

	for (S.case_cnt = 1; S.case_cnt <= t; ++S.case_cnt)
		start_();

#ifdef DEBUG
	fclose(stdin);
#endif

	return 0;
}
