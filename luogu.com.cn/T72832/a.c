#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int a[1000009];

int cmp(const void *a, const void *b);

int main(void)
{
	int n, i, c;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; ++i) {
			a[i] = 0;
			while (!isdigit(c = getchar()));
			do {
				a[i] = a[i] * 10 + c - '0';
			} while (isdigit(c = getchar()));
		}
		qsort(a, n - 1, sizeof(int), cmp);
		n -= 4;
		for (i = 0; i < n; i += 4) {
			printf("%d ", a[i]);
			printf("%d ", a[i + 1]);
			printf("%d ", a[i + 2]);
			printf("%d ", a[i + 3]);
		}
		n += 4;
		for (; i < n; ++i)
			printf("%d ", a[i]);
		putchar('\n');
	}

	return 0;
}

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
