#include <stdio.h>

long long L;
long long ex_gcd(long long a, long long b, long long *x, long long *y);
long long gcd(long long a, long long b);

int main(void)
{
	long long x, y, m, n, a, b, k, gg, t;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	while (scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &L) == 5) {
		a = m - n;
		b = y - x;
		if (a < 0) {
			a = -a;
			b = -b;
		}
		while (b < 0)
			b += L;
		a %= L;
		b %= L;

		gg = ex_gcd(a, L, &t, &k);

		if (!gg || b % gg) {
			puts("Impossible");
			continue;
		}

		if (gg) {
			t = t * b / gg % L;
			k = t * b / gg % L;
		}

		gg = gcd(a, L);
		t %= (L / gg);
		t += L;
		t %= (L / gg);
		k %= (a / gg);
		k += L;
		k %= (a / gg);

		printf("%lld\n", t);
	}
	return 0;
}

long long ex_gcd(long long a, long long b, long long *x, long long *y)
{
	long long ret = a;
	if (!b){
		*x = 1;
		*y = 0;
	} else {
		ret = ex_gcd(b, a % b, y, x);
		*y = (*y - (a / b) * (*x) + L) % L;
	}
	return ret % L;
}

long long gcd(long long a, long long b)
{
	while (b) {
		long long t = a % b;
		a = b;
		b = t;
	}
	return a % L;
}
