#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;
typedef unsigned long long int ull;

ull mod;

ull ullmul(ull a, ull b)
{
	ull ans = 0;
	while (b) {
		if (b & 1)
			ans = (ans + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return ans;
}

ull ullpow(ull a, ull b)
{
	ull ans = 1;
	while (b) {
		if (b & 1)
			ans = ullmul(ans, a);
		a = ullmul(a, a);
		b >>= 1;
	}
	return ans;
}

int is_prime(ull x)
{
	ull d = x - 1;
	int cnt = 0;
	unsigned long long test[] = { 2, 3, 7, 61, 24251 };
	unsigned int j;

	if ((x & 1) == 0 || (x < 3))
		return x == 2;

	while ((d & 1) == 0) {
		++cnt;
		d >>= 1;
	}

	mod = x;

	for (j = 0; j < sizeof(test) / sizeof(test[0]); ++j) {
		ull t = test[j];
		ull v = ullpow(t, d);
		int i;

		if (v == 1 || v == x - 1)
			continue;

		for (i = 0; i < cnt; ++i) {
			v = ullmul(v, v);
			if (v == x - 1)
				break;
		}
		if (i == cnt)
			return 0;
	}
	return 1;
}

int main(void)
{
	ull x;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	srand(0x66ccff);
	scanf("%*d");

	while (scanf("%llu", &x) != EOF)
		puts(is_prime(x) ? "Prime" : "Not prime");

#ifdef DEBUG
	fclose(stdin);
#endif
	return 0;
}
