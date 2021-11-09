#include <stdio.h>

int main(void)
{
	int i, j, n, num;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (i = 1; ; ++i) {
		num = 0;
		for (j = 1; j <= i; ++j)
			if (i % j == 0)
				++num;
		if (num == n)
			break;
	}
	for (j = 1; j <= i; ++j)
		if (i % j == 0)
			printf("%d ", j);
	printf("%d\n", i);
	return 0;
}
