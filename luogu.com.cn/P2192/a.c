#include <stdio.h>

int five, zero, n;

int main(void)
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		if (x == 5)
			++five;
		else
			++zero;
	}
	if (zero == 0) {
		puts("-1");
	} else {
		if (five < 9) {
			puts("0");
		} else {
			five = (int)(five / 9) * 9;
			for (i = 0; i < five; ++i)
				putchar('5');
			while (zero--)
				putchar('0');
			putchar('\n');
		}
	}
	return 0;
}
