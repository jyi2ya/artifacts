#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char z_rbf[BUFSIZ], *z_rp = &z_rbf[BUFSIZ];
char z_wbf[BUFSIZ], *z_wp = z_wbf;
char z_buf[31], *z_bp;

#define z_gc() \
	(z_rp == &z_rbf[BUFSIZ] ? \
	 (z_rp = z_rbf, fread(z_rbf, BUFSIZ, 1, stdin), *z_rp++) : \
	 (*z_rp++)) \

#define z_get(x__) \
	do { \
		register int ch_, f_ = 1; \
		while (!isdigit(ch_ = z_gc())) \
			if (ch_ == '-') \
				f_ = -1; \
		x__ = ch_ - '0'; \
		while (isdigit(ch_ = z_gc())) \
			x__ = x__ * 10 + ch_ - '0'; \
		x__ *= f_; \
	} while (0)

#define z_pc(x__) \
	do { \
		*z_wp++ = x__; \
		if (z_wp == &z_wbf[BUFSIZ]) { \
			z_wp = z_wbf; \
			fwrite(z_wp, BUFSIZ, 1, stdout); \
		} \
	} while (0)

#define z_put(type__, x__, code__) \
	do { \
		register type__ x_ = x__; \
		z_bp = z_buf; \
		if (x_ < 0) { \
			x_ = -x_; \
			z_pc('-'); \
		} \
		if (x_ == 0) { \
			z_pc('0'); \
			break; \
		} \
		while (x_) { \
			*++z_bp = x_ % 10 + '0'; \
			x_ /= 10; \
		} \
		while (z_bp != z_buf) \
			z_pc(*z_bp--); \
		code__; \
	} while (0)

void z_flush(void)
{
	fwrite(z_wbf, 1, z_wp - z_wbf, stdout);
}

#define z_ini() atexit(z_flush)

int main(void)
{
	static long long val[100];
	static struct {
		int u, v;
	} E[200009];
	register int i, j;
	register long long Y;
	register int cnt = 0;
#define add_edge(u__, v__) \
	do { \
		E[cnt].u = u__; \
		E[cnt].v = v__; \
		++cnt; \
	} while (0)

	z_ini();
#define PROG "review"
#ifndef ONLINE_JUDGE
	freopen(PROG".in", "r", stdin);
#ifndef DEBUG
	freopen(PROG".out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	z_get(Y);
	val[1] = val[2] = 1;
	add_edge(1, 2);
	for (i = 3; i < 64; ++i) {
		for (j = 1; j < i; ++j) {
			val[i] += val[j];
			add_edge(j, i);
		}
	}
	for (i = 63; i >= 1; --i)
		if (val[i] <= Y) {
			add_edge(i, 64);
			Y -= val[i];
		}
	z_put(int, 64, z_pc(' '));
	z_put(int, cnt, z_pc('\n'));
	for (i = 0; i < cnt; ++i) {
		z_put(int, E[i].u, z_pc(' '));
		z_put(int, E[i].v, z_pc('\n'));
	}
	return 0;
}
