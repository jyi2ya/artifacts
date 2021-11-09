/*
ID:lindong6
PROG:milk3
LANG:C
*/

#include <stdio.h>

int A, B, C;
int ans[109], vis[30][30][30];

void read(void);
void dfs(int a,int b, int c);
int max(int a, int b);
int min(int a, int b);

#ifdef DEBUG
#define dbgout printf
#else
void dbgout(const char *fuck, ...) { };
#endif

int main(void)
{
	register int i;
	int first = 1;

	read();
	dfs(0, 0, C);
	for (i = 0; i < 109; ++i) {
		if (ans[i]) {
			if (first)
				first = 0;
			else
				putchar(' ');

			printf("%d", i);
		}
	}
	putchar('\n');

	return 0;
}

void dfs(int a, int b, int c)
{
	dbgout("a = %d, b = %d, c = %d\n", a, b, c );

	if (vis[a][b][c])
		return;
	vis[a][b][c] = 1;

	if (a == 0)
		ans[c] = 1;
	/* pour a to b */
	dfs(max(a - (B - b), 0), min(b + a, B), c);
	/* pour b to a */
	dfs(min(a + b, A), max(b - (A - a), 0), c);
	/* pour b to c */
	dfs(a, max(b - (C - c), 0), min(b + c, C));
	/* pour c to b */
	dfs(a, min(c + b, B), max(c - (B - b), 0));
	/* pour a to c */
	dfs(max(a - (C - c), 0), b, min(a + c, C));
	/* pour c to a */
	dfs(min(c + a, A), b, max(c - (A - a), 0));
}

void read(void)
{
	scanf("%d%d%d", &A, &B, &C);
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}
