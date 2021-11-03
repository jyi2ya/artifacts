#include <stdio.h>
#include <string.h>

char str[109][20];

int same(int x)
{
	int i;
	for (i = 0; i < x; ++i)
		if (strcmp(str[i], str[x]) == 0)
			return 1;
	return 0;
}

int main(void)
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%s", str[i]);
		if (same(i)) {
			puts("No");
			return 0;
		}
		if (i && str[i - 1][strlen(str[i - 1]) - 1] != str[i][0]) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}
