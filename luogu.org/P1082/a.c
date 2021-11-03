#include <stdio.h>

typedef long long ll;

void exgcd(ll a, ll b, ll *x, ll *y);

int main(void)
{
	ll a, b, x, y;
	scanf("%lld%lld", &a, &b);
/*	if (a > b) { ll t = a; a = b; b = t; } */

	exgcd(a, b, &x, &y);
	if (x < 0) x = (x + b) % b;

	printf("%lld\n", x);
	return 0;
}

void exgcd(ll a, ll b, ll *x, ll *y)
{
	if (!b) { *y = 0; *x = 1; }
	else { exgcd(b, a % b, y, x); *y -= (a / b) * (*x); }
}
