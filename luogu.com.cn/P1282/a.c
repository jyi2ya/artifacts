#include <stdio.h>
#include <string.h>

#define INF 0x7f7f7f7f

#define MAGIC 6003
char V[MAGIC * 2][1009];
int M[MAGIC * 2][1009];

int gans;

int N, A[1009], B[1009];

int min(int a, int b);
int abs(int a);
int dfs(int d, int p);
int dfs1(int d, int p);

int main(void)
{
	int i, u = 0, b = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &N);

	for (i = 0; i < N; ++i) {
		scanf("%d%d", A + i, B + i);
		u += A[i];
		b += B[i];
	}

	gans = dfs(u - b, 0);
	memset(V, 0, sizeof(V));
	i = dfs1(u - b, 0);
	printf("%d\n", i);
	return 0;
}

int dfs1(int d, int p)
{
	if (p == N)
		return (abs(d) == gans) ? 0 : INF;

	if (!V[d + MAGIC][p]) {
		V[d + MAGIC][p] = 1;
		M[d + MAGIC][p] = min(
				dfs1(d - 2 * (A[p] - B[p]), p + 1) + 1,
				dfs1(d, p + 1)
				);
	}

	return M[d + MAGIC][p];
}

int dfs(int d, int p)
{
	if (p == N)
		return abs(d);

	if (!V[d + MAGIC][p]) {
		V[d + MAGIC][p] = 1;
		M[d + MAGIC][p] = min(
				dfs(d - 2 * (A[p] - B[p]), p + 1),
				dfs(d, p + 1)
				);
	}

	return M[d + MAGIC][p];
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int abs(int a)
{
	return a > 0 ? a : -a;
}
