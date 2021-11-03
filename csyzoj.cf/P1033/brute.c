#include <stdio.h>
#include <string.h>

int main(void)
{
	static int cnt[500009];
	static int val[500009];
	int i;
	int n, m;

	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
		scanf("%d", &val[i]);
	while (m--) {
		int l, r;
		int ok = -1;
		scanf("%d%d", &l, &r);
		memset(cnt, 0, sizeof(cnt));
		for (i = l; i <= r; ++i)
			++cnt[val[i]];
		for (i = 0; i < n; ++i)
			if (cnt[i] * 2 > r - l + 1) {
				ok = i;
				break;
			}
		if (ok >= 0)
			printf("%d\n", ok);
		else
			puts("-1");
	}
	return 0;
}
