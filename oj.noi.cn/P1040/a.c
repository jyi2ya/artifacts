#include <stdio.h>

long long gcd(long long a, long long b);

int main(void)
{
	long long a, b, i, gg;
	scanf("%lld%lld", &a, &b);
	while ((gg = gcd(a, b)) != 1)
		b /= gg;
	if (b == 1)
		puts("Yes");
	else
		puts("No");
	return 0;
}

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}
