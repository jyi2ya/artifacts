/*
ID:lindong6
PROG:castle
LANG:C
*/

#include <stdio.h>
#include <string.h>

#define MAX 500
char map[MAX][MAX];
int size[MAX][MAX];
int number[MAX][MAX];
int N, M;

void read(void);
void prtmap(int i, int j);

void fillall(void);
int get_size(void);
int get_number(void);
int broke_wall(void);

int main(void)
{
	read();
	fillall();
	printf("%d\n", get_number());
	printf("%d\n", get_size());
	broke_wall();
	return 0;
}

int number_cnt, sz;

void fill_size(int x, int y)
{
	size[x][y] = sz;
	if (map[x + 1][y] == ' ' && !size[x + 1][y])
		fill_size(x + 1, y);
	if (map[x - 1][y] == ' ' && !size[x - 1][y])
		fill_size(x - 1, y);
	if (map[x][y + 1] == ' ' && !size[x][y + 1])
		fill_size(x, y + 1);
	if (map[x][y - 1] == ' ' && !size[x][y - 1])
		fill_size(x, y - 1);
}

int dfs_size(int x, int y)
{
	int ans = 0;

	if ((x - 1) % 3 == 0 && (y - 1) % 3 == 0)
		++ans;

	number[x][y] = number_cnt;
	if (map[x + 1][y] == ' ' && !number[x + 1][y])
		ans += dfs_size(x + 1, y);
	if (map[x - 1][y] == ' ' && !number[x - 1][y])
		ans += dfs_size(x - 1, y);
	if (map[x][y + 1] == ' ' && !number[x][y + 1])
		ans += dfs_size(x, y + 1);
	if (map[x][y - 1] == ' ' && !number[x][y - 1])
		ans += dfs_size(x, y - 1);

	return ans;
}

void fillall(void)
{
	register int i, j;
	number_cnt = 1;
	for (i = 1; i <= N * 3; ++i)
		for (j = 1; j <= M * 3; ++j)
			if (map[i][j] == ' ' && !number[i][j]) {
				sz = dfs_size(i, j);
				fill_size(i, j);
				++number_cnt;
			}
}

int get_size(void)
{
	register int i, j;
	int ans = 0;
	for (i = 1; i <= N * 3; ++i)
		for (j = 1; j <= M * 3; ++j)
			if (size[i][j] > ans)
				ans = size[i][j];
	return ans;
}

int get_number(void)
{
	register int i, j;
	int ans = 0;
	for (i = 1; i <= N * 3; ++i)
		for (j = 1; j <= M * 3; ++j)
			if (number[i][j] > ans)
				ans = number[i][j];
	return ans;
}

void prtmap(int x, int y)
{
	int i, j;
	puts("map");
	for (i = 0; i <= N * 3; ++i) {
		for (j = 0; j <= M * 3; ++j) {
			if (i == x && j == y)
				printf("X ");
			else
				printf("%c ", map[i][j]);
		}
		putchar('\n');
	}
	puts("number");
	for (i = 0; i <= N * 3; ++i) {
		for (j = 0; j <= M * 3; ++j)
			printf("%d ", number[i][j]);
		putchar('\n');
	}
	puts("size");
	for (i = 0; i <= N * 3; ++i) {
		for (j = 0; j <= M * 3; ++j)
			printf("%d ", size[i][j]);
		putchar('\n');
	}
}

void read(void)
{
	register int i, j;

	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);

	memset(map, '#', sizeof(map));

	scanf("%d%d", &M, &N);

	for (i = 1; i <= N * 3; i += 3)
		for (j = 1; j <= M * 3; j += 3) {
			int n;
			scanf("%d", &n);

			map[i][j - 1] = ' ';
			map[i - 1][j] = ' ';
			map[i][j + 1] = ' ';
			map[i + 1][j] = ' ';
			map[i][j] = ' ';

			if (n & 1)
				map[i][j - 1] = '#';
			n /= 2;
			if (n & 1)
				map[i - 1][j] = '#';
			n /= 2;
			if (n & 1)
				map[i][j + 1] = '#';
			n /= 2;
			if (n & 1)
				map[i + 1][j] = '#';
		}
}

int broke_wall(void)
{
	register int i, j;
	int ans = 0, x = 0x66ccff, y = 0x66ccff, direct = 'L';
	int bac1, bac2, new_size;
	for (j = 1; j <= M * 3; ++j)
		for (i = N * 3; i >= 1; --i)
			if (
					(i - 1) % 3 == 0 && 
					(j - 1) % 3 == 0 &&
					map[i][j] == ' '
			   ) {
				/* north */
				if (i >= 2) {
					bac1= map[i - 1][j];
					bac2 = map[i - 2][j];
					map[i - 1][j] = ' ';
					map[i - 2][j] = ' ';
					memset(number, 0, sizeof(number));
					new_size = dfs_size(i, j);
					if (new_size > ans) {
						ans = new_size;
						x = i, y = j;
						direct = 'N';
					}
					map[i - 1][j] = bac1;
					map[i - 2][j] = bac2;
				}
			}
	for (j = 1; j <= M * 3; ++j)
		for (i = N * 3; i >= 1; --i)
			if (
					(i - 1) % 3 == 0 && 
					(j - 1) % 3 == 0 &&
					map[i][j] == ' '
			   ) {
				/* east */
				bac1 = map[i][j + 1];
				bac2 = map[i][j + 2];
				map[i][j + 1] = ' ';
				map[i][j + 2] = ' ';
				memset(number, 0, sizeof(number));
				new_size = dfs_size(i, j);
				if (new_size > ans) {
					ans = new_size;
					x = i, y = j;
					direct = 'E';
				} else if (new_size == ans) {
					if (j < y) {
						ans = new_size;
						x = i, y = j;
						direct = 'E';
					}
				}
				map[i][j + 1] = bac1;
				map[i][j + 2] = bac2;
			}
	printf("%d\n%d %d %c\n", ans, (x - 1) / 3 + 1, (y - 1) / 3 + 1, (char)direct);
	return 0;
}
