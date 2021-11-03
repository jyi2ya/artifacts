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

#define MOD 1000000007LL

int main(void)
{
	register long long n, m;
	register long long i, j;
	register long long jmp;
	static long long dp[109][100009];
	register long long difcnt = 1;
	register long long last;
	register long long next;
	register long long cnt;

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

	for (i = 1; i <= m; i = jmp + 1) {
		jmp = m / (m / i);
		dp[n][difcnt + 1] = (dp[n][difcnt] + (jmp - i + 1)) % MOD;
		++difcnt;
	}

	for (i = n - 1; i >= 0; --i) {
		last = 0;
		next = 1;
		cnt = difcnt;

		dp[i][1] = dp[i + 1][difcnt];
		for (j = 1; j <= m; j = jmp + 1) {
			jmp = m / (m / j);
			++next;
			dp[i][next] = (dp[i][last] + (jmp - j + 1) *
					dp[i + 1][cnt--] % MOD) % MOD;
			last = next;
		}
	}

	z_put(long long, dp[1][difcnt], z_pc('\n'));

	return 0;
}
