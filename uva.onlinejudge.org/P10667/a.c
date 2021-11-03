#include <stdio.h>
#include <string.h>

#ifdef DEBUG
#define Z(x) printf x
#else
#define Z(x)
#endif

int v[2009][2009];
int n;

int max(int a, int b)
{
	return a > b ? a : b;
}

int solve(void)
{
	int m = n;
	static int r[2009][2009];
	static int s[2009];
	static int u[2009], b[2009];
	int a = 0;
	int i, j;
	int t;

	memset(r, 0, sizeof(r));

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
	int T;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &T);
	while (T--) {
		int s;
		int i, j;
		scanf("%d%d", &n, &s);
		for (i = 1; i <= n; ++i)
			for (j = 1; j <= n; ++j)
				v[i][j] = 1;
		while (s--) {
			int r1, c1, r2, c2;
			scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
			for (i = r1; i <= r2; ++i)
				for (j = c1; j <= c2; ++j)
					v[i][j] = 0;
		}
		solve();
	}
	return 0;
}
