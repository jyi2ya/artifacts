#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a, b, c, max, mid, min;
	scanf("%d%d%d", &a, &b, &c);

	max = a;
	if (b > max) max = b;
	if (c > max) max = c;

	min = a;
	if (b < min) min = b;
	if (c < min) min = c;

	mid = a + b + c - min - max;

	printf("%d\n", max * 10 + mid + min);
	return 0;
}
