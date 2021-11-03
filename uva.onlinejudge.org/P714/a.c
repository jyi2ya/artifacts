#include <stdio.h>
#include <string.h>
#include <limits.h>

int a[509], m, k, vis[509];

int isok(int max);

int main(void)
{
	int N;
	scanf("%d", &N);
	while (N--) {
		int i, l, r, now = 0, cnt;
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &m, &k);
		for (i = 0; i < m; ++i) scanf("%d", a + i);

		l = 0, r = INT_MAX;
		while (l < r) {
			int mid = l + (r - l) / 2;
			if (isok(mid)) r = mid;
			else l = mid + 1;
		}

		now = a[m - 1], cnt = 1;
		for (i = m - 2; i >= 0; --i) {
			now += a[i];
			if (now > l) {
				vis[i + 1] = 1;
				now = a[i];
				++cnt;
			}
		}
		for (i = 1; i < m; ++i)
			if (!vis[i] && cnt < k) {
				vis[i] = 1;
				++cnt;
			}
		for (i = 0; i < m; ++i) {
			if (vis[i]) printf(" /");
			if (i) putchar(' ');
			printf("%d", a[i]);
		}
		putchar('\n');
	}
	return 0;
}

int isok(int max)
{
	int cnt = 0, now = 0, i;
	for (i = m - 1; i >= 0; --i) {
		if (a[i] > max) return 0;
		now += a[i];
		if (now > max) {
			++cnt;
			now = a[i];
		}
	}
	return cnt < k;
}

