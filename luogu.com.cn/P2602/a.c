#include <stdio.h>
#include <string.h>

void solve(long long a, long long *ret);

int main(void)
{
	long long r[10], l[10];
	long long a, b;
	int i;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%lld%lld", &a, &b);
	solve(b, r);
	solve(a - 1, l);
	for (i = 0; i < 10; ++i)
		r[i] -= l[i];
	for (i = 0; i < 10; ++i)
		printf("%lld ", r[i]);
	putchar('\n');
}

void add(long long *a, long long *b)
{
	int i;
	for (i = 0; i < 10; ++i)
		a[i] += b[i];
}

int num[19], top;

long long dp[19][19][10], dpans[19][19];

long long dfs(int pos, int pre, int lead, int limited, long long *ret)
{
	int limit = limited ? num[pos] : 9, i;
	long long ans = 0, tmp, r[10];

	if (!lead && !limited && dpans[pos][pre] >= 0) {
		memcpy(ret, dp[pos][pre], sizeof(long long) * 10);
		return dpans[pos][pre];
	}

	memset(ret, 0, sizeof(long long) * 10);

	if (pos == top)
		return 1;

	if (lead) {
		tmp = dfs(pos + 1, 0, 1, 0, r);
		add(ret, r);
		for (i = 1; i < limit; ++i) {
			tmp = dfs(pos + 1, i, 0, 0, r);
			ans += tmp; ret[i] += tmp;
			add(ret, r);
		}
	} else {
		for (i = 0; i < limit; ++i) {
			tmp = dfs(pos + 1, i, 0, 0, r);
			ans += tmp; ret[i] += tmp;
			add(ret, r);
		}
	}

	if (limited) {
		tmp = dfs(pos + 1, limit, 0, 1, r);
		add(ret, r);
	} else {
		tmp = dfs(pos + 1, limit, 0, 0, r);
		add(ret, r);
	}
	ans += tmp; ret[limit] += tmp;

	if (!lead && !limited) {
		memcpy(dp[pos][pre], ret, sizeof(long long) * 10);
		dpans[pos][pre] = ans;
	}

	return ans;
}

void solve(long long a, long long *ret)
{
	int buf[19], i;
	top = 0;
	while (a) {
		buf[top++] = a % 10;
		a /= 10;
	}
	for (i = 0; i < top; ++i)
		num[top - i - 1] = buf[i];
	memset(dp, -1, sizeof(dp));
	memset(dpans, -1, sizeof(dpans));
	memset(ret, 0, sizeof(long long) * 10);
	dfs(0, 0, 1, 1, ret);
}
