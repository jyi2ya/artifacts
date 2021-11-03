#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a > *(int *)b ? -1 : 1;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int n, m;
	int i, j;
	static int v[5009][5009];
	static int t[5009];
	static int r[5009][5009];
	int a = 0;

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i) {
		while (getchar() != '\n');
		for (j = 1; j <= m; ++j)
			v[i][j] = getchar() - '0';
	}

	for (i = 1; i <= n; ++i)
		for (j = m; j >= 1; --j)
			r[i][j] = (v[i][j] == 0 ? 0 : r[i][j + 1] + 1);

	for (i = 1; i <= m; ++i) {
		for (j = 1; j <= n; ++j)
			t[j] = r[j][i];
		qsort(t + 1, n, sizeof(int), cmp);
		for (j = 1; j <= n; ++j)
			a = max(a, t[j] * j);
	}

	printf("%d\n", a);
	return 0;
}
