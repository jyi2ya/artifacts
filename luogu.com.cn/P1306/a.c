/* Tips : gcd(f(i), f(j)) = f(gcd(i, j)); */

#include <stdio.h>
#include <string.h>

#define MOD 100000000

long long f(long long x);
long long gcd(long long a, long long b);

int main(void)
{
	long long n, m, fn, fm, x;
	scanf("%lld%lld", &n, &m);
	x = gcd(n, m);
	printf("%lld\n", f(x));
	return 0;
}

long long gcd(long long a, long long b)
{
	while (b) {
		long long t = a % b;
		a = b;
		b = t;
	}
	return a;
}

long long f(long long x)
{
	register int i, j, k;
	--x;
	long long base[1][2] = { {1, 1} }, mul[2][2] = { { 1, 1 }, { 1, 0 } };
	long long basetmp[1][2], multmp[2][2];
	while (x) {
		if (x & 1) {
			memset(basetmp, 0, sizeof(basetmp));
			for (i = 0; i < 1; ++i)
				for (j = 0; j < 2; ++j)
					for (k = 0; k < 2; ++k)
						basetmp[i][j] = (basetmp[i][j] + base[i][k] * mul[k][j] % MOD) % MOD;
			memcpy(base, basetmp, sizeof(basetmp));
		}
		memset(multmp, 0, sizeof(multmp));
		for (i = 0; i < 2; ++i)
			for (j = 0; j < 2; ++j)
				for (k = 0; k < 2; ++k)
					multmp[i][j] = (multmp[i][j] + mul[i][k] * mul[k][j] % MOD) % MOD;
		memcpy(mul, multmp, sizeof(multmp));
		x /= 2;
	}
	return base[0][1];
}
