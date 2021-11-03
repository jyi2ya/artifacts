#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch, k, i, num[256], top = 0;
	while (!isdigit(ch = getchar()));
	num[top++] = ch;
	while (isdigit(ch = getchar()))
		num[top++] = ch;
	scanf("%d", &k);

	while (k--) {
		int j;
		for (i = 0; i < top && num[i] == -1; ++i);
		for (; num[i] == '0'; ++i)
			num[i] = -1;

		for (i = 0; i < top; ++i)
			if (num[i] > 0) {
				for (j = i + 1; num[j] < 0; ++j);
				if (num[j] < num[i]) {
					num[i] = -1;
					break;
				}
			}
	}

	for (i = 0; i < top; ++i)
		if (num[i] > 0)
			putchar(num[i]);
	putchar('\n');
	return 0;
}
