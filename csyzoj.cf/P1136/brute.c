#include <stdio.h>

int main(void)
{
	int n;
	struct {
		int att;
		int act;
	} val[209];
	int ans = 0;
	int i;
	unsigned int mask;

#define PROG "debate"
#ifndef ONLINE_JUDGE 
	freopen(PROG ".in", "r", stdin);
#ifndef DEBUG
	freopen(PROG ".out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d%d", &val[i].att, &val[i].act);

	for (mask = 0; mask < (1U << n); ++mask) {
		int lans = 0;
		int cnt1 = 0;
		int cnt2 = 0;
		int num = 0;
		for (i = 0; i < n; ++i)
			if (mask >> i & 1) {
				lans += val[i].act;
				switch (val[i].att) {
					case 00: break;
					case 01: ++cnt2; break;
					case 10: ++cnt1; break;
					case 11: ++cnt1; ++cnt2; break;
				}
				++num;
			}
		if (cnt2 * 2 < num || cnt1 * 2 < num)
			lans = -0x3f3f3f3f;
		if (lans > ans)
			ans = lans;
	}

	printf("%d\n", ans);

	return 0;
}
