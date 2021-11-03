#include <stdio.h>

int main(void)
{
	int n = 0, x;
	while (scanf("%d", &x) == 1)
		n ^= x;
	printf("%d\n", n);
	return 0;
}
