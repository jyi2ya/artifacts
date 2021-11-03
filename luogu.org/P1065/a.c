#include <stdio.h>

int main(void)
{
	static int ord[1000009];
	static int cost[1009][1009];
	static int use[1009][1009];
	static int sch[1009][1009];
	static int cnt[10009];
	static int last[10009];
	int m, n;
	int i, j, k;
	int ans = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d", &m, &n);
	for (i = 1; i <= n * m; ++i)
		scanf("%d", &ord[i]);
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
			scanf("%d", &use[i][j]);
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
			scanf("%d", &cost[i][j]);
	for (i = 1; i <= n * m; ++i) {
		int mac;
		int len;
		++cnt[ord[i]];
		mac = use[ord[i]][cnt[ord[i]]];
		len = cost[ord[i]][cnt[ord[i]]];
		for (j = last[ord[i]]; ; ++j) {
			for (k = j; k < j + len && !sch[mac][k]; ++k)
				;
			if (k == j + len) {
				for (k = j; k < j + len; ++k)
					sch[mac][k] = ord[i];
				if (j + len > ans)
					ans = j + len;
				last[ord[i]] = k;
				break;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
