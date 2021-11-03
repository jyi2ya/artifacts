#include <stdio.h>

int main(void)
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", (a * (100 + c - b) - a * 100) / 100);
	return 0;
}
