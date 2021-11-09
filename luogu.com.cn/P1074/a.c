#include <stdio.h>
#include <stdlib.h>

#define INF 0x5566ccff

int sudoku[10][10], useline[10][10], usecol[10][10], useblock[10][10];
typedef struct line {
	int n, i;
} line;
line nxt[10];
int gans;

int max(int a, int b);
int col_id(int y, int x);
int line_id(int y, int x);
int score_lev(int y, int x);
int block_id(int y, int x);

int dfs(int y, int x, int ans);
int cmp(const void *a, const void *b);

int main(void)
{
	int i, j, scr = 0;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	for (i = 0; i < 9; ++i)
		for (j = 0; j < 9; ++j)
			scanf("%d", sudoku[i] + j);
	for (i = 0; i < 9; ++i) {
		nxt[i].i = i, nxt[i].n = 0;
		for (j = 0; j < 9; ++j)
			nxt[i].n += (!sudoku[i][j]);
	}
	qsort(nxt, 9, sizeof(line), cmp);

	for (i = 0; i < 9; ++i)
		for (j = 0; j < 9; ++j) {
			useline[line_id(nxt[i].i, j)][sudoku[nxt[i].i][j]] = 1;
			usecol[col_id(nxt[i].i, j)][sudoku[nxt[i].i][j]] = 1;
			useblock[block_id(nxt[i].i, j)][sudoku[nxt[i].i][j]] = 1;
		}

	scr = dfs(0, 0, 0);
	scr = (scr < 0 ? -1 : scr);
	printf("%d\n", scr);
	return 0;
}

int max_ans(int y, int x)
{
	int i, j, k, a = 0;
	for (i = y; i <= 8; ++i)
		for (j = (i == y ? x : 0); j <= 8; ++j) {
			if (sudoku[nxt[i].i][j]) {
				k = sudoku[nxt[i].i][j];
			} else {
				for (k = 9; k >= 1; --k)
					if (
							!useline[line_id(nxt[i].i, j)][k] &&
							!usecol[col_id(nxt[i].i, j)][k] &&
							!useblock[block_id(nxt[i].i, j)][k]
					   )
						break;
			}

			if (!k)
				return -INF;

			a += score_lev(nxt[i].i, j) * k;
		}

	return k;
}

int dfs(int y, int x, int ans)
{
	int i, lans = -INF;

	/*
	if (ans + max_ans(y, x) <= gans)
		return -INF;
		*/

	if (y == 9)
		return ans;
	if (x == 9)
		return dfs(y + 1, 0, ans);
	if (sudoku[nxt[y].i][x]) {
		if (x == 9)
			return dfs(y + 1, 0, ans + score_lev(nxt[y].i, x) * sudoku[nxt[y].i][x]);
		else
			return dfs(y, x + 1, ans + score_lev(nxt[y].i, x) * sudoku[nxt[y].i][x]);
	}

	for (i = 1; i <= 9; ++i)
		if (
				!useline[line_id(nxt[y].i, x)][i] &&
				!usecol[col_id(nxt[y].i, x)][i] &&
				!useblock[block_id(nxt[y].i, x)][i]
		   ) {
			useline[line_id(nxt[y].i, x)][i] = 1;
			usecol[col_id(nxt[y].i, x)][i] = 1;
			useblock[block_id(nxt[y].i, x)][i] = 1;
			lans = max(lans, dfs(y, x + 1, ans + score_lev(nxt[y].i, x) * i));
			useline[line_id(nxt[y].i, x)][i] = 0;
			usecol[col_id(nxt[y].i, x)][i] = 0;
			useblock[block_id(nxt[y].i, x)][i] = 0;
		}

	return lans;
}

/*
int inrange(int x, int l, int r)
{
	return l <= x && x <= r;
}
*/
#define inrange(x, l, r) ((l) <= (x) && (x) <= (r))

int score_lev(int y, int x)
{
	if (inrange(x, 4, 4) && inrange(y, 4, 4))
		return 10;
	if (inrange(x, 3, 5) && inrange(y, 3, 5))
		return 9;
	if (inrange(x, 2, 6) && inrange(y, 2, 6))
		return 8;
	if (inrange(x, 1, 7) && inrange(y, 1, 7))
		return 7;
	return 6;
}

int block_id(int y, int x)
{
	if (inrange(x, 0, 2) && inrange(y, 0, 2))
		return 0;
	if (inrange(x, 3, 5) && inrange(y, 0, 2))
		return 1;
	if (inrange(x, 6, 8) && inrange(y, 0, 2))
		return 2;
	if (inrange(x, 0, 2) && inrange(y, 3, 5))
		return 3;
	if (inrange(x, 3, 5) && inrange(y, 3, 5))
		return 4;
	if (inrange(x, 6, 8) && inrange(y, 3, 5))
		return 5;
	if (inrange(x, 0, 2) && inrange(y, 6, 8))
		return 6;
	if (inrange(x, 3, 5) && inrange(y, 6, 8))
		return 7;
	return 8;
}

int col_id(int y, int x)
{
	return x;
}

int line_id(int y, int x)
{
	return y;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int cmp(const void *a, const void *b)
{
	return ((line*)a)->n - ((line*)b)->n;
}
