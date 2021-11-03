#include <stdio.h>

long long mul(long long a, long long b);
void exgcd(long long a, long long b, long long *x, long long *y);

long long MOD;

int main(void)
{
	long long N, M, L, x, y, a;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%lld%lld%lld", &N, &M, &L);
	MOD = N + 1;
	exgcd(2, MOD, &x, &y);
	x = (x % MOD + MOD) % MOD;

	a = 1;
	while (M) {
		if (M & 1)
			a = mul(a, x) % MOD;
		x = mul(x, x) % MOD;
		M /= 2;
	}

	printf("%lld\n", mul(L, a) % MOD);
	return 0;
}

void exgcd(long long a, long long b, long long *x, long long *y)
{
	if (!b) {
		*x = 1;
		*y = 0;
	} else {
		exgcd(b, a % b, y, x);
		*y = (*y - mul(a / b, *x)) % MOD;
	}
}

long long mul(long long a, long long b)
{
	long long ans = 0;
	while (b) {
		if (b & 1)
			ans = (ans + a) % MOD;
		a = (a + a) % MOD;
		b /= 2;
	}
	return ans;
}
