#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
			code__; \
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

struct E {
	int src, dst;
};

struct {
	struct {
		int val, add;
		int deg, fir, las;
	} N[1000009];
	struct E E[2000009], tmp[2000009];
	int Ec;
} G;

#define g_ini()

#define g_add(u__, v__) \
	do { \
		G.E[G.Ec].src = u__; \
		G.E[G.Ec].dst = v__; \
		++G.Ec; \
	} while (0)

#define g_add2(u__, v__) \
	do { \
		g_add(u__, v__); \
		g_add(v__, u__); \
		++G.N[u__].deg; \
		++G.N[v__].deg; \
	} while (0)

int cmp(const void *a, const void *b)
{
	return G.N[((struct E *)b)->dst].deg - G.N[((struct E *)a)->dst].deg;
}

int main(void)
{
	register int n, m, q;
	register int i;

	z_ini();
#define PROG "sibyl"
#ifndef ONLINE_JUDGE
	freopen(PROG".in", "r", stdin);
#ifndef DEBUG
	freopen(PROG".out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	z_get(n);
	z_get(m);
	z_get(q);
	g_ini();
	while (m--) {
		register int u, v;
		z_get(u);
		z_get(v);
		g_add2(u, v);
	}
	qsort(G.E, G.Ec, sizeof(*G.E), cmp);
	for (i = 1; i <= n; ++i) {
		G.N[i].fir = G.N[i - 1].fir + G.N[i - 1].deg;
		G.N[i].las = G.N[i].fir;
	}
	for (i = 0; i < G.Ec; ++i)
		G.tmp[G.N[G.E[i].src].las++] = G.E[i];
	memcpy(G.E, G.tmp, sizeof(*G.tmp) * G.Ec);

	while (q--) {
		register int op;
		z_get(op);
		if (op == 0) {
			register int x;
			register int ans;
			z_get(x);
			ans = G.N[x].val;
			for (i = G.N[x].fir; i < G.N[x].las &&
					G.N[G.E[i].dst].deg > G.N[x].deg; ++i)
				ans += G.N[G.E[i].dst].add;
			z_put(int, ans, z_pc('\n'));
		} else {
			register int x, y;
			z_get(x);
			z_get(y);
			G.N[x].val += y;
			G.N[x].add += y;
			for (i = G.N[x].fir; i < G.N[x].las &&
					G.N[G.E[i].dst].deg >= G.N[x].deg; ++i)
				G.N[G.E[i].dst].val += y;
		}
	}

	return 0;
}
