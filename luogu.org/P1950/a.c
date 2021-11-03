#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, j;
	static int r[1009][1009];
	static int v[1009][1009];
	static int stk[1009];
	static int mt[1009];
	int top = 0;
	long long ans = 0;
	int n, m;

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i) {
		while (getchar() != '\n');
		for (j = 1; j <= m; ++j)
			v[i][j] = getchar();
	}

	for (i = 1; i <= n; ++i)
		for (j = m; j >= 1; --j)
			r[i][j] = (v[i][j] == '*' ? 0 : r[i][j + 1] + 1);

	for (i = 1; i <= m; ++i) {
		top = 1;
		for (j = 1; j <= n; ++j) {
			while (top > 1 && r[stk[top - 1]][i] >= r[j][i])
				--top;
			mt[j] = mt[stk[top - 1]] + (j - stk[top - 1]) * r[j][i];
			ans += mt[j];
			stk[top++] = j;
		}
	}

	printf("%lld\n", ans);

	return 0;
}
