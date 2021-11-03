#include <stdio.h>

#define MAX (3009)

int main(void)
{
	static int v[MAX][MAX];
	static int r[MAX][MAX];
	static int s[MAX];
	static long long d[MAX];
	long long a = 0;
	int i, j;
	int n, m;
	int t;

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i) {
		while  (getchar() != '\n');
		for (j = 1; j <= m; ++j)
			scanf("%d", &v[i][j]);
	}
	for (i = 1; i <= n; ++i)
		for (j = m; j >= 1; --j)
			r[i][j] = (v[i][j] == 0 ? 0 : r[i][j + 1] + 1);
	for (i = 1; i <= m; ++i) {
		t = 1;
		for (j = 1; j <= n; ++j) {
			while (t > 1 && r[s[t - 1]][i] >= r[j][i])
				--t;
			d[j] = d[s[t - 1]] + (j - s[t - 1]) * r[j][i];
			a += d[j];
			s[t++] = j;
		}
	}

	printf("%lld\n", a);
	return 0;
}
