#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long ll;

struct coord {
	ll x, y;
};

struct coord pos[100009];
ll sorted_x[100009], prefix_x[100009];
ll sorted_y[100009], prefix_y[100009];

int cmp(const void *p, const void *q)
{
	return *(ll*)p < *(ll*)q ? -1 : 1;
}

int lb(ll *arr, ll x, int n)
{
	int l = 1, r = n + 1, m;
	while (l < r) {
		m = l + (r - l) / 2;
		if (x <= arr[m])
			r = m;
		else
			l = m + 1;
	}
	return l;
}

int main_(void)
{
	int n;
	int i;
	ll ans = LLONG_MAX;

	scanf("%d", &n);
	for (i = 1; i <= n; ++i) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		pos[i].x = (x + y);
		pos[i].y = (x - y);
	}

	for (i = 1; i <= n; ++i) {
		sorted_x[i] = pos[i].x;
		sorted_y[i] = pos[i].y;
	}

	qsort(sorted_x + 1, n, sizeof(sorted_x[0]), cmp);
	qsort(sorted_y + 1, n, sizeof(sorted_y[0]), cmp);

	for (i = 1; i <= n; ++i)
		prefix_x[i] = prefix_x[i - 1] + sorted_x[i];
	for (i = 1; i <= n; ++i)
		prefix_y[i] = prefix_y[i - 1] + sorted_y[i];

	for (i = 1; i <= n; ++i) {
		ll lans = 0;
		ll x = pos[i].x, y = pos[i].y;
		ll mid;

		mid = lb(sorted_x, x, n);
		lans += (mid - 1) * x - prefix_x[mid - 1];
		lans += prefix_x[n] - prefix_x[mid - 1] - (n - mid + 1) * x;

		mid = lb(sorted_y, y, n);
		lans += (mid - 1) * y - prefix_y[mid - 1];
		lans += prefix_y[n] - prefix_y[mid - 1] - (n - mid + 1) * y;

		if (lans < ans)
			ans = lans;
	}

	printf("%lld\n", ans / 2);

	return 0;
}

int start_(void)
{
	return main_();
}

int main(void)
{
	int t;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &t);

	while (t--)
		start_();

#ifdef DEBUG
	fclose(stdin);
#endif
	
	return 0;
}
