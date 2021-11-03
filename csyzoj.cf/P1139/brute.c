#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#ifndef DEBUG
#define NDEBUG
#endif
#include <assert.h>

char z_rbf[BUFSIZ], z_wbf[BUFSIZ], z_bf[41];
char *z_rp = &z_rbf[BUFSIZ], *z_wp = z_wbf, *z_bp;

#define z_gc() \
	(z_rp == &z_rbf[BUFSIZ] ? \
	 (z_rp = z_rbf, fread(z_rbf, BUFSIZ, 1, stdin), *z_rp++) : \
	 (*z_rp++))

#define z_pc(x__) \
	do { \
		if (z_wp != &z_wbf[BUFSIZ]) { \
			*z_wp++ = x__; \
		} else { \
			z_wp = z_wbf; \
			fwrite(z_wp, BUFSIZ, 1, stdout); \
			*z_wp++ = x__; \
		} \
	} while (0)

#define z_get(type__, x__) \
	do { \
		register type__ x_; \
		register int ch_, f_ = 1; \
		assert(sizeof(x_) == sizeof(x__)); \
		while (!isdigit(ch_ = z_gc())) \
			if (ch_ == '-') \
				f_ = -1; \
		x_ = ch_ - '0'; \
		while (isdigit(ch_ = z_gc())) \
			x_ = x_ * 10 + ch_ - '0'; \
		x__ = x_ * f_; \
	} while (0)

#define z_put(type__, x__, code__) \
	do { \
		register type__ x_ = x__; \
		assert(sizeof(x_) == sizeof(x__)); \
		if (x_ != 0) { \
			if (x_ < 0) { \
				x_ = -x_; \
				z_pc('-'); \
			} \
			z_bp = z_bf; \
			do { \
				*++z_bp = x_ % 10 + '0'; \
				x_ /= 10; \
			} while (x_); \
			while (z_bp != z_bf) \
				z_pc(*z_bp--); \
		} else { \
			z_pc('0'); \
		} \
		code__; \
	} while (0)

#define z_pstr(s__) \
	do { \
		register char *s_ = (char *)s__; \
		while (*s_) \
			z_pc(*s_++); \
	} while (0)

void z_flush(void)
{
	fwrite(z_wbf, z_wp - z_wbf, 1, stdout);
}

#define z_ini() atexit(z_flush)

#include <string.h>

#define MOD 1000000007LL

int main(void)
{
	register long long n, m;
	register int i, j;
	static long long dp[109][50009];

	z_ini();
#define PROG "noname"
#ifndef ONLINE_JUDGE
	freopen(PROG ".in", "r", stdin);
#ifndef DEBUG
	freopen(PROG ".out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	z_get(long long, n);
	z_get(long long, m);

	for (i = 1; i <= m; ++i)
		dp[n][i] = dp[n][i - 1] + 1;
	for (i = n - 1; i >= 0; --i) {
		for (j = 1; j <= m; ++j)
			dp[i][j] = (dp[i][j - 1] + dp[i + 1][m / j]) % MOD;
	}

	z_put(long long, dp[1][m], z_pc('\n'));

	return 0;
}
