#include <stdio.h>

int squ(int x)
{
	return x * x;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int main(void)
{
	int n, m;
	int i, j;
	static int val[2009][2009];
	static int right[2009][2009];
	static int stt[2009];
	static int len[2009];
	int top = 0;
	int ans1 = 1, ans2 = 1;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
			scanf("%d", &val[i][j]);
	for (i = 1; i <= n; ++i) {
		right[i][m] = 1;
		for (j = m - 1; j >= 1; --j)
			right[i][j] = (val[i][j] != val[i][j + 1] ?
					right[i][j + 1] + 1 : 1);
	}

	/*
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j)
			printf("%d ", right[i][j]);
		putchar('\n');
	}
	*/

	for (i = 1; i <= m; ++i) {
		top = 0;
		stt[0] = 1;
		len[0] = right[1][i];
		++top;
		ans1 = max(ans1, right[1][i]);
		ans2 = max(ans2, 1);
		for (j = 2; j <= n; ++j) {
			if (val[j][i] == val[j - 1][i]) {
				while (top > 0) {
					--top;
					ans1 = max(ans1, (j - stt[top]) *
							len[top]);
					ans2 = max(ans2, squ(min(j - stt[top],
							len[top])));
				}
				stt[0] = j;
				len[0] = right[j][i];
				++top;
			} else {
				int st = j;
				while (top > 0 && right[j][i] < len[top - 1]) {
					--top;
					ans1 = max(ans1, (j - stt[top]) *
							len[top]);
					ans2 = max(ans2, squ(min(j - stt[top],
							len[top])));
					st = stt[top];
				}
				stt[top] = st;
				len[top] = right[j][i];
				++top;
			}
		}
		while (top > 0) {
			--top;
			ans1 = max(ans1, (j - stt[top]) *
					len[top]);
			ans2 = max(ans2, squ(min(j - stt[top],
							len[top])));
		}
	}

	printf("%d\n%d\n", ans2, ans1);
	return 0;
}
