#include <stdio.h>
#include <limits.h>

int m, k;
int s[509];
int ans[509][2];

void read(void);
int check(int mid);

int main(void)
{
	int l = 0, r = INT_MAX, i, sum = 0, cnt;
	read();
	if (k == 0 && m == 0)
		return 0;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}

	cnt = 0;
	ans[cnt][1] = m;
	for (i = m; i >= 1; --i) {
		sum += s[i];
		if (sum > l) {
			ans[cnt][0] = i + 1;
			ans[++cnt][1] = i;
			sum = s[i];
		}
	}
	ans[cnt++][0] = 1;
	while (cnt < k) {
		ans[cnt][0] = 0;
		ans[cnt][1] = 0;
		++cnt;
	}
	while (--cnt >= 0)
		printf("%d %d\n", ans[cnt][0], ans[cnt][1]);
	return 0;
}

int check(int mid)
{
	int i, sum = 0, cnt = 1;
	for (i = m; i >= 1; --i) {
		if (mid < s[i])
			return 0;

		sum += s[i];
		if (sum > mid) {
			++cnt;
			sum = s[i];
		}
	}
	return cnt <= k;
}

void read(void)
{
	int i;
#ifdef DEBUG
	freopen("testdata.in", "r", stdin);
#endif
	scanf("%d%d", &m, &k);
	for (i = 1; i <= m; ++i)
		scanf("%d", s + i);
}
