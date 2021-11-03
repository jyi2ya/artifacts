#include <stdio.h>
#include <string.h>

int cnt[3009];
int solve(void)
{
	int n, m, k;
	int i;
	memset(cnt, 0, sizeof(cnt));
	scanf("%d%d%d", &n, &m, &k);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		++cnt[u];
		++cnt[v];
	}
	for (i = 1; i <= n; ++i)
		if (cnt[i] < k) {
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
