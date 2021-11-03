#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	srand(0x66ccff);
	puts("100000 20");
	for (i = 0; i < 100000; ++i)
		putchar(rand() % 26 + 'a');
	putchar('\n');
	return 0;
}
