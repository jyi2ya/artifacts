#include <stdio.h>
#include <limits.h>

int m, k;
int s[100009];

void read(void);
int check(int mid);

int main(void)
{
	int l = 0, r = INT_MAX;
	read();
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%d\n", l);
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
