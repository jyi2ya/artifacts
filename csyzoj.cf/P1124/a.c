#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char z_ib[BUFSIZ], *z_ip = &z_ib[BUFSIZ];
char z_ob[BUFSIZ], *z_op = z_ob;
char z_nb[31], *z_np;

#define z_pc(x__) \
	do { \
		if (z_op == &z_ob[BUFSIZ]) { \
			z_op = z_ob; \
			fwrite(z_op, 1, BUFSIZ, stdout); \
		} \
		*z_op++ = x__; \
	} while (0)

#define z_put(type__, x__, code__) \
	do { \
		register type__ x_ = (x__); \
		z_np = z_nb; \
		if (!x_) \
			*++z_np = '0'; \
		while (x_) { \
			*++z_np = x_ % 10 + '0'; \
			x_ /= 10; \
		} \
		while (z_np != z_nb) \
			z_pc(*z_np--); \
		code__; \
	} while (0)

#define z_gc() \
	(z_ip == &z_ib[BUFSIZ] ? \
	 z_ip = z_ib, fread(z_ip, 1, BUFSIZ, stdin), *z_ip++ : \
	 *z_ip++)

#define z_get(x__) \
	do { \
		register int f_ = 1, ch_; \
		while (!isdigit(ch_ = z_gc())) \
			if (ch_ == '-') \
				f_ = -1; \
		x__ = ch_ - '0'; \
		while (isdigit(ch_ = z_gc())) \
			x__ = x__ * 10 + ch_ - '0'; \
		x__ *= f_; \
	} while (0)

void z_flush(void)
{
	fwrite(z_ob, z_op - z_ob, 1, stdout);
}

#define z_ini() \
	atexit(z_flush);

#include <stdio.h>

long long f[309][309];
#define MOD 1000000007LL

int main(void)
{
	register int i, j, k;
	register int n, m;

	z_ini();
#ifndef ONLINE_JUDGE
	freopen("cake.in", "r", stdin);
#ifndef DEBUG
	freopen("cake.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	z_get(n);
	z_get(m);
	f[1][1] = 1;
	for (i = 2; i <= m; ++i)
		for (k = 1; k < i; ++k)
			f[1][i] = (f[1][i] + f[1][i - k] * f[1][k] % MOD) % MOD;
	for (i = 2; i <= n; ++i)
		for (j = 1; j <= m; ++j) {
			for (k = 1; k < i; ++k)
				f[i][j] = (f[i][j] + f[i - k][j] *
						f[k][j] % MOD) % MOD;
			for (k = 1; k < j; ++k)
				f[i][j] = (f[i][j] + f[i][j - k] *
						f[i][k] % MOD) % MOD;
		}
	z_put(long long, f[n][m], z_pc('\n'));
	return 0;
}
