#include <stdio.h>

struct {
	int fir, las;
	int siz;
	int val;
} N[1000009];

struct {
	int dst, dis;
} E[2000009];

int n, m;

int max(int a, int b)
{
	return a > b ? a : b;
}

int dp[3009][3009];

void dfs(int rt)
{
	int i, j, k;
	if (rt > n - m) {
		N[rt].siz = 1;
		dp[rt][1] = N[rt].val;
		return ;
	}

	for (i = N[rt].fir; i < N[rt].las; ++i) {
		dfs(E[i].dst);
		N[rt].siz += N[E[i].dst].siz;
		for (j = m; j >= 1; --j)
			for (k = 0; k <= N[E[i].dst].siz && k <= j; ++k)
				dp[rt][j] = max(dp[rt][j], dp[rt][j - k] +
						dp[E[i].dst][k] - E[i].dis);
	}
}

int main(void)
{
	int i, j;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n - m; ++i) {
		int c;
		scanf("%d", &c);
		N[i].fir = N[i - 1].las;
		N[i].las = N[i].fir + c;
		for (j = N[i].fir; j < N[i].las; ++j)
			scanf("%d%d", &E[j].dst, &E[j].dis);
	}

	for (i = n - m + 1; i <= n; ++i)
		scanf("%d", &N[i].val);

	for (i = 0; i <= n; ++i)
		for (j = 0; j <= m; ++j)
			dp[i][j] = -0x3f3f3f3f;

	for (i = 0; i <= n; ++i)
		dp[i][0] = 0;

	dfs(1);

	for (i = m; i >= 0; --i)
		if (dp[1][i] >= 0)
			break;

	printf("%d\n", i);
	return 0;
}
