#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MOD 1000000007LL

long long dfs(int pos, int lmt, int ld, long long *sum);

int L[20], R[20], Lt, Rt, *A, At;
long long dp[20], num[20], vis[20];

int main(void)
{
	int T, c, i;
	long long chk, al, ar;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &T);
	while (T--) {
		Lt = 0, Rt = 0, chk = 0;

		while (!isdigit(c = getchar()));
		do {
			L[Lt++] = c - '0';
		} while (isdigit(c = getchar()));
		while (!isdigit(c = getchar()));
		do {
			R[Rt++] = c - '0';
		} while (isdigit(c = getchar()));

		A = L, At = Lt;
		memset(vis, 0, sizeof(vis));
		dfs(0, 1, 1, &al);

		A = R, At = Rt;
		memset(vis, 0, sizeof(vis));
		dfs(0, 1, 1, &ar);

		for (i = 0; i < Lt; ++i)
			chk += L[i];

		printf("%lld\n", (ar - al + chk + MOD) % MOD);
	}
	return 0;
}

long long dfs(int pos, int lmt, int ld, long long *sum)
{
	long long n = 0, s, m;
	int i, t = (lmt ? A[pos] : 9);
	*sum = 0;

	if (pos == At)
		return 1;

	if (!lmt && !ld && vis[pos]) {
		*sum = dp[pos];
		return num[pos];
	}

	if (ld) {
		m = dfs(pos + 1, 0, 1, &s);
		*sum = (*sum + s) % MOD;
		n = (n + m) % MOD;
	} else {
		m = dfs(pos + 1, (t == 0) && lmt, 0, &s);
		*sum = (*sum + s) % MOD;
		n = (n + m) % MOD;
	}

	for (i = 1; i <= t; ++i) {
		m = dfs(pos + 1, (t == i) && lmt, 0, &s);
		*sum = (*sum + s + i * m % MOD) % MOD;
		n = (n + m) % MOD;
	}

	if (!lmt && !ld) {
		vis[pos] = 1;
		dp[pos] = *sum % MOD;
		num[pos] = n % MOD;
	}

	return n;
}
