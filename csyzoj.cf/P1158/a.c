#include <stdio.h>
#include <string.h>

int main(void)
{
	int n, m;
	int i;
	int ans;
	static int val[1000009];
	static int cnt[1000009];
	static int mark[1000009];

#ifndef ONLINE_JUDGE
	freopen("card.in", "r", stdin);
#ifndef DEBUG
	freopen("card.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	scanf("%d%d", &n, &m);
	ans = n;
	for (i = 1; i <= n; ++i) {
		scanf("%d", &val[i]);
		++cnt[val[i]];
		if (val[i] - cnt[val[i]] + 1 >= 1) {
			if (!mark[val[i] - cnt[val[i]] + 1])
				--ans;
			++mark[val[i] - cnt[val[i]] + 1];
		}
	}

	while (m--) {
		int x, y;

		scanf("%d%d", &x, &y);
		if (val[x] - cnt[val[x]] + 1 >= 1) {
			--mark[val[x] - cnt[val[x]] + 1];
			if (!mark[val[x] - cnt[val[x]] + 1])
				++ans;
		}
		--cnt[val[x]];
		val[x] = y;
		++cnt[val[x]];
		if (val[x] - cnt[val[x]] + 1 >= 1) {
			if (!mark[val[x] - cnt[val[x]] + 1])
				--ans;
			++mark[val[x] - cnt[val[x]] + 1];
		}

		printf("%d\n", ans);
	}

	return 0;
}
