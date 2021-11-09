#include <stdio.h>

long long a[39], n;
long long vis[39][39];
int vm[39][39];

long long max(long long a, long long b);
long long dfs(int l, int r);
void dfsans(int l, int r);

int main(void)
{
	int i;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%lld", &n);
	for (i = 1; i <= n; ++i)
		scanf("%lld", a + i);
	printf("%lld\n", dfs(1, n));
	dfsans(1, n);
	return 0;
}

void dfsans(int l, int r)
{
	if (l < 1 || r > n || l > r)
		return;
	if (l == r) {
		printf("%d ", l);
		return;
	}
	printf("%d ", vm[l][r]);
	dfsans(l, vm[l][r] - 1);
	dfsans(vm[l][r] + 1, r);
}

long long dfs(int l, int r)
{
	int m, ta;
	long long ans = 0;
	if (l < 1 || r > n || l > r)
		return 1;
	if (l == r)
		return a[l];
	if (vm[l][r])
		return vis[l][r];
	for (m = l; m <= r; ++m) {
		ta = dfs(l, m - 1) * dfs(m + 1, r) + a[m];
		if (ta > ans) {
			ans = ta;
			vm[l][r] = m;
		}
	}
	return vis[l][r] = ans;
}

long long max(long long a, long long b)
{
	return a > b ? a : b;
}
