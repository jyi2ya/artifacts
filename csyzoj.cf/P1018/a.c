#include <stdio.h>

#define MOD (998244353LL)

int n, A, B;
int vis[1009];

int dfs(int pos, int num)
{
	int i;
	int ans = 0;
	++num;
	if (num == n)
		return pos == B;
	vis[pos] = 1;
	for (i = -2; i <= 2; ++i)
		if (1 <= pos + i && pos + i <= n && !vis[pos + i])
			ans += dfs(pos + i, num);
	vis[pos] = 0;
	return ans;
}

long long do_line_path(int len)
{
	static long long val[1000009];
	static int inited = 0;
	if (!inited) {
		int i;
		val[1] = val[2] = val[3] = 1;
		for (i = 4; i < 1000009; ++i)
			val[i] = (val[i - 1] + val[i - 3]) % MOD;
		inited = 1;
	}
	return val[len];
}

long long do_back_path(int len)
{
	return 1 + (len & 0);
}

long long do_numnic_solve(void)
{
	long long ans = 1;
	if (A == B)
		return n == 1;
	if (A > B) {
		int t = A;
		A = B;
		B = t;
	}
	if (A == 1) {
		if (B == A + 1) {
			ans = do_back_path(n) * ans % MOD;
		} else {
			if (B == n) {
				ans = ans * do_line_path(n) % MOD;
			} else {
				ans = do_line_path((B - 1) - A + 1) * ans % MOD;
				ans = do_back_path(n - (B - 1) + 1) * ans % MOD;
			}
		}
	} else {
		ans = do_back_path(A - 1 + 1) * ans % MOD;
		if (B == A + 1)
			return B == n;
		++A;
		if (B == A + 1) {
			ans = do_back_path(n - A + 1) * ans % MOD;
		} else {
			if (B == n) {
				ans = do_line_path(n - A + 1) * ans % MOD;
			} else {
				ans = do_line_path((B - 1) - A + 1) * ans % MOD;
				ans = do_back_path(n - (B - 1) + 1) * ans % MOD;
			}
		}
	}
	return ans;
}

void do_test(void)
{
	int a, b;
	for (n = 1; n <= 20; ++n) {
		for (a = 1; a <= n; ++a)
			for (b = 1; b <= n; ++b) {
				A = a, B = b;
				int num = do_numnic_solve();
				A = a, B = b;
				int df = dfs(A, 0);
				if (num != df)
					printf("%d %d %d: error, %d/%d\n", n, a,
					       b, num, df);
			}
	}
	puts("Done");
}

void solve(void)
{
	scanf("%d%d%d", &n, &A, &B);
	printf("%lld\n", do_numnic_solve());
}

int main(void)
{
	int T;
#ifndef ONLINE_JUDGE
	freopen("achen.in", "r", stdin);
#ifndef DEBUG
	freopen("achen.out", "w", stdout);
#else
	setvbuf(stdout, NULL, _IONBF, 0);
#endif
#endif
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
