/*
 * 这可能是我今年写过的最丑的代码了。
 */

#include <stdio.h>

void gao(void)
{
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	if (a == 1) {
		puts("0");
	} else {
		if (n == 2) {
			if (a % 2) {
				puts("0");
			} else if (b % 2 && a == 0) {
				puts("0");

			} else {
				if (a + b >= 2)
					puts("1");
				else
					puts("0");
			}
		} else {
			if (a == n)
				puts("1");
			else if (b == n)
				puts("1");
			else if (a + b >= n + 1)
				puts("1");
			else
				puts("0");
		}
	}
}

int main(void)
{
	int T;
	scanf("%*d%d", &T);
	while (T--)
		gao();
	return 0;
}
