#include <stdio.h>

int tm[109];

int main(void)
{
	int n, m;
	int i;
	int ans = 0;
	int ok = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d", &n, &m);

	while (!ok) {
		ok = 1;
		for (i = 0; i < m; ++i) {
			if (!tm[i] && n) {
				scanf("%d", tm + i);
				--n;
				--tm[i];
				ok = 0;
			} else if (tm[i] > 0) {
				--tm[i];
				ok = 0;
			}
		}
		++ans;
	}

	printf("%d\n", ans - 1);
	return 0;
}
