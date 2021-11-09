#include <stdio.h>
#include <string.h>

void next_perm(int *arr, int num);

int a[10009];

int main(void)
{
	int N, i, X;
	scanf("%d%d", &N, &X);
	for (i = 0; i < N; ++i)
		scanf("%d", a + i);
	while (X--)
		next_perm(a, N);
	for (i = 0; i < N; ++i)
		printf("%d ", a[i]);
	putchar('\n');
	return 0;
}


int vis[10009], ok;
int dfs(int pos, int *arr, int num)
{
	int i;
	if (pos == num) {
		if (ok)
			return 1;
		ok = 1;
		return 0;
	}

	for (i = arr[pos]; i <= num; ++i) {
		if (vis[i])
			continue;

		arr[pos] = i;
		vis[i] = 1;
		if (dfs(pos + 1, arr, num))
			return 1;
		vis[i] = 0;
	}
	arr[pos] = 1;
	return 0;
}

void next_perm(int *arr, int num)
{
	memset(vis, 0, sizeof(vis));
	ok = 0;
	dfs(0, arr, num);
}
