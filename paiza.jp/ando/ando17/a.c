#include <stdio.h>

int main(void)
{
	int a, b, cnt = 0;
	scanf("%d%d", &a, &b);
	while (cnt < b) {
		int i;
		for (i = 0; i < a && cnt < b; ++i, ++cnt)
			putchar('R');
		for (i = 0; i < a && cnt < b; ++i, ++cnt)
			putchar('W');
	}
	return 0;
}
