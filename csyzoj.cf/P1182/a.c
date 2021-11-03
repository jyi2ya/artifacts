void guess(void);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD (998244353LL)

void exgcd(long long a, long long b, long long *x, long long *y)
{
	if (b) {
		exgcd(b, a % b, y, x);
		*y -= (a / b) * *x;
	} else {
		*x = 1;
		*y = 0;
	}
}

long long inv(long long a)
{
	long long x, y;
	exgcd(a, MOD, &x, &y);
	return (x + MOD) % MOD;
}

long long llpow(long long a, long long x)
{
	long long ret = 1;
	x %= (MOD - 1);
	while (x) {
		if (x & 1)
			ret = ret * a % MOD;
		a = a * a % MOD;
		x /= 2;
	}
	return ret;
}

int main(void)
{
	long long p, k;
	long long invp;
	long long invp1;
	long long ans;

#ifndef ONLINE_JUDGE
	freopen("coin.in", "r", stdin);
#ifndef DEBUG
	freopen("coin.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	scanf("%lld%lld", &p, &k);
	if (p == 1LL) {
		printf("%lld\n", k);
	} else {
		invp = inv(p);
		invp1 = inv(MOD + p - 1);
		ans = (MOD - invp1) * llpow(invp, k) % MOD;
		ans = (ans + invp1) % MOD;
		printf("%lld\n", ans);
	}

	return 0;
}

#ifdef DEBUG

double guess_brute(double p, int k)
{
	int test_time = 30000;
	char check[512];
	int i, j;
	double ok = 0.0;

	for (i = 0; i < k; ++i)
		check[i] = '1';
	check[k] = '\0';
	for (j = 0; j < test_time; ++j) {
		char *pos;
		char buf[4096];
		for (i = 0; i < (int)(sizeof(buf) / sizeof(*buf)); ++i)
			buf[i] = (rand() < p * RAND_MAX) ? '1' : '0';
		if ((pos = strstr(buf, check)) != NULL)
			ok += pos - buf + k;
		else
			ok += sizeof(buf) / sizeof(*buf) + k;
	}
	return ok / test_time;
}

double guess_float(double p, int k)
{
	double v = 0;
	static double dp[10009][1009];
	int i, j;

	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (i = 1; i < 10000; ++i) {
		for (j = 0; j < k; ++j)
			dp[i][0] += dp[i - 1][j];
		dp[i][0] *= (1.0 - p);
		for (j = 1; j <= k; ++j)
			dp[i][j] = dp[i - 1][j - 1] * p;
		v += dp[i][k] * i;
	}
	return v;
}

double guess_super(double p, int k)
{
	int i;
	double ans = 0;
	for (i = 1; i <= k; ++i)
		ans = (ans + 1) * (1.0 / p);
	return ans;
}

long long guess_super_mod(long long p, int k)
{
	int i;
	long long ans = 0;
	long long invp = inv(p);
	for (i = 1; i <= k; ++i)
		ans = (ans + 1) * invp % MOD;
	return ans;
}

long long guess_super_mod_fast(long long p, int k)
{
	long long invp = inv(p);
	long long invp1 = inv(MOD + p - 1);
	long long ans = (MOD - invp1) * llpow(invp, k) % MOD;
	return (ans + invp1) % MOD;
}

#include <assert.h>

void guess(void)
{
	long long i;
	for (i = 0; i < 50000; ++i)
		assert(guess_super_mod(239472393, i) ==
				guess_super_mod_fast(239472393, i));
	puts("PASS");
	exit(0);
	guess_brute(0.5, 1);
	long long p = inv(2);
	//long long k = 1;
	long long k = 1000000;
	long long ans = 1;
	for (i = 1; i <= k; ++i)
		ans = ans * inv(p) % MOD;
	printf("%lld\n", ans);
	exit(0);
}

#endif
