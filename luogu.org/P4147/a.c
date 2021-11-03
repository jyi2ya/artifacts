#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int n, m;
	int i, j;
	static char val[1009][1009];
	static int right[1009][1009];
	static int stt[1009];
	static int len[1009];
	int top = 0;
	int ans = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
			scanf("%s", &val[i][j]);

	for (i = 1; i <= n; ++i) {
		right[i][m] = (val[i][m] == 'F' ? 1 : 0);
		for (j = m - 1; j >= 1; --j)
			right[i][j] = (val[i][j] == 'F' ? 
					right[i][j + 1] + 1 : 0);
	}

	for (i = 1; i <= m; ++i) {
		top = 0;
		stt[top] = 1;
		len[top] = right[1][i];
		++top;
		for (j = 2; j <= n; ++j) {
			int st = j;
			while (top > 0 && len[top - 1] > right[j][i]) {
				--top;
				ans = max(ans, len[top] * (j - stt[top]));
				st = stt[top];
			}
			stt[top] = st;
			len[top] = right[j][i];
			++top;
		}
		while (top > 0) {
			--top;
			ans = max(ans, len[top] * (j - stt[top]));
		}
	}

	printf("%d\n", 3 * ans);

	return 0;
}
