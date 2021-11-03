#include <stdio.h>
#include <string.h>

short dp[5009][5009];
char str[5009];

int min(int a, int b);

int main(void)
{
	int i, j, len;
	scanf("%*d%s", str);
	len = strlen(str) - 1;

	memset(dp, 0x7f, sizeof(dp));
	for (i = 0; i <= len; ++i) {
		dp[i][i] = 0;
		if (str[i] == str[i + 1])
			dp[i][i + 1] = 0;
	}

	for (i = len; i >= 0; --i) {
		for (j = i; j <= len; ++j) {
			if (str[i] == str[j] && j - 1 >= 0 && i + 1 <= len)
				dp[i][j] = min(dp[i + 1][j - 1], dp[i][j]);
			if (i + 1 <= j)
				dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j]);
			if (j - 1 >= 0)
				dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
		}
	}

	printf("%d\n", dp[0][len]);
	return 0;
}

int min(int a, int b)
{
	return a < b ? a : b;
}
