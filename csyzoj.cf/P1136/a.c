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
		whlie (*s_) \
			z_pc(*s_++); \
	} while (0)

void z_flush(void)
{
	fwrite(z_wbf, z_wp - z_wbf, 1, stdout);
}

#define z_ini() atexit(z_flush)

int gt(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main(void)
{
	register int n;
	register int i, j;

	static int val[5][1000009];
	static int cnt[5];

	register int cnt1 = 0, cnt2 = 0;
	register int num = 0;

	register int ans = 0;

	register int dt1, dt2;
	register int *mgr1, *mgr2;
	register int res1, res2;

	z_ini();
#define PROG "debate"
#ifndef ONLINE_JUDGE 
	freopen(PROG ".in", "r", stdin);
#ifndef DEBUG
	freopen(PROG ".out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	z_get(int, n);
	for (i = 0; i < n; ++i) {
		register int at, op;
		z_get(int, at);
		z_get(int, op);
		switch (at) {
			case 00: val[0][cnt[0]++] = op; break;
			case 01: val[1][cnt[1]++] = op; break;
			case 10: val[2][cnt[2]++] = op; break;
			case 11: val[3][cnt[3]++] = op; break;
		}
	}

	for (i = 0; i < cnt[3]; ++i) {
		ans += val[3][i];
		++cnt1;
		++cnt2;
		++num;
	}

	qsort(val[0], cnt[0], sizeof(*val[0]), gt);
	qsort(val[1], cnt[1], sizeof(*val[1]), gt);
	qsort(val[2], cnt[2], sizeof(*val[2]), gt);

	for (i = 0; i < cnt[1] && i < cnt[2]; ++i) {
		ans += val[1][i] + val[2][i];
		++cnt1;
		++cnt2;
		num += 2;
	}

	if (i == cnt[1]) {
		dt1 = 1, dt2 = 0;
		mgr1 = val[2], mgr2 = val[0];
		res1 = cnt[2], res2 = cnt[0];
	} else {
		dt1 = 0, dt2 = 1;
		mgr1 = val[1], mgr2 = val[0];
		res1 = cnt[1], res2 = cnt[0];
	}
	j = 0;

	while (i < res1 && j < res2) {
		if (mgr1[i] < mgr2[j] && cnt1 * 2 >= num + 1 &&
				cnt2 * 2 >= num + 1) {
			ans += mgr2[j++];
			++num;
		} else if ((cnt1 + dt1) * 2 >= num + 1 &&
				(cnt2 + dt2) * 2 >= num + 1) {
			ans += mgr1[i++];
			++num;
			cnt1 += dt1;
			cnt2 += dt2;
		} else {
			break;
		}
	}

	while (i < res1 && (cnt1 + dt1) * 2 >= num + 1 &&
				(cnt2 + dt2) * 2 >= num + 1) {
		++num;
		cnt1 += dt1;
		cnt2 += dt2;
		ans += mgr1[i++];
	}

	while (j < res2 && cnt1 * 2 >= num + 1 && cnt2 * 2 >= num + 1) {
		++num;
		ans += mgr2[j++];
	}

	printf("%d\n", ans);
	return 0;
}
