#include <stdio.h>

int main(void)
{
	int c1, c2, p1, p2;
	scanf("%d%d%d%d", &c1, &p1, &c2, &p2);
	if (c1 * p2 > c2 * p1)
		printf("1");
	else
		printf("2");
	putchar('\n');
	return 0;
}
