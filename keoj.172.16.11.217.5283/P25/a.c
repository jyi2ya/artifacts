#include <stdio.h>

long long val[10000001];
char is_digit_base[257], *is_digit = is_digit_base + 1;

#define read(x) { \
	register int ch; \
	while (!is_digit[ch = getchar()]); \
	x = ch - '0'; \
	while (is_digit[ch = getchar()]) \
		x = x * 10 + ch - '0'; \
}

int main(){
	int n, m;

	for (n = '0'; n <= '9'; ++n)
		is_digit[n] = 1;

	read(n);
	read(m);
	while (m--) {
		register int l, r, op;
		register long long x, y, d;
		read(op);
		if (op == 1) {
			read(l);
			read(x);
			y = x;
			r = l;
			d = 0;
		} else {
			read(l);
			read(r);
			read(x);
			read(y);
			d = (r == l ? 0 : (y - x) / (r - l));
		}
		val[l] += x;
		val[l + 1] += d - x;
		val[r + 1] -= d + y;
		val[r + 2] += y;
	}

	{
		register long long x = 0, y = 0;
		register long long xx = 0, mx = 0;
		register long long *i, *cap = val + n + 1;
		for (i = val + 1; i != cap; ++i) {
			x += *i;
			y += x;
			xx ^= y;
			if (y > mx)
				mx = y;
		}
		printf("%lld %lld\n", mx, xx);
	}
	return 0;
}
