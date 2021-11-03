#include <stdio.h>
#include <string.h>

int N, A, B;
int k[209];
int vis[209][209];

int dfs(int pos, int depth);

int main(void)
{
	int i;
	scanf("%d%d%d", &N, &A, &B);
	memset(vis, -1, sizeof(vis));
	for (i = 1; i <= N; ++i)
		scanf("%d", k + i);
	for (i = 1; i <= N; ++i)
		if (dfs(A, i))
			break;
	if (i > N)
		i = -1;
	if (A == B)
		i = 0;
	printf("%d\n", i);
}

int dfs(int pos, int depth)
{
	int ans = 0;
	if (vis[pos][depth] >= 0)
		return vis[pos][depth];

	if (depth == 0)
		return pos == B;

	if (pos + k[pos] <= N)
		ans |= dfs(pos + k[pos], depth - 1);

	if (pos - k[pos] >= 1)
		ans |= dfs(pos - k[pos], depth - 1);

	return vis[pos][depth] = ans;
}
