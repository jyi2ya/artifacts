#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N,p[11], px[11], py[11], gx, gy;

void print_board(void);
int die(void);

int main(void)
{
	while (scanf("%d%d%d", &N, &gy, &gx) == 3 && (N || gx || gy)) {
		int i;
		for (i = 0; i < N; ++i) {
			char buf[3];
			int x, y;
			scanf("%s%d%d", buf, &y, &x);
			p[i] = buf[0];
			px[i] = x;
			py[i] = y;
		}
		if (die()) puts("YES");
		else puts("NO");
		/* print_board(); */
	}
	return 0;
}

char board[11][11];

void build_board(void)
{
	int i;
	memset(board, '.', sizeof(board));
	for (i = 0; i < N; ++i) board[py[i]][px[i]] = p[i];
	board[gy][gx] = 'g';
}

/* G {{{ */
int kill_G(int y, int x)
{
	int i, cnt = 0;
	for (i = y - 1; i > 0; --i) {
		if (board[i][x] != '.') {
			if (board[i][x] != '.') {
				if (board[i][x] == 'g' && cnt == 0) return 1;
				else ++cnt;
			}
		}
	}
	return 0;
}
/* }}} */
/* R {{{ */
int kill_R(int y, int x)
{
	int i, cnt;

	cnt = 0;
	for (i = y - 1; i > 0; --i) {
		if (board[i][x] != '.') {
			if (board[i][x] != '.') {
				if (board[i][x] == 'g' && cnt == 0) return 1;
				else ++cnt;
			}
		}
	}

	cnt = 0;
	for (i = y + 1; i <= 10; ++i) {
		if (board[i][x] != '.') {
			if (board[i][x] != '.') {
				if (board[i][x] == 'g' && cnt == 0) return 1;
				else ++cnt;
			}
		}
	}

	cnt = 0;
	for (i = x - 1; i > 0; --i) {
		if (board[y][i] != '.') {
			if (board[y][i] != '.') {
				if (board[y][i] == 'g' && cnt == 0) return 1;
				else ++cnt;
			}
		}
	}

	cnt = 0;
	for (i = x + 1; i <= 9; ++i) {
		if (board[y][i] != '.') {
			if (board[y][i] != '.') {
				if (board[y][i] == 'g' && cnt == 0) return 1;
				else ++cnt;
			}
		}
	}

	return 0;
}
/* }}} */
/* C {{{ */
int kill_C(int y, int x)
{
	int i, cnt;

	cnt = 0;
	for (i = y - 1; i > 0; --i) {
		if (board[i][x] != '.') {
			if (board[i][x] != '.') {
				if (board[i][x] == 'g' && cnt == 1) return 1;
				else ++cnt;
			}
		}
	}

	cnt = 0;
	for (i = y + 1; i <= 10; ++i) {
		if (board[i][x] != '.') {
			if (board[i][x] != '.') {
				if (board[i][x] == 'g' && cnt == 1) return 1;
				else ++cnt;
			}
		}
	}

	cnt = 0;
	for (i = x - 1; i > 0; --i) {
		if (board[y][i] != '.') {
			if (board[y][i] != '.') {
				if (board[y][i] == 'g' && cnt == 1) return 1;
				else ++cnt;
			}
		}
	}

	cnt = 0;
	for (i = x + 1; i <= 9; ++i) {
		if (board[y][i] != '.') {
			if (board[y][i] != '.') {
				if (board[y][i] == 'g' && cnt == 1) return 1;
				else ++cnt;
			}
		}
	}

	return 0;
}
/* }}} */
/* H {{{ */
#define chk() \
	do { \
		if (1 <= y && y <= 10 && 1 <= x && x <= 9) { \
			if (board[y][x] == 'g') return 1; \
		} \
	} while(0)

int kill_H(int y, int x)
{

	if (board[y + 1][x] == '.') {
		y += 2, x -= 1; chk(); y -= 2, x += 1;
		y += 2, x += 1; chk(); y -= 2, x -= 1;
	}
	if (board[y - 1][x] == '.') {
		y -= 2, x -= 1; chk(); y += 2, x += 1;
		y -= 2, x += 1; chk(); y += 2, x -= 1;
	}
	if (board[y][x + 1] == '.') {
		y += 1, x += 2; chk(); y -= 1, x -= 2;
		y -= 1, x += 2; chk(); y += 1, x -= 2;
	}
	if (board[y][x - 1] == '.') {
		y += 1, x -= 2; chk(); y -= 1, x += 2;
		y -= 1, x -= 2; chk(); y += 1, x += 2;
	}
	return 0;
}
/* }}} */

int isok(void)
{
	int i, j;
	if (gx > 6 || gx < 4 || gy < 1 || gy > 3) return 0;
	build_board();
	for (i = 1; i <= 10; ++i) {
		for (j = 1; j <= 9; ++j) {
			switch(board[i][j]) {
				case 'G': { if (kill_G(i, j)) return 0; break; }
				case 'R': { if (kill_R(i, j)) return 0; break; }
				case 'C': { if (kill_C(i, j)) return 0; break; }
				case 'H': { if (kill_H(i, j)) return 0; break; }
				default: break;
			}
		}
	}
	return 1;
}

int die(void)
{
	++gy; if (isok()) return 0; --gy;
	--gy; if (isok()) return 0; ++gy;
	--gx; if (isok()) return 0; ++gx;
	++gx; if (isok()) return 0; --gx;
	return 1;
}

void print_board(void)
{
	int i, j;
	puts("#####################################");
	putchar('+');
	for (i = 0; i < 9; ++i) putchar('-');
	putchar('+');
	putchar('\n');
	for (i = 1; i <= 5; ++i) {
		putchar('|');
		for (j = 1; j <= 9; ++j) {
			if (i <= 3 && j <= 6 && j >= 4 && board[i][j] == '.') {
				putchar('x');
			} else {
				putchar(board[i][j]);
			}
		}
		putchar('|');
		putchar('\n');
	}
	putchar('|');
	for (j = 0; j < 9; ++j) putchar('=');
	putchar('|');
	putchar('\n');
	for (i = 6; i <= 10; ++i) {
		putchar('|');
		for (j = 1; j <= 9; ++j) {
			if (i >= 8 && j <= 6 && j >= 4 && board[i][j] == '.') {
				putchar('x');
			} else {
				putchar(board[i][j]);
			}
		}
		putchar('|');
		putchar('\n');
	}
	putchar('+');
	for (i = 0; i < 9; ++i) putchar('-');
	putchar('+');
	putchar('\n');
}
