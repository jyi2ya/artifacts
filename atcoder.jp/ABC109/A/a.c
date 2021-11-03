#include <stdio.h>

int main(void)
{
	int a, b, c, isok = 0;
	scanf("%d%d", &a, &b);
	for (c = 1; c <= 3; ++c)
		if ((a * b * c) % 2 == 1)
			isok = 1;
	if (isok) puts("Yes");
	else puts("No");
	return 0;
}
