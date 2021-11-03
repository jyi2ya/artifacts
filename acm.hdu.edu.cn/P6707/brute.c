#include <stdio.h>
#include <string.h>

int val[100009];

int main(void)
{
	int n, m;
	int i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i)
		scanf("%d", &val[i]);
	while (m--) {
		int x;
		scanf("%d", &x);
		for (i = 0; i < n; ++i)
			if (val[i] == x)
				break;
		memmove(val + 1, val, sizeof(int) * i);
		val[0] = x;
	}
	for (i = 0; i < n; ++i)
		printf("%d ", val[i]);
	putchar('\n');
	return 0;
}
