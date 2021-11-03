#include <stdio.h>
#include <string.h>

char str1[2009], str2[2009];

int dp[2009][2009];
int min(int a, int b);

int main(void)
{
	int i, j, len1, len2;
#ifdef DEBUG
	freopen("testdata.in", "r", stdin);
#endif
	scanf("%s%s", str1, str2);
	len1 = strlen(str1);
	len2 = strlen(str2);

	memset(dp, 0x7f, sizeof(dp));

	dp[0][len2] = len1;
	for (i = 1; i <= len1; ++i)
		dp[i][len2] = dp[i - 1][len2] - 1;

	dp[len1][0] = len2;
	for (i = 1; i <= len2; ++i)
		dp[len1][i] = dp[len1][i - 1] - 1;

	for (i = len1 - 1; i >= 0; --i)
		for (j = len2 - 1; j >= 0; --j) {
			dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j]);
			dp[i][j] = min(dp[i][j + 1] + 1, dp[i][j]);
			if (str1[i] == str2[j])
				dp[i][j] = min(dp[i + 1][j + 1], dp[i][j]);
			else
				dp[i][j] = min(dp[i + 1][j + 1] + 1, dp[i][j]);
		}
	printf("%d\n", dp[0][0]);
	return 0;
}

int min(int a, int b)
{
	return a < b ? a : b;
}
