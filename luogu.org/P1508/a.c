#include <stdio.h>

int N, M;
int G[209][209], V[209][209], R[209][209];

int max(int a, int b);
int dfs(int y, int x);

int main(void)
{
	int i, j;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &N, &M);
	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j)
			scanf("%d", G[i] + j);

	printf("%d\n", max(
				max(
					dfs(N - 1, M / 2 - 1),
					dfs(N - 1, M / 2 + 1)
				   ), dfs(N - 1, M / 2)));

	return 0;
}

int dfs(int y, int x)
{
	int a;

	if (V[y][x])
		return R[y][x];
	if (y == 0)
		return R[y][x] = G[y][x];

	a = dfs(y - 1, x);
	if (x - 1 >= 0)
		a = max(a, dfs(y - 1, x - 1));
	if (x + 1 < M)
		a = max(a, dfs(y - 1, x + 1));

	V[y][x] = 1;
	return R[y][x] = a + G[y][x];
}

int max(int a, int b)
{
	return a > b ? a : b;
}
