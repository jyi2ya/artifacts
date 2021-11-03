int magic[] = {
1,2,            0,3,4,5,6,7,0,8,       9,10,       11,12,
13,                   0,14,              15,16,   17,18,
0,19,                 20,21,                22,    23,
24,                   0,25,                   26,27,
28,                   29,0,                   30,31,
0,3,                  8,0,                     1,4,
9,14,                 19,0,                    2,5,
10,                   15,20,                   25,
0,6,                  11,16,                   21,
26,0,                 7,12,                    17,
22,                   27,30,                   0,13,
18,23,28,31,0,        24,29,                   0,7,
13,0,2,6,12,18,       24,0,                    1,5,


     11,17,23,
   29,       0,4,
  10,          16,
 22,            28,
0,              3,9,
15,               21, /* 我觉得吧，这儿我画不下了。 */
 27,            31,
  0,           8,
   14,20,26,30,0,
19,25,0,1,2,6,11,10,4,5,0,3,4,10,15,14,8,9,0,6,7,13,18,17,11,12,0,10,
11,17,22,21,15,16,0,14,15,21,26,25,19,20,0,17,18,22,24,28,29,23,0,21,
22,28,31,30,26,27,0,
};

int affect[32][32];
int spread[32][32];
int top[32];

void convert_the_fucking_magic_to_a_magic_table(void)
{
	register int i, j, k;
	i = 0;
	while (i < (int)(sizeof(magic) / sizeof(*magic))) {
		for (j = i; magic[j]; ++j)
			for (k = i; magic[k]; ++k)
				if (magic[j] != magic[k]) {
					spread[magic[j]][top[magic[j]]++] =
						magic[k];
					affect[magic[j]][magic[k]] = 1;
				}
		i = j + 1;
	}
}

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
		assert(sizeof(x__) == sizeof(x_)); \
		if (x_ != 0) { \
			z_bp = z_bf; \
			if (x_ < 0) { \
				z_pc('-'); \
				x_ = -x_; \
			} \
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

int avail[32];
int cannot[32][32];
int ans[32];
int k, n;

int sch(int cur)
{
	register int i, j;

	if (cur == 32)
		return --n ? 0 : 1;

	for (i = 1; i < 32; ++i)
		if (!avail[i])
			return 0;

	if (ans[cur])
		return sch(cur + 1);

	for (i = 1; i <= k; ++i)
		if (!cannot[cur][i]) {
			ans[cur] = i;
			for (j = 0; j < top[cur]; ++j) {
				if (!cannot[spread[cur][j]][i])
					--avail[spread[cur][j]];
				++cannot[spread[cur][j]][i];
			}

			if (sch(cur + 1))
				return 1;

			for (j = 0; j < top[cur]; ++j) {
				--cannot[spread[cur][j]][i];
				if (!cannot[spread[cur][j]][i])
					++avail[spread[cur][j]];
			}
		}

	ans[cur] = 0;

	return 0;
}

int main(void)
{
	register int i, j;

	z_ini();
#define PROG "hexodoku"
#ifndef ONLINE_JUDGE 
	freopen(PROG ".in", "r", stdin);
#ifndef DEBUG
	freopen(PROG ".out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	convert_the_fucking_magic_to_a_magic_table();
	z_get(int, k);
	z_get(int, n);
	for (i = 1; i < 32; ++i)
		avail[i] = k;
	for (i = 1; i < 32; ++i) {
		z_get(int, ans[i]);
		if (ans[i]) {
			for (j = 1; j < 32; ++j)
				if (affect[i][j]) {
					if (!cannot[j][ans[i]])
						--avail[j];
					++cannot[j][ans[i]];
				}
			for (j = 1; j <= k; ++j)
				if (j != ans[i])
					++cannot[i][j];
			avail[i] = 1;
		}
	}

	if (sch(1)) {
		z_pstr("Found\n");
		for (i = 1; i < 32; ++i)
			z_put(int, ans[i], z_pc(' '));
		z_pc('\n');
	} else {
		z_pstr("No way\n");
	}
	return 0;
}
