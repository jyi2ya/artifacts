#include <stdio.h>
#include <string.h>

long long tot, N;

long long dfs(long long pos, long long sum);
long long vis[2009][49];

int main(void)
{
	scanf("%lld", &N);
	memset(vis, -1, sizeof(vis));
	tot = N * (N + 1) / 2;
	printf("%lld\n", dfs(1, 0) / 2);
	return 0;
}

long long dfs(long long pos, long long sum)
{
	if (vis[sum][pos] >= 0)
		return vis[sum][pos];
	if (pos > N)
		return vis[sum][pos] = ((sum * 2) == tot);
	return vis[sum][pos] = dfs(pos + 1, sum) + dfs(pos + 1, sum + pos);
}
