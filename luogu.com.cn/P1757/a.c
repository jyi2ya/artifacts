#include <stdio.h>

#define GROUP_MAX (109)
#define N_MAX (1009)
#define M_MAX (1009)

struct item {
	int w;
	int v;
};

struct item group[GROUP_MAX][N_MAX];
int top[GROUP_MAX];

int dp[GROUP_MAX][M_MAX];

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int n, m;
	int i, j, k;

	scanf("%d%d", &m, &n);
	for (i = 0; i < n; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		group[c][top[c]].w = a;
		group[c][top[c]].v = b;
		++top[c];
	}

	for (i = 0; i < GROUP_MAX; ++i)
		for (j = 0; j <= m; ++j) {
			dp[i][j] = dp[i - 1][j];
			for (k = 0; k < top[i]; ++k)
				if (j >= group[i][k].w)
					dp[i][j] = max(dp[i][j], 
						dp[i - 1][j - group[i][k].w] +
						group[i][k].v);
		}
	printf("%d\n", dp[GROUP_MAX - 1][m]);
	return 0;
}
