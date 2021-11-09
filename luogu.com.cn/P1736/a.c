#include <stdio.h>

int G[2509][2509], N, M, L[2509][2509], C[2509][2509], D[2509][2509];

int min(int a, int b);

int main(void)
{
	int i, j, a = 0;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &N, &M);
	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j)
			scanf("%d", G[i] + j);
	for (i = 0; i <= N; ++i)
		for (j = 0; j <= M; ++j) {
			L[i][j] =
				((G[i][j] == 0) ?
				 (((j == 0) ?
				   (0) :
				   (L[i][j - 1])) + 1) :
				 (0));
			C[i][j] =
				((G[i][j] == 0) ?
				 (((i == 0) ?
				   (0) :
				   (C[i - 1][j])) + 1) :
				 (0));
		}
	for (i = 0; i <= N; ++i)
		for (j = 0; j <= M; ++j)
			D[i][j] = 
				((i && j) ?
				 ((G[i][j]) ?
				  (min(min(C[i - 1][j], L[i][j - 1]), D[i - 1][j - 1]) + 1) :
				  (0)) :
				 (G[i][j]));

	for (i = 0; i <= N; ++i)
		for (j = 0; j <= M; ++j)
			if (D[i][j] > a)
				a = D[i][j];

	for (i = 0; i <= N; ++i)
		for (j = M; j >= 0; --j) {
			L[i][j] =
				((G[i][j] == 0) ?
				 (((j == 0) ?
				   (0) :
				   (L[i][j + 1])) + 1) :
				 (0));
			C[i][j] =
				((G[i][j] == 0) ?
				 (((i == 0) ?
				   (0) :
				   (C[i - 1][j])) + 1) :
				 (0));
		}
	for (i = 0; i <= N; ++i)
		for (j = M; j >= 0; --j)
			D[i][j] = 
				((i && j) ?
				 ((G[i][j]) ?
				  (min(min(C[i - 1][j], L[i][j + 1]), D[i - 1][j + 1]) + 1) :
				  (0)) :
				 (G[i][j]));

	for (i = 0; i <= N; ++i)
		for (j = M; j >= 0; --j)
			if (D[i][j] > a)
				a = D[i][j];

	printf("%d\n", a);
	return 0;
}

int min(int a, int b)
{
	return a < b ? a : b;
}
