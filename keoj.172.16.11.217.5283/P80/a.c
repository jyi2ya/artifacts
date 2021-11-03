#include <stdio.h>
#include <ctype.h>

#define MOD 1000000009LL
#define MAGIC1 691504013LL
#define MAGIC2 308495997LL
#define MAGIC3 276601605LL

#define MULMOD(a, b) a = a * b % MOD

void gao(int x)
{
	register long long r1 = 1, r2 = 1;
	register long long a1 = MAGIC1, a2 = MAGIC2;
	while (x) {
		if (x & 1) {
			MULMOD(r1, a1);
			MULMOD(r2, a2);
		}
		MULMOD(a1, a1);
		MULMOD(a2, a2);
		x >>= 1;
	}
	printf("%lld\n", (r1 - r2 + MOD) % MOD * MAGIC3 % MOD);
}

#define ge getchar()

long long readll()
{
	long long x = 0;
	static char ch;
	while (!isdigit(ch = ge)) ;
	while (isdigit(ch))
		x = x * 10 + (ch ^ 48), ch = ge;
	return x;
}

int main(void)
{
	int T;
	T = readll();
	while (T--) {
		register long long n;
		register int t;
		n = readll();
		t = n % (MOD - 1);
		gao(t);
	}
	return 0;
}
