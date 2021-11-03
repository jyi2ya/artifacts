#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int n, m;
	register int i, j;
	static int v[5009][5009];
	static int t[5009];
	static int r[5009][5009];
	register int a = 0;

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
		register int c = 0;
		for (j = 1; j <= m; ++j)
			t[j] = 0;
		for (j = 1; j <= n; ++j)
			++t[r[j][i]];
		for (j = m; j >= 1; --j) {
			c += t[j];
			a = max(a, c * j);
		}
	}
	
	printf("%d\n", a);
	return 0;
}
