#include <stdio.h>

int main(void)
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", (1 << a) * (b + 1));
	return 0;
}
