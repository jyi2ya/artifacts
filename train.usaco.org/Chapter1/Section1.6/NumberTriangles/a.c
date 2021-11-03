/*
ID:lindong6
PROG:numtri
LANG:C
*/

#include <stdio.h>

int R;
int dp[1009][1009];
int tri[1009][1009];

void read(void);
int max(int a, int b);

int main(void)
{
	register int i, j;
	int ans = 0;

	read();
	dp[1][1] = tri[1][1];
	for (i = 2; i <= R; ++i)
		for (j = 1; j <= i; ++j)
			dp[i][j] = 
				max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
	for (i = 0; i <= R; ++i)
		ans = max(ans, dp[R][i]);
	printf("%d\n", ans);
	return 0;
}

void read(void)
{
	register int i, j;

	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);

	scanf("%d", &R);
	for (i = 1; i <= R; ++i)
		for (j = 1; j <= i; ++j)
			scanf("%d", tri[i] + j);
}

int max(int a, int b)
{
	return a > b ? a : b;
}
