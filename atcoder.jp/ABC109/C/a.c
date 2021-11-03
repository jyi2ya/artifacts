#include <stdio.h>

int abs(int a);
int gcd(int a, int b);

int N, X;
int a[100009];

int main(void)
{
	int i, ans;
	scanf("%d%d", &N, &X);
	for (i = 0; i < N; ++i) scanf("%d", a + i);
	for (i = 0; i < N; ++i) a[i] = abs(X - a[i]);
	ans = a[0];
	for (i = 0; i < N; ++i) ans = gcd(ans, a[i]);
	printf("%d\n", ans);
	return 0;
}

int abs(int x)
{
	if (x < 0) return -x;
	return x;
}

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
