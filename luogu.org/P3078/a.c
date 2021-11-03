#include <stdio.h>

int main(void)
{
	long long ans = 0;
	int n, last = 0;
	scanf("%d", &n);
	while (n--) {
		long long x;
		scanf("%lld", &x);
		if (last < x)
			ans += x - last;
		last = x;
	}
	printf("%lld\n", ans);
	return 0;
}

/* T L E

long long solve(int l, int r, long long last);

long long seq[100009];

int main(void)
{
	int n, i;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf("%lld", seq + i);
	printf("%lld\n", solve(1, n, 0));
	return 0;
}

long long solve(int l, int r, long long last)
{
	long long ans = 0, min = 0x7f7f7f7f7f7f7f7f;
	int i, j;
	for (i = l; i <= r; ++i)
		if (seq[i] < min)
			min = seq[i];
	ans += min - last;
	for (i = l; i <= r && seq[i] == min; ++i);
	while (i <= r) {
		for (j = i + 1; j <= r && seq[j] != min; ++j);
		--j;
		ans += solve(i, j, min);
		for (i = j + 1; i <= r && seq[i] == min; ++i);
	}
	return ans;
}
*/
