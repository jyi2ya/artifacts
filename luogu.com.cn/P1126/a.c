#include <stdio.h>
#include <ctype.h>

int N, M, sy, sx, ey, ex, init_d;
int puz[59][59];
int vis[2509][59][59][26];

void read(void);
int iddfs(int y, int x, int dir, int depth);
void print_maz(void);

int main(void)
{
	int depth;
	read();
	for (depth = 0; depth < N * M; ++depth)
		if (iddfs(sy, sx, init_d, depth))
			break;
	if (depth < N * M)
		printf("%d\n", depth);
	else
		puts("-1");
	return 0;
}

void get_delta(int *y, int *x, int dir)
{
	if (dir == 'S') {
		*x = 0;
		*y = 1;
	} else if (dir == 'E') {
		*x = 1;
		*y = 0;
	} else if (dir == 'W') {
		*x = -1;
		*y = 0;
	} else if (dir == 'N') {
		*x = 0;
		*y = -1;
	}
}

int iddfs(int y, int x, int dir, int depth)
{
	int ans = 0, dx, dy, i;

	if (depth == 0) {
		if (y == ey && x == ex)
			return 1;
		else
			return 0;
	}

	if (y > N || x > M || y < 1 || x < 1)
		return 0;
	if (y + 1 > N || x + 1 > M)
		return 0;
	if (puz[y][x] || puz[y + 1][x] || puz[y + 1][x + 1] || puz[y][x + 1])
		return 0;

	if (vis[depth][y][x][dir - 'A'])
		return 0;
	vis[depth][y][x][dir - 'A'] = 1;

	if (dir != 'N')
		ans |= iddfs(y, x, 'S', depth - 1);
	if (dir != 'S')
		ans |= iddfs(y, x, 'N', depth - 1);
	if (dir != 'E')
		ans |= iddfs(y, x, 'W', depth - 1);
	if (dir != 'W')
		ans |= iddfs(y, x, 'E', depth - 1);

	get_delta(&dy, &dx, dir);

	for (i = 1; i <= 3; ++i) {
		y += dy, x += dx;
		if (puz[y][x] || puz[y + 1][x] ||
				puz[y + 1][x + 1] || puz[y][x + 1])
			break;
		else
			ans |= iddfs(y, x, dir, depth - 1);
	}
	return ans;
}

void read(void)
{
	int i, j;
	scanf("%d%d", &N, &M);
	for (i = 1; i <= N; ++i)
		for (j = 1; j <= M; ++j)
			scanf("%d", puz[i] + j);
	scanf("%d%d%d%d", &sy, &sx, &ey, &ex);
	while (!isalpha(init_d = getchar()));
}

void print_maz(void)
{
	int i, j;
	for (i = 1; i <= N; ++i) {
		for (j = 1; j <= M; ++j) {
			if ((i == ey && j == ex) ||
					(i == ey + 1 && j == ex) ||
					(i == ey + 1 && j == ex + 1) ||
					(i == ey && j == ex + 1))
				printf("E ");
			else if ((i == sy && j == sx) ||
					(i == sy + 1 && j == sx) ||
					(i == sy + 1 && j == sx + 1) ||
					(i == sy && j == sx + 1))
				printf("S ");
			else
				printf("%d ", puz[i][j]);
		}
		putchar('\n');
	}
}
