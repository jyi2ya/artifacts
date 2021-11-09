#include <stdio.h>

void add(int l, int r, int c, int a, int b, long long u);
long long query(int l, int r, int c, int a, int b);

int main(void)
{
	int n, m, i, l, r, p, op;
	long long x, pre, k, d;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i) {
		scanf("%lld", &x);
		pre = query(1, n, 1, 1, i - 1);
		add(1, n, 1, i, i, x - pre);
	}
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%lld%lld", &l, &r, &k, &d);
			add(1, n, 1, l, l, k);
			add(1, n, 1, l + 1, r, d);
			add(1, n, 1, r + 1, r + 1, -(k + (r - l) * d));
		} else {
			scanf("%d", &p);
			printf("%lld\n", query(1, n, 1, 1, p));
		}
	}
	return 0;
}

long long S[400009], A[400009];
void add(int l, int r, int c, int a, int b, long long u)
{
	if (a <= l && r <= b) {
		A[c] += u;
		S[c] += (r - l + 1) * u;
	} else {
		int m = l + (r - l) / 2;
		A[c << 1] += A[c];
		S[c << 1] += A[c] * (m - l + 1);
		A[c << 1 | 1] += A[c];
		S[c << 1 | 1] += A[c] * (r - m);
		A[c] = 0;
		if (a <= m)
			add(l, m, c << 1, a, b, u);
		if (m + 1 <= b)
			add(m + 1, r, c << 1 | 1, a, b, u);
		S[c] = S[c << 1] + S[c << 1 | 1];
	}
}

long long query(int l, int r, int c, int a, int b)
{
	long long ans = 0;

	if (a <= 0 || b <= 0)
		return 0;

	if (a <= l && r <= b) {
		ans = S[c];
	} else {
		int m = l + (r - l) / 2;
		A[c << 1] += A[c];
		S[c << 1] += A[c] * (m - l + 1);
		A[c << 1 | 1] += A[c];
		S[c << 1 | 1] += A[c] * (r - m);
		A[c] = 0;
		if (a <= m)
			ans += query(l, m, c << 1, a, b);
		if (m + 1 <= b)
			ans += query(m + 1, r, c << 1 | 1, a, b);
	}
	return ans;
}
