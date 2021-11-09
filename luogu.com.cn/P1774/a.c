#include <stdio.h>

int a[500009];
int t[500009];

long long msort(int l, int r)
{
	int tt = l;
	long long ans;
	int m = l + (r - l) / 2;
	int i, j;

	if (r - l <= 1)
		return 0;

	ans = msort(l, m) + msort(m, r);

	for (i = l, j = m; i < m && j < r; ) {
		if (a[j] < a[i]) {
			ans += (long long)(m - i);
			t[tt++] = a[j++];
		} else {
			t[tt++] = a[i++];
		}
	}
	while (i < m)
		t[tt++] = a[i++];
	while (j < r)
		t[tt++] = a[j++];

	for (i = l; i < r; ++i)
		a[i] = t[i];

	return ans;
}

int main(void)
{
	int i;
	int n;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", a + i);

	printf("%lld\n", msort(0, n));
	return 0;
}
