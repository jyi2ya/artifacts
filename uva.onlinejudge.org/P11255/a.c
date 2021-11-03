/*
 * 这道题目跟 UVa 10601 很像。是一个弱化版。用一样的做法就可以通过了。
 */
#include <stdio.h>

#define CBUF (70)
long long C[CBUF][CBUF];

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

long long magic(int a, int b, int c, int size)
{
	int n = a + b + c;
	int num = n / size;
	if (a < 0 || b < 0 || c < 0 || a % size || b % size || c % size)
		return 0;
	return C[num][a / size] *
		C[num - a / size][b / size] *
		C[num - a / size - b / size][c / size];
}

int main(void)
{
	int T;
	int i, j;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	for (i = 0; i < CBUF; ++i)
		C[i][0] = C[i][i] = 1;
	for (i = 1; i < CBUF; ++i)
		for (j = 1; j <= i; ++j)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];

	scanf("%d", &T);
	while (T--) {
		int a, b, c;
		int n;
		long long ans = 0;

		scanf("%d%d%d", &a, &b, &c);
		n = a + b + c;

		for (i = 1; i <= n; ++i)
			ans += magic(a, b, c, n / gcd(n, i));

		if (n & 1) {
			ans += (
					magic(a - 1, b, c, 2) +
					magic(a, b - 1, c, 2) +
					magic(a, b, c - 1, 2)
			       ) * (n);
		} else {
			ans += (
					magic(a - 1, b - 1, c, 2) +
					magic(a - 1, b, c - 1, 2) +
					magic(a, b - 1, c - 1, 2)
			       ) * (n / 2) * 2 +

				(
				 magic(a - 2, b, c, 2) +
				 magic(a, b - 2, c, 2) +
				 magic(a, b, c - 2, 2)
				) * (n / 2) +

				magic(a, b, c, 2) * (n / 2);
		}

		printf("%lld\n", ans / 2 / n);
	}

	return 0;
}
