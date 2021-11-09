#include <stdio.h>

#define MAX 2000009

int que[MAX], a[MAX], l = 0, r = 0;

int main(void)
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i) scanf("%d", a+i);
	for (i = 0; i < n; ++i) {
		if (l == r) puts("0");
		else printf("%d\n", a[que[l]]);

		while (que[l] <= i - m && l < r) ++l;
		while (a[que[r - 1]] > a[i] && r > l) --r;
		que[r++] = i;
	}
	return 0;
}
