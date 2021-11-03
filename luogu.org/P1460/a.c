/*
ID:lindong6
PROG:holstein
LANG:C
*/

#include <stdio.h>
#include <string.h>

void read(void);

int need[100], V;
int contain[100][100], G;

int use[30], amount[30], used = 0;

int ans[30], ansused = 0x7fffffff;

int dfs(int pos);

int main(void)
{
	register int i;

	read();
	dfs(0);

	printf("%d", ansused);
	for (i = 0; i < G; ++i)
		if (ans[i])
			printf(" %d", i + 1);
	putchar('\n');

	return 0;
}

#define fls() fflush(stdout);
int check(void)
{
	register int i;
	for (i = 0; i < V; ++i)
		if (amount[i] < need[i])
			return 0;
	return 1;
}

int depth;
int dfs(int pos)
{
	int i;

	if (pos == G) {
		if (check() && used < ansused) {
			ansused = used;
			memcpy(ans, use, sizeof(use));
		}
		return 0;
	}

	use[pos] = 1;
	++used;
	for (i = 0; i < V; ++i)
		amount[i] += contain[pos][i];
	dfs(pos + 1);
	for (i = 0; i < V; ++i)
		amount[i] -= contain[pos][i];
	--used;
	use[pos] = 0;

	dfs(pos + 1);

	return 0;
}

void read(void)
{
	register int i, j;

	scanf("%d", &V);
	for (i = 0; i < V; ++i)
		scanf("%d", need + i);
	scanf("%d", &G);
	for (i = 0; i < G; ++i)
		for (j = 0; j < V; ++j)
			scanf("%d", contain[i] + j);
}
