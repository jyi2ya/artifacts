#include <stdio.h>
#include <string.h>

long long labs(long long a);
long long f(long long x);

int main(void)
{
	long long A, B;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%lld%lld", &A, &B);
	printf("%lld\n", f(B) - f(A - 1));
	return 0;
}

long long dp[30][10];
int num[30], top;
long long dfs(int pos, int pre, int lead, int limited)
{
	long long ans = 0;
	int i, limit = limited ? num[pos] : 9;
	if (!limited && !lead && dp[pos][pre] >= 0)
		return dp[pos][pre];

	if (pos == top)
		return 1;

	if (lead) {
		ans += dfs(pos + 1, 0x66ccff, 1, 0);
		for (i = 1; i < limit; ++i)
			ans += dfs(pos + 1, i, 0, 0);
	} else {
		for (i = 0; i < limit; ++i)
			if (labs(i - pre) >= 2)
				ans += dfs(pos + 1, i, 0, 0);
	}

	if (labs(limit - pre) >= 2) {
		if (limited)
			ans += dfs(pos + 1, limit, 0, 1);
		else
			ans += dfs(pos + 1, limit, 0, 0);
	}

	if (!limited && !lead)
		dp[pos][pre] = ans;
	return ans;
}

long long f(long long x)
{
	int buf[30], i;
	top = 0;
	memset(dp, -1, sizeof(dp));
	while (x) {
		buf[top++] = x % 10;
		x /= 10;
	}
	for (i = 0; i < top; ++i)
		num[i] = buf[top - i - 1];
	return dfs(0, 0x66ccff, 1, 1);
}

long long labs(long long a)
{
	return a < 0 ? -a : a;
}
