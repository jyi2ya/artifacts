#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[102], *p;
	int cnt = 0;
	scanf("%s", a);
	while ((p = strstr(a, "cat")) != NULL) {
		p[0] = '#';
		p[1] = '#';
		p[2] = '#';
		++cnt;
	}
	printf("%d", cnt);
	return 0;
}
