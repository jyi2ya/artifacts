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

unsigned int val[100009];
unsigned int tmp[100009];
unsigned int cnt[256];

int main(void)
{
	register int n;
	register unsigned int *p, *q;
	register unsigned int *cap;
	register int shift;

	z_ini();
#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	z_get(n);
	for (p = val, cap = &val[n]; p != cap; ++p)
		z_get(*p);

	for (shift = 0; shift < 4; ++shift) {
		for (p = cnt, cap = &cnt[256]; p != cap; ++p)
			*p = 0;
		for (p = val, cap = &val[n]; p != cap; ++p)
			++cnt[*p >> (shift << 3) & 0xff];
		for (p = cnt, cap = &cnt[256]; p != cap; ++p)
			*p += p[-1];
		for (p = &val[n - 1], cap = val - 1; p != cap; --p)
			tmp[--cnt[*p >> (shift << 3) & 0xff]] = *p;
		cap = &val[n];
		p = val, q = tmp;
		while (p != cap)
			*p++ = *q++;
	}

	for (p = val, cap = &val[n]; p != cap; ++p)
		z_put(unsigned int, *p, z_pc(' '));
	z_pc('\n');
	return 0;
}
