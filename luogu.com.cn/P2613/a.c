#include <stdio.h>
#include <ctype.h>

#define MOD 19260817

long long getll(void);
long long exgcd(long long a, long long b, long long *x, long long *y);

int main(void)
{
	long long a, b, t, k, gcd;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	a = getll(), b = getll();
	gcd = exgcd(b, MOD, &t, &k);
	t = ((t % MOD) + MOD) % MOD;
	if (a % gcd)
		puts("Angry!");
	else
		printf("%lld\n", t * a / gcd % MOD);
	return 0;
}

long long getll(void)
{
	long long ans = 0;
	int ch;
	while (!isdigit(ch = getchar()));
	ans = ch - '0';
	while (isdigit(ch = getchar()))
		ans = (ans * 10 + ch - '0') % MOD;
	ungetc(ch, stdin);
	return ans;
}

long long exgcd(long long a, long long b, long long *x, long long *y)
{
	long long ret = a;
	if (!b) {
		*x = 1;
		*y = 0;
	} else {
		ret = exgcd(b, a % b, y, x);
		*y = (*y - (a / b) * *x) % MOD;
	}
	return ret;
}
