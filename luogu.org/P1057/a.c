#include <stdio.h>
#include <string.h>

int dfs(int res, int pos);
int n, m;
int vis[39][38];

int main(void)
{
	memset(vis, -1, sizeof(vis));
	scanf("%d%d", &n, &m);
	printf("%d\n", dfs(m, 0));
	return 0;
}

int dfs(int res, int last)
{
	int ans = 0;
	if (res == 1) {
		if ((last - 1 + n) % n == 0 || (last + 1) % n == 0)
			return 1;
		else
			return 0;
	}

	if (vis[res][last] >= 0)
		return vis[res][last];

	ans += dfs(res - 1, (last - 1 + n) % n);
	ans += dfs(res - 1, (last + 1) % n);

	return vis[res][last] = ans;
}
