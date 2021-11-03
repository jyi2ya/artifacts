#include <stdio.h>
#include <string.h>

#ifdef DEBUG
#define Z(x) printf x
#else
#define Z(x)
#endif

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int solve(void)
{
	int n, m;
	static int v[2009][2009];
	static int r[2009][2009];
	static int s[2009];
	static int u[2009], b[2009];
	int a = 0;
	int i, j;
	int t;

	if (scanf("%d%d", &n, &m) == EOF)
		return 1;
	memset(r, 0, sizeof(r));

	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
			scanf("%d", &v[i][j]);
	for (i = 1; i <= n; ++i)
		for (j = m; j >= 1; --j)
			r[i][j] = (v[i][j] == 0 ? 0 : r[i][j + 1] + 1);

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j)
			Z(("%d(%d) ", v[i][j], r[i][j]));
		Z(("\n"));
	}

	for (i = 1; i <= m; ++i) {
		memset(u, 0, sizeof(u));
		memset(b, 0, sizeof(b));
		t = 1;
		for (j = 1; j <= n; ++j) {
			while (t > 1 && r[j][i] <= r[s[t - 1]][i])
				--t;
			b[j] = (t == 1 ? 1 : s[t - 1] + 1);
			s[t++] = j;
		}
		t = 1;
		for (j = n; j >= 1; --j) {
			while (t > 1 && r[j][i] <= r[s[t - 1]][i])
				--t;
			u[j] = (t == 1 ? n : s[t - 1] - 1);
			s[t++] = j;
		}
		for (j = 1; j <= n; ++j)
			a = max(a, r[j][i] * (u[j] - b[j] + 1));
	}

	printf("%d\n", a);

	return 0;
}

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	while (solve() == 0);
	return 0;
}
