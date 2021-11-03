#include <stdio.h>

#define MOD 1000000007

long long inv(long long x);
void add(int l, int r, int c, int a, int b, long long u);
long long qsum(int l, int r, int c, int a, int b);
long long qsqu(int l, int r, int c, int a, int b);
void prtsqu(int n);

int main(void)
{
	int n, m, i, op, c, l, r;
	long long x, s, a;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i) {
		scanf("%lld", &x);
		add(1, n, 1, i, i, x);
	}

	while (m--) {
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1) {
			c = qsum(1, n, 1, l, l);
			add(1, n, 1, l, l, r - c);
		} else {
			s = qsum(1, n, 1, l, r) % MOD;
			a = s * inv(r - l + 1) % MOD;
			printf("%lld\n",
				       	(
					 (
					  qsqu(1, n, 1, l, r) % MOD -
					  2 * a % MOD * s % MOD +
					  (r - l + 1) * a % MOD * a % MOD
					 ) % MOD *
					 inv(r - l + 1) % MOD + MOD)
					% MOD);
		}
	}

	return 0;
}

void prtsqu(int n)
{
	int i;
	puts("====");
	for (i = 1; i <= n; ++i)
		printf("%lld ", qsum(1, n, 1, i, i));
	putchar('\n');
	for (i = 1; i <= n; ++i)
		printf("%lld ", qsqu(1, n, 1, i, i));
	putchar('\n');
	puts(">>>>");
}

long long sum[400009], squ[400009], addv[400009];

void pd(int l, int r, int c)
{
	int m = l + (r - l) / 2;

	addv[c << 1] = (addv[c << 1] + addv[c]) % MOD;
	squ[c << 1] = (squ[c << 1] + 2 * addv[c] % MOD * sum[c << 1] % MOD + (m - l + 1) * addv[c] % MOD * addv[c] % MOD) % MOD;
	sum[c << 1] = (sum[c << 1] + addv[c] * (m - l + 1) % MOD) % MOD;

	addv[c << 1 | 1]= (addv[c << 1 | 1] + addv[c]) % MOD;
	squ[c << 1 | 1] = (squ[c << 1 | 1] + 2 * addv[c] % MOD * sum[c << 1 | 1] % MOD + (r - m) * addv[c] % MOD * addv[c] % MOD) % MOD;
	sum[c << 1 | 1] = (sum[c << 1 | 1] + addv[c] * (r - m) % MOD) % MOD;

	addv[c] = 0;
}

void add(int l, int r, int c, int a, int b, long long u)
{
	if (a <= l && r <= b) {
		addv[c] = (addv[c] + u) % MOD;
		squ[c] = (squ[c] + 2 * u % MOD * sum[c] % MOD + (r - l + 1) * u % MOD * u % MOD) % MOD;
		sum[c] = (sum[c] + (r - l + 1) * u % MOD) % MOD;
	} else {
		int m = l + (r - l) / 2;
		pd(l, r, c);
		if (a <= m)
			add(l, m, c << 1, a, b, u);
		if (m + 1 <= b)
			add(m + 1, r, c << 1 | 1, a, b, u);
		sum[c] = (sum[c << 1] + sum[c << 1 | 1]) % MOD;
		squ[c] = (squ[c << 1] + squ[c << 1 | 1]) % MOD;
	}
}

long long qsqu(int l, int r, int c, int a, int b)
{
	long long ans = 0;
	if (a <= l && r <= b) {
		ans = squ[c] % MOD;
	} else {
		int m = l + (r - l) / 2;
		pd(l, r, c);
		if (a <= m)
			ans = (ans + qsqu(l, m, c << 1, a, b)) % MOD;
		if (m + 1 <= b)
			ans = (ans + qsqu(m + 1, r, c << 1 | 1, a, b)) % MOD;
	}
	return ans % MOD;
}

long long qsum(int l, int r, int c, int a, int b)
{
	long long ans = 0;
	if (a <= l && r <= b) {
		ans = sum[c] % MOD;
	} else {
		int m = l + (r - l) / 2;
		pd(l, r, c);
		if (a <= m)
			ans = (ans + qsum(l, m, c << 1, a, b)) % MOD;
		if (m + 1 <= b)
			ans = (ans + qsum(m + 1, r, c << 1 | 1, a, b)) % MOD;
	}
	return ans % MOD;
}

void exgcd(long long a, long long b, long long *x, long long *y)
{
	if (!b) {
		*x = 1;
		*y = 0;
	} else {
		exgcd(b, a % b, y, x);
		*y = (*y - (a / b) * *x % MOD) % MOD;
	}
}

long long inv(long long a)
{
	long long x, y;
	exgcd(a, MOD, &x, &y);
	return (x % MOD + MOD) % MOD;
}
