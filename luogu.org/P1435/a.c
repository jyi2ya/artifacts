#include <stdio.h>
#include <string.h>

int dp[1009][1009];
char buf[1009], rev[1009];

int max(int a, int b);

int main(void)
{
	int i, j, len;
	scanf("%s", buf + 1);
	len = strlen(buf + 1);
	for (i = 1; i <= len; ++i)
		rev[len - i + 1] = buf[i];
	rev[len + 1] = '\0';
	for (i = 1; i <= len; ++i)
		for (j = 1; j <= len; ++j) {
			if (buf[i] == rev[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	printf("%d\n", len - dp[len][len]);
	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
