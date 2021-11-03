#include <stdio.h>
#include <limits.h>

int h[500009];
int n, m;

int qry(int x)
{
	int i;
	int ans = 0;
	for (i = 1; i <= n; ++i)
		if (h[i - 1] < x && x <= h[i])
			++ans;
	return ans;
}

void chg(int x, int y)
{
	h[x] = y;
}

int main(void)
{
	int i;
#ifndef LOCAL_TEST
	int last = 0;
#endif
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
		scanf("%d", &h[i]);
	h[0] = INT_MIN;
	while (m--) {
		char cmd[3];
		scanf("%s", cmd);
		if (cmd[0] == 'Q') {
			int x;
			int ans;
			scanf("%d", &x);
#ifndef LOCAL_TEST
			x ^= last;
#endif
			ans = qry(x);
			printf("%d\n", ans);
#ifndef LOCAL_TEST
			last = ans;
#endif
		} else {
			int x, y;
			scanf("%d%d", &x, &y);
#ifndef LOCAL_TEST
			x ^= last;
			y ^= last;
#endif
			chg(x, y);
		}
	}
	return 0;
}
