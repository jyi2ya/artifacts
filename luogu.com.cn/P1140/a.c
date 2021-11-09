#include <stdio.h>
#include <ctype.h>

int a[109], b[109], n, m;
int dp[209][209];

const int diff[5][5] = {
	{5, -1, -2, -1, -3},
	{-1, 5, -3, -2, -4},
	{-2, -3, 5, -2, -2},
	{-1, -2, -2, 5, -1},
	{-3, -4, -2, -1, 0}
};

void read(void);
int max(int p, int q);

int main(void)
{
	int i, j;
	read();
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			dp[i][j] = -0x7f7f7f7f;

	for (i = n - 1; i >= 0; --i)
		dp[i][m] = dp[i + 1][m] + diff[a[i]][4];
	for (i = m - 1; i >= 0; --i)
		dp[n][i] = dp[n][i + 1] + diff[b[i]][4];

	for (i = n - 1; i >= 0; --i)
		for (j = m - 1; j >= 0; --j) {
			dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + diff[a[i]][b[j]]);
			dp[i][j] = max(dp[i][j], dp[i + 1][j] + diff[4][a[i]]);
			dp[i][j] = max(dp[i][j], dp[i][j + 1] + diff[4][b[j]]);
		}
	printf("%d\n", dp[0][0]);
	return 0;
}

void read(void)
{
	int ch, cur;
#ifdef DEBUG
	freopen("testdata.in", "r", stdin);
#endif
	scanf("%d", &n);
	while (!isalpha(ch = getchar()));
	cur = 0;
	do {
		switch (ch) {
			case 'A': a[cur++] = 0; break;
			case 'C': a[cur++] = 1; break;
			case 'G': a[cur++] = 2; break;
			case 'T': a[cur++] = 3; break;
			default: break;
		}
	} while (isalpha(ch = getchar()));

	scanf("%d", &m);
	while (!isalpha(ch = getchar()));
	cur = 0;
	do {
		switch (ch) {
			case 'A': b[cur++] = 0; break;
			case 'C': b[cur++] = 1; break;
			case 'G': b[cur++] = 2; break;
			case 'T': b[cur++] = 3; break;
			default: break;
		}
	} while (isalpha(ch = getchar()));
}

int max(int p, int q)
{
	return p > q ? p : q;
}
