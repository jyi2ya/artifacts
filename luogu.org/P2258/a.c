#include <stdio.h>
#include <string.h>

#define INF 0x3f7f7f7f

int abs(int x)
{
	return x > 0 ? x : -x;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int count(unsigned int x)
{
	int a = 0;
	while (x) {
		++a;
		x -= (x & -x);
	}
	return a;
}

int N, M, R, C;
int G[20][20], T[20][20], F[20][20][20], chose[20];

int cost(int old, int a)
{
	int i, s = 0;
	if (old == -1)
		old = a;
	for (i = 0; i < R; ++i)
		s += abs(T[i][old] - T[i][a]);
	for (i = 1; i < R; ++i)
		s += abs(T[i][a] - T[i - 1][a]);
	/*
	puts("=== ===");
	for (i = 0; i < R; ++i)
		printf("%d %d\n", T[i][old], T[i][a]);
	printf("%d\n", s);
	*/
	return s;
}

int memorize_dfs(int p, int c, int l)
{
	int la;
	if (l >= 0 && F[p][c][l] >= 0) {
		la = F[p][c][l];
	} else if (c == C) {
		la = 0;
	} else if (p == M) {
		la = INF;
	} else {
		la = min(memorize_dfs(p + 1, c + 1, p) + cost(l, p),
				memorize_dfs(p + 1, c, l));
	}
	if (l >= 0)
		F[p][c][l] = la;
	return la;
}

int solve(void)
{
	int i, j, k;
	k = 0;
	for (i = 0; i < N; ++i)
		if (chose[i]) {
			for (j = 0; j < M; ++j)
				T[k][j] = G[i][j];
			++k;
		}
	memset(F, -1, sizeof(F));
	return memorize_dfs(0, 0, -1);
}

int dfs_choose(int p, int c)
{
	int la = INF;
	if (p == N)
		return (c == R) ? (solve()) : (INF);

	la = min(la, dfs_choose(p + 1, c));
	chose[p] = 1;
	la = min(la, dfs_choose(p + 1, c + 1));
	chose[p] = 0;

	return la;
}

int main(void)
{
	int i, j;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d%d%d", &N, &M, &R, &C);
	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j)
			scanf("%d", G[i] + j);

	printf("%d\n", dfs_choose(0, 0));
	return 0;
}
