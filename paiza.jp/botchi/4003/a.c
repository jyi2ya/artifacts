#include <stdio.h>

int main(void)
{
	int i;
	char buf[109];
	scanf("%s", buf);
	for (i = 0; buf[i] != '\0'; ++i)
		if (!(i & 1))
			putchar(buf[i]);
	return 0;
}
