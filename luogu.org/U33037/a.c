#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int n, i, j, min, max;
	double (*intful)(double x);
	scanf("%d", &n);
	if (n & 1) {
		intful = floor;
		min = 0;
		max = n * 2;
	} else {
		intful = ceil;
		min = 1;
		max = n * 2 - 1;
	}
	for (i = min; i <= max; ++i) {
		for (j = min; j <= max; ++j) {
			int x, y;
			x = i - n; y = j - n;
			if (intful(sqrt(x * x + y * y) + 0.5) == n) {
				putchar('1');
			} else {
				putchar(' ');
			}
			putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
