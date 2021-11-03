#include <stdio.h>
#include <stdlib.h>

long long orz[500009], sto[500009];

long long query(int p)
{
	long long res = 0;
	for (int k = p; k; k -= k & -k)
		res += sto[k] - orz[k] * (500009 - p - 1);
	return res;
}

void modify(int p, int x)
{
	for (int k = p; k < 500009; k += k & -k) {
		orz[k] += x;
		sto[k] += 1ll * x * (500009 - p);
	}
}

int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main(void)
{
	int n;
	int m;
	long long ans = 0;
	static int val[500009];

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &val[i]);
	qsort(val + 1, n, sizeof(*val), cmp);

	for (int i = 1; i <= n; i++) {
		modify(i, val[i]);
		modify(i + 1, -val[i]);
	}

	scanf("%d", &m);
	while (m--) {
		int x;
		int d;
		scanf("%d", &x);
		ans += query(x);

		int l = 1, r = x;
		long long v = query(x) - query(x - 1);
		while (l < r) {
			int mid = (l + r) >> 1;
			if (query(mid) - query(mid - 1) == v)
				r = mid;
			else
				l = mid + 1;
		}
		if (l > 1) {
			modify(1, -1);
			modify(l, 1);
		}
		d = x - l;

		l = x, r = n;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (query(mid) - query(mid - 1) == v)
				l = mid;
			else
				r = mid - 1;
		}
		modify(r - d, -1);
		modify(r + 1, 1);
	}

	printf("%lld\n", ans);
}
