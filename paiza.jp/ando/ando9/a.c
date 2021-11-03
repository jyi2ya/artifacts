#include <stdio.h>

int main(void)
{
	char buf[1024];
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%s", buf);
		if (i)
			putchar('_');
		printf("%s", buf);
	}
	return 0;
}
