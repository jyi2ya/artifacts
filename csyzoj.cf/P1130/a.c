#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char z_rbf[BUFSIZ], z_wbf[BUFSIZ], z_bf[41];
char *z_rp = &z_rbf[BUFSIZ], *z_wp = z_wbf, *z_bp;

#define z_gc() \
	(z_rp == &z_rbf[BUFSIZ] ? \
	 (z_rp = z_rbf, fread(z_rp, BUFSIZ, 1, stdin), *z_rp++) : \
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

#define z_put(type__, x__, code__) \
	do { \
		register type__ x_ = x__; \
		z_bp = z_bf; \
		if (x_ == 0) { \
			z_pc('0'); \
			break; \
		} \
		if (x_ < 0) { \
			z_pc('-'); \
			x_ = -x_; \
		} \
		while (x_) { \
			*++z_bp = x_ % 10 + '0'; \
			x_ /= 10; \
		} \
		while (z_bp != z_bf) \
			z_pc(*z_bp--); \
		code__; \
	} while (0)

#define z_pstr(s__) \
	do { \
		register char *s_ = (char *)s__; \
		while (*s_) { \
			z_pc(*s_); \
			++s_; \
		} \
	} while (0)

void z_flush(void)
{
	fwrite(z_wbf, z_wp - z_wbf, 1, stdout);
}

#define z_ini() atexit(z_flush)

void solve(void)
{
	register int n;
	register int last_t = 0, last_x = 0, last_y = 0;
	register int flag = 1;
	z_get(n);

	while (n--) {
		register int t, x, y;
		register int dis;
		register int dt;
		z_get(t);
		z_get(x);
		z_get(y);
		dis = abs(last_x - x) + abs(last_y - y);
		dt = abs(last_t - t);
		if (((dis & 1) ^ (dt & 1)) || dt < dis)
			flag = 0;
		last_x = x;
		last_y = y;
		last_t = t;
	}

	if (flag)
		z_pstr("Yes\n");
	else
		z_pstr("No\n");
}

int main(void)
{
	register int T;

	z_ini();
#define PROG "charlotte"
#ifndef ONLINE_JUDGE
	freopen(PROG".in", "r", stdin);
#ifndef DEBUG
	freopen(PROG".out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	z_get(T);
	while (T--)
		solve();

	return 0;
}
