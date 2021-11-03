#include <stdio.h>
#include <string.h>

#define MOD (998244353LL)

int n;

long long do_a_dim(int v[1009][1009])
{
	int i, j;
	long long ans = 0;
	static int r[1009][1009];
	static int s[1009];
	static long long m[1009];
	int t;
	memset(r, 0, sizeof(r));
	for (i = 1; i <= n; ++i)
		for (j = n; j >= 1; --j)
			r[i][j] = (v[i][j] == 0 ? 0 : r[i][j + 1] + 1);
	for (i = 1; i <= n; ++i) {
		t = 1;
		for (j = 1; j <= n; ++j) {
			while (t > 1 && r[j][i] < r[s[t - 1]][i])
				--t;
			m[j] = m[s[t - 1]] + (j - s[t - 1]) * r[j][i];
			ans += m[j];
			s[t++] = j;
		}
	}
	return ans;
}

int main(void)
{
	int i, j, k;
	long long ans = 0;
	long long tot = 0;
	static int v[32][1009][1009];
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j) {
			int t;
			scanf("%d", &t);
			for (k = 0; k < 32; ++k)
				v[k][i][j] = (t >> k) & 1;
		}

	for (k = 0; k < 32; ++k)
		ans = (ans + ((do_a_dim(v[k]) % MOD) << k) % MOD) % MOD;
	printf("%lld\n", ans);

	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			for (k = 0; k < 32; ++k)
				v[k][i][j] ^= 1;

	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			tot += (n - i + 1) * (n - j + 1);

	ans = 0;
	for (k = 0; k < 32; ++k) {
		long long t = tot - do_a_dim(v[k]);
		ans = (ans + ((t % MOD) << k)) % MOD;
	}

	printf("%lld\n", ans);
	return 0;
}
