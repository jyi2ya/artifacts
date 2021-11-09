#include <stdio.h>
#include <string.h>

#define printgraph(G) \
	do { \
		int rgi, rgj; \
		puts("==== GRP ===="); \
		for (rgi = 0; rgi < N; ++rgi) { \
			for (rgj = 0; rgj < M; ++rgj) \
				putchar(G[rgi][rgj] ? G[rgi][rgj] : ' '); \
			putchar('\n'); \
		} \
	} while (0)

#define readgraph() \
	do { \
		int rgi, rgj; \
		if (scanf("%d%d", &N, &M) != 2) { \
			EXIT = 1; \
			break; \
		} \
		for (rgi = 0; rgi < N; ++rgi) { \
			while (getchar() != '\n'); \
			for (rgj = 0; rgj < M; ++rgj) \
				G[rgi][rgj] = getchar(); \
		} \
	} while (0)

#define test_do(cond, code) if (cond) code
#define magic(x, N) (((x) % (N) + (N)) % (N))

#define MAXLEVEL 2

int N, M, YES;
char G[1509][1509];
int V[1509][1509], Ay[1509][1509], Ax[1509][1509];

void dfs(int y, int x)
{
	int iy = magic(y, N), ix = magic(x, M);

	if (V[iy][ix]) {
		if (Ay[iy][ix] != y || Ax[iy][ix] != x)
			YES = 1;
		return;
	}

	V[iy][ix] = 1, Ay[iy][ix] = y, Ax[iy][ix] = x;

	test_do(G[magic(y - 1, N)][ix] != '#', dfs(y - 1, x));
	test_do(G[magic(y + 1, N)][ix] != '#', dfs(y + 1, x));
	test_do(G[iy][magic(x - 1, M)] != '#', dfs(y, x - 1));
	test_do(G[iy][magic(x + 1, M)] != '#', dfs(y, x + 1));
}

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	for (; ;) {
		int i, j, sx, sy, EXIT = 0;

		readgraph();
		if (EXIT)
			break;

		for (i = 0; i < N; ++i)
			for (j = 0; j < M; ++j)
				if (G[i][j] == 'S')
					sy = i, sx = j;

		memset(V, 0, sizeof(V));
		YES = 0;
		dfs(sy, sx);

		if (YES)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
