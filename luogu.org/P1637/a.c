#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[30009];
int mp[30009];
int n;

int map(int x)
{
	int l = 1, r = n + 1, m;
	while (l < r) {
		m = l + (r - l) / 2;
		if (mp[m] < x)
			l = m + 1;
		else
			r = m;
	}
	return l;
}

int map_cmp(const void *i1, const void *i2)
{
	return *(int*)i1 < *(int*)i2 ? -1 : 1;
}

void add(int *o, int p, int k, int d)
{
	for (; p <= n && p; p += d * (p & -p))
		o[p] += k;
}

int query(int *o, int p, int d)
{
	int ans = 0;
	for (; p <= n && p; p += d * (p & -p))
		ans += o[p];
	return ans;
}

int L[30009], R[30009];
int FL[30009], FR[30009];

int main(void)
{
	int i;
	long long ans = 0;
	long long cl, cr;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		scanf("%d", a + i);

	memcpy(mp, a, sizeof(mp));
	qsort(mp + 1, n, sizeof(int), map_cmp);
	
	for (i = 1; i <= n; ++i) {
		add(FL, map(a[i]), 1, 1);
		L[i] = query(FL, map(a[i]) - 1, -1) - query(FL, 0, -1);
	}

	for (i = n; i >= 1; --i) {
		add(FR, map(a[i]), 1, -1);
		R[i] = query(FR, map(a[i]) + 1, 1), - query(FR, 0, 1);
	}

	for (i = 1; i <= n; ++i) {
		cl = L[i], cr = R[i];
		ans += cl * cr;
	}

	printf("%lld\n", ans);
	return 0;
}
