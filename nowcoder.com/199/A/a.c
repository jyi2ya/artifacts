#include <stdio.h>

#define MAX 100009

int know[MAX][3], num[MAX], n, m, ans[MAX];

void init(void);
void merge(int x, int y);
int find(int x);

void read(void);

int main(void)
{
	int i, j;
	read();
	init();
	for (i = 1; i <= n; ++i)
		for (j = 0; j < num[i]; ++j) {
			if (find(know[i][j]) == find(
		}
	return 0;
}	

void read(void)
{
	int i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		know[a][num[a]++] = b;
		know[b][num[b]++] = a;
	}
}

int fa[MAX];

void init(void)
{
	int i;
	for (i = 1; i <= n; ++i) fa[i] = i;
}
void merge(int x, int y)
{
	fa[find(x)] = find(y);
}
int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
