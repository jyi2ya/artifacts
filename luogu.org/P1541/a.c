#include <stdio.h>

int S[309], N, M, C[5];
int V[41][41][41][41];

int max(int x1, int x2, int x3, int x4);

int main(void)
{
	int i, x, i1, i2, i3, i4;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; ++i)
		scanf("%d", S + i);
	for (i = 0; i < M; ++i) {
		scanf("%d", &x);
		++C[x];
	}

	for (i1 = 0; i1 <= C[1]; ++i1)
		for (i2 = 0; i2 <= C[2]; ++i2)
			for (i3 = 0; i3 <= C[3]; ++i3)
				for (i4 = 0; i4 <= C[4]; ++i4)
					V[i1][i2][i3][i4] = max(
							((i1 - 1 >= 0) ?
							(V[i1 - 1][i2][i3][i4]) :
							(0)),
							(((i2 - 1 >= 0)) ?
							(V[i1][i2 - 1][i3][i4]) :
							(0)),
							((i3 - 1 >= 0) ?
							(V[i1][i2][i3 - 1][i4]) :
							(0)),
							((i4 - 1 >= 0) ?
							(V[i1][i2][i3][i4 - 1]) :
							(0))) + S[i1 + i2 * 2 + i3 * 3 + i4 * 4 + 1];

	printf("%d\n", V[C[1]][C[2]][C[3]][C[4]]);
	return 0;
}

int max(int x1, int x2, int x3, int x4)
{
	x1 = (x2 > x1) ? (x2) : (x1);
	x1 = (x3 > x1) ? (x3) : (x1);
	x1 = (x4 > x1) ? (x4) : (x1);
	return x1;
}
