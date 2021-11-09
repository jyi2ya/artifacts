#include <stdio.h>
#include <string.h>

char buffer[2048][2048];
int height[109][109], m, n;

void putcube(int y, int x);
void putbuffer(int h, int w);

int main(void)
{
	int i, j, k, h = 0, w = 0;
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			scanf("%d", height[i] + j);
	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			if ((m - i - 1) * 2 + height[i][j] * 3 + 3 > h)
				h = (m - i - 1) * 2 + height[i][j] * 3 + 3;
	w = m * 2 + n * 4 + 1;
	memset(buffer, '.', sizeof(buffer));

	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
			for (k = 1; k <= height[i][j]; ++k)
				putcube(
						h - ((m - i - 1) * 2 + k * 3 + 3),
						(m - i - 1) * 2 + j * 4 + 2
				       );
	putbuffer(h, w);
	return 0;
}

void fill(int y, int x, const char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; ++i)
		buffer[y][x + i] = str[i];
}

void putcube(int y, int x)
{
	fill(y, x,           "+---+");
	fill(y + 1, x - 1,  "/   /|");
	fill(y + 2, x - 2, "+---+ |");
	fill(y + 3, x - 2, "|   | +");
	fill(y + 4, x - 2, "|   |/");
	fill(y + 5, x - 2, "+---+");
}

void putbuffer(int h, int w)
{
	int i, j;
	for (i = 0; i < h; ++i) {
		for (j = 0; j < w; ++j)
			putchar(buffer[i][j]);
		putchar('\n');
	}
}
