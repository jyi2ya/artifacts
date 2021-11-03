#include <stdio.h>
#include <string.h>

/* readint {{{ */
#include <ctype.h>
int readint(int *ans)
{
	int ch, lt0 = 0;
	*ans = 0;
	while (!isdigit(ch = getchar()) && ch != '-' && ch != EOF);
	if (ch == EOF) return 0;
	else if (ch == '-') lt0 = 1;
	else *ans = ch - '0';

	while (isdigit(ch = getchar())) *ans = *ans * 10 + ch - '0';
	if (lt0) *ans = -*ans;
	return 1;
}
/* }}} */
/* newline {{{ */
void newline(void)
{
	int ch;
	while ((ch = getchar()) == '\r' || ch == '\n');
	ungetc(ch, stdin);
}
/* }}} */

void print_board(void);
void print_all_moves(void);
void try_to_put(int y, int x);
void count_piece(void);

char board[11][11];
int nowprocess, x, y;

int main(void)
{
	int T, first = 1;
	readint(&T);
	newline();
	while (T--) {
		int i, j;
		char cmd[16];
		if (first) first = 0; else putchar('\n');

		memset(board, '-', sizeof(board));
		for (i = 1; i <= 8; ++i) {
			for (j = 1; j <= 8; ++j) board[i][j] = getchar();
			newline();
		}
		scanf("%s", cmd);
		nowprocess = cmd[0];

		while (scanf("%s", cmd) == 1 && cmd[0] != 'Q') {
			if (cmd[0] == 'L') print_all_moves();
			else {
				try_to_put(cmd[1] - '0', cmd[2] - '0');
				count_piece();
			}
		}

		print_board();

		newline();
	}
	return 0;
}

/* check {{{ */
int check_with_direct(int y, int x, int deltay, int deltax)
{
	int i, j, cnt = 0;
	for (
			i = y + deltay, j = x + deltax;
			0 <= i && i <= 9 && 0 <= j && j <= 9;
			i += deltay, j += deltax
	    ) {
		if (board[i][j] == '-') return 0;
		if (board[i][j] == nowprocess) break;
		++cnt;
	}
	if (cnt) return 1;
	return 0;
}

int check(int y, int x)
{
	int ans = 0;
	if (board[y][x] != '-') return 0;
	ans |= check_with_direct(y, x, -1, -1); /* left & up */
	ans |= check_with_direct(y, x, -1, 0);  /* up */
	ans |= check_with_direct(y, x, -1, 1);  /* right & up */
	ans |= check_with_direct(y, x, 0, -1);  /* left */
	ans |= check_with_direct(y, x, 0, 1);   /* right */
	ans |= check_with_direct(y, x, 1, -1);  /* left & down */
	ans |= check_with_direct(y, x, 1, 0);   /* down */
	ans |= check_with_direct(y, x, 1, 1);   /* right & down */
	return ans;
}
/* }}} */
/* fill {{{ */
void fill_with_direct(int y, int x, int deltay, int deltax)
{
	int i, j;
	for (
			i = y + deltay, j = x + deltax;
			0 <= i && i <= 9 && 0 <= j && j <= 9;
			i += deltay, j += deltax
	    ) {
		if (board[i][j] == '-') return ;
		if (board[i][j] == nowprocess) break;
	}
	for (
			i -= deltay, j -= deltax;
			board[i][j] != nowprocess;
			i -= deltay, j -= deltax
	    ) board[i][j] = nowprocess;
}

void fill(int y, int x)
{
	fill_with_direct(y, x, -1, -1); /* left & up */
	fill_with_direct(y, x, -1, 0);  /* up */
	fill_with_direct(y, x, -1, 1);  /* right & up */
	fill_with_direct(y, x, 0, -1);  /* left */
	fill_with_direct(y, x, 0, 1);   /* right */
	fill_with_direct(y, x, 1, -1);  /* left & down */
	fill_with_direct(y, x, 1, 0);   /* down */
	fill_with_direct(y, x, 1, 1);   /* right & down */
}
/* }}} */

void count_piece(void)
{
	int i, j, w = 0, b = 0;
	for (i = 1; i <= 8; ++i)
		for (j = 1; j <= 8; ++j) {
			if (board[i][j] == 'W') ++w;
			if (board[i][j] == 'B') ++b;
		}
	printf("Black - %2d White - %2d\n", b, w);
}

void try_to_put(int y, int x)
{
	if (!check(y, x)) nowprocess = (nowprocess == 'W') ? 'B' : 'W';
	board[y][x] = nowprocess;
	fill(y, x);
	nowprocess = (nowprocess == 'W') ? 'B' : 'W';
}

void print_all_moves(void)
{
	int i, j, cnt = 0;
	for (i = 1; i <= 8; ++i)
		for (j = 1; j <= 8; ++j) {
			if (check(i, j)) {
				if (cnt) putchar(' ');
				printf("(%d,%d)", i, j);
				++cnt;
			}
		}
	if (cnt) putchar('\n');
	else puts("No legal move.");
}

void print_board(void)
{
	int i, j;
	for (i = 1; i <= 8; ++i) {
		for (j = 1; j <= 8; ++j) putchar(board[i][j]);
		putchar('\n');
	}
}
