#include <stdio.h>

int main(void)
{
	static int col[2000009];
	static int cost[2000009];
	static int cnt[2000009];
	int last = 0;
	int n, p;
	int i, j;
	int ans = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%*d%d", &n, &p);
	for (i = 1; i <= n; ++i)
		scanf("%d%d", &col[i], &cost[i]);
	for (i = 1; i <= n; ++i) {
		if (cost[i] <= p) {
			for (j = last + 1; j < i; ++j)
				++cnt[col[j]];
			ans += cnt[col[i]];
			++cnt[col[i]];
			last = i;
		} else {
			ans += cnt[col[i]];
		}
	}
	printf("%d\n", ans);
	return 0;
}
