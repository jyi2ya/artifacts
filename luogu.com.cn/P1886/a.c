#include <stdio.h>

#define MAX 1000009

int a[MAX], max[MAX], min[MAX];
int que[MAX], l, r;

int main(void)
{
	int N, k, i;
	scanf("%d%d", &N, &k);
	for (i = 0; i < N; ++i) scanf("%d", a + i);

	l = 0; r = 0;
	for (i = 0; i <= N; ++i) {
		max[i] = a[que[l]];
		while (que[l] <= i - k && l < r) ++l;
		while (a[que[r - 1]] < a[i] && r > l) --r;
		que[r++] = i;
	}

	l = 0; r = 0;
	for (i = 0; i <= N; ++i) {
		min[i] = a[que[l]];
		while (que[l] <= i - k && l < r) ++l;
		while (a[que[r - 1]] > a[i] && r > l) --r;
		que[r++] = i;
	}

	for (i = k; i <= N; ++i) printf("%d ", min[i]);
	putchar('\n');
	for (i = k; i <= N; ++i) printf("%d ", max[i]);
	putchar('\n');

	return 0;
}
