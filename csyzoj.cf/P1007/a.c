#include <stdio.h>
#include <limits.h>
#include <string.h>

int h[1000009];
int n, m;

long long s[1000009];
long long s0 = 0;

long long s_qry(int x)
{
	long long ans = 0;
	for (; x; x -= (x & -x))
		ans += s[x];
	return ans;
}

void s_add(int l, int r, long long ad)
{
	for (; l <= 1000000; l += (l & -l))
		s[l] += ad;
	for (++r; r <= 1000000; r += (r & -r))
		s[r] -= ad;
}

long long qry(int x)
{
	return s_qry(x);
}

void bld(void)
{
	int i;
	memset(s, 0, sizeof(s));
	for (i = 1; i <= n; ++i)
		if (h[i - 1] < h[i])
			s_add(h[i - 1] + 1, h[i], 1);
}

void chg(int x, int y)
{
	if (h[x - 1] < h[x])
		s_add(h[x - 1] + 1, h[x], -1);
	if (x < n && h[x] < h[x + 1])
		s_add(h[x] + 1, h[x + 1], -1);
	h[x] = y;
	if (h[x - 1] < h[x])
		s_add(h[x - 1] + 1, h[x], 1);
	if (x < n && h[x] < h[x + 1])
		s_add(h[x] + 1, h[x + 1], 1);
}

int main(void)
{
	int i;
#ifndef DEBUG
	long long last = 0;
#endif
#ifdef DEBUG
#define LOCAL_TEST
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
		scanf("%d", &h[i]);
	h[n + 1] = 1000000;
	bld();
	while (m--) {
		char cmd[3];
		scanf("%s", cmd);
		if (cmd[0] == 'Q') {
			int x;
			long long ans;
			scanf("%d", &x);
#ifndef LOCAL_TEST
			x ^= last;
#endif
			ans = qry(x);
			printf("%lld\n", ans);
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
