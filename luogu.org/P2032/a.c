#include <stdio.h>

#define MAX 2000009

int que[MAX],a[MAX];

int main(void)
{
	int n, k, i, l, r;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; ++i) scanf("%d", a + i);

	l = 0; r = 0;
	for (i = 0; i <= n; ++i) {
		if (i >= k) printf("%d\n", a[que[l]]);
		while (que[l] <= i - k && l < r) ++l;
		while (a[que[r - 1]] < a[i] && r > l) --r;
		que[r++] = i;
	}
	return 0;
}
