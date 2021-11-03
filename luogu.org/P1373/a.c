#include <stdio.h>

#define MOD 1000000007

int f[809][809][20][2];
int val[809][809];

int main(void)
{
	int N, M, K;
	int i, j, k;
	int ans = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d%d", &N, &M, &K);
	++K;
	for (i = 1; i <= N; ++i)
		for (j = 1; j <= M; ++j)
			scanf("%d", &val[i][j]);
	for (i = 1; i <= N; ++i)
		for (j = 1; j <= M; ++j)
			f[i][j][val[i][j]][0] = 1;
	for (i = 1; i <= N; ++i)
		for (j = 1; j <= M; ++j)
			for (k = 0; k < K; ++k) {
				f[i][j][k][1] +=
					f[i - 1][j][(k + val[i][j] + K) % K][0];
				f[i][j][k][1] %= MOD;
				f[i][j][k][1] +=
					f[i][j - 1][(k + val[i][j] + K) % K][0];
				f[i][j][k][1] %= MOD;
				f[i][j][k][0] +=
					f[i - 1][j][(k - val[i][j] + K) % K][1];
				f[i][j][k][0] %= MOD;
				f[i][j][k][0] +=
					f[i][j - 1][(k - val[i][j] + K) % K][1];
				f[i][j][k][0] %= MOD;
			}
	for (i = 1; i <= N; ++i)
		for (j = 1; j <= M; ++j)
			ans = (ans + f[i][j][0][1]) % MOD;
	printf("%d\n", ans);
	return 0;
}
