/*
 * 题意：给定 A, B, 求 sum_(i=A)^B [gcd(i, N) = 1] 。
 */
#include <stdio.h>

struct {
	int case_cnt;
} E;

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
	int case_cnt = E.case_cnt;
	long long a, b, n;
	long long i;
	long long ans = 0;

	scanf("%lld%lld%lld", &a, &b, &n);
	for (i = a; i <= b; ++i)
		if (llgcd(i, n) == 1)
			++ans;

	printf("Case #%d: %lld\n", case_cnt, ans);
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
	for (E.case_cnt = 1; E.case_cnt <= t; ++E.case_cnt)
		start_();

#ifdef DEBUG
	fclose(stdin);
#endif

	return 0;
}
