#include <stdio.h>
#include <string.h>

#define MAX 1000009

int red[MAX], green[MAX], diff[MAX], last[MAX * 2];
char str[MAX];

int main(void)
{
	int i, ans = 0;
	int len;
	scanf("%s", str + 1);
	len = strlen(str + 1) + 1;
	for (i = 1; str[i] != '\0'; ++i) {
		red[i] = red[i - 1];
		green[i] = green[i - 1];

		if (str[i] == 'R')
			++red[i];
		else
			++green[i];

		diff[i] = red[i] - green[i];
	}
	for (i = len - 1; i > 0; --i)
		if (!last[diff[i] + MAX])
			last[diff[i] + MAX] = i;
	for (i = 0; i < len; ++i)
		if (last[diff[i] + MAX] - i > ans)
			ans = last[diff[i] + MAX] - i;
	printf("%d\n", ans);
	return 0;
}
