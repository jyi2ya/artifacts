/*
 * 题意：给定 A, B, 求 sum_(i=A)^B [gcd(i, N) = 1] 。
 *
 * 分析 sum_(i=A)^B [gcd(i, N) = 1] 这个式子。因为这是容斥的题目，所以用莫比乌斯
 * 反演会被打。因此考虑容斥。
 *
 * 设 f(x) = sum_(i=1)^x [gcd(i, N) = 1]
 * 答案为 f(B) - f(A - 1) 。
 * 直接求 f() （对我）很难，所以用所有数减去不合法的数。
 * 数 N 有 p_1, p_2, ..., p_k 共 k 个质因子。
 * 那么 p_1, p_2, ..., p_k 的倍数都不与 N 互质。这一部分数是要减掉的。
 * 但是 p_1p_2 的倍数在过程中被减掉了两次，所以要加回来。
 * 这样一分析就是一道经典的容斥的题了。
 */
#include <stdio.h>

#define PRIME_MAX 1000000

struct {
	long long prime[PRIME_MAX];
	long long fac[128];
	int is_not_prime[PRIME_MAX];
	int case_cnt;
	int fac_num;
	long long N;
} S;

int factor(long long N, long long *ans)
{
	int i, k = 0;
	long long *prime = S.prime;

	for (i = 0; prime[i] * prime[i] <= N; ++i)
		if (N % prime[i] == 0) {
			ans[k++] = prime[i];
			while (N % prime[i] == 0)
				N /= prime[i];
			if (N == 1)
				break;
		}

	if (N > 1)
		ans[k++] = N;

	return k;
}

long long f(long long x)
{
	long long ans = 0;
	long long *fac = S.fac;
	unsigned long long use;
	int fac_num = S.fac_num;

	for (use = 1; use < (1ULL << fac_num); ++use) {
		int cnt = 0;
		long long i;
		long long t = 1;

		for (i = 0; i < fac_num; ++i)
			if (use & (1 << i)) {
				t *= fac[i];
				++cnt;
			}

		ans += (x / t) * ((cnt & 1) ? 1 : -1);
	}

	return x - ans;
}

int main_(void)
{
	int case_cnt = S.case_cnt;
	long long a, b, n;

	scanf("%lld%lld%lld", &a, &b, &n);
	S.fac_num = factor(n, S.fac);
	S.N = n;
	printf("Case #%d: %lld\n", case_cnt, f(b) - f(a - 1));

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
	long long *prime = S.prime;
	int *is_not_prime = S.is_not_prime;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	for (i = 2; i < PRIME_MAX; ++i)
		if (!is_not_prime[i]) {
			prime[k++] = i;
			for (j = i + i; j < PRIME_MAX; j += i)
				is_not_prime[j] = 1;
		}

	scanf("%d", &t);
	for (S.case_cnt = 1; S.case_cnt <= t; ++S.case_cnt)
		start_();

#ifdef DSBUG
	fclose(stdin);
#endif

	return 0;
}
