#include <stdio.h>

int main(void)
{
	char buf[109];
	int s, n;
	scanf("%d", &n);
	while (n--) {
		scanf("%s%d", buf, &s);
		if (s == 3)
			puts(buf);
	}
	return 0;
}
