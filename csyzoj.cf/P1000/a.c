#include <stdio.h>

int main(void)
{
	unsigned char a, b;
	scanf("%hhu%hhu", &a, &b);
	printf("%hhu\n", a + b);
	return 0;
}
