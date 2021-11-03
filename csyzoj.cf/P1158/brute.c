#include <stdio.h>
#include <string.h>

int main(void)
{
	int n, m;
	int i, j;
	static int val[10009];
	static int cnt[10009];

#ifndef ONLINE_JUDGE
	freopen("card.in", "r", stdin);
#ifndef DEBUG
	freopen("card.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i) {
		scanf("%d", &val[i]);
		++cnt[val[i]];
	}

	while (m--) {
		int x, y;
		int ans = 0;
		static int mark[10009];

		scanf("%d%d", &x, &y);
		--cnt[val[x]];
		val[x] = y;
		++cnt[val[x]];

		memset(mark + 1, 0, sizeof(*mark) * n);

		for (i = n; i >= 1; --i)
			for (j = i - cnt[i] + 1; j <= i; ++j)
				if (j >= 1)
					mark[j] = 1;

		for (j = 1; j <= n; ++j)
			ans += !mark[j];

		printf("%d\n", ans);
	}

	return 0;
}
