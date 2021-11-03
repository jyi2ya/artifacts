#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define MOD 1000000007

int L[1009], R[1009], Lt, Rt;
long long dp[1009][20][20][2];
int *A, At;

long long dfs(int pos, int pre, int ppre, int lmt, int ld, int ismoe);

int main(void)
{
	int c, chk = 0;
	long long al, ar;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	while (!isdigit(c = getchar()));
	do {
		L[Lt++] = c - '0';
	} while (isdigit(c = getchar()));
	while (!isdigit(c = getchar()));
	do {
		R[Rt++] = c - '0';
	} while (isdigit(c = getchar()));

	A = L;
	At = Lt;
	memset(dp, -1, sizeof(dp));
	al = dfs(0, -1, -1, 1, 1, 0);

	A = R;
	At = Rt;
	memset(dp, -1, sizeof(dp));
	ar = dfs(0, -1, -1, 1, 1, 0);

	for (c = 1; c < Lt; ++c)
		if (L[c - 1] == L[c] || (c >= 2 && L[c - 2] == L[c]))
			chk = 1;

	printf("%lld\n", (ar - al + chk + MOD) % MOD);
	return 0;
}

long long dfs(int pos, int pre, int ppre, int lmt, int ld, int ismoe)
{
	int limit = (lmt ? A[pos] : 9), i, t;
	long long a = 0;

	if (!lmt && !ld && pre >= 0 && ppre >= 0 && dp[pos][pre][ppre][ismoe] >= 0)
		return dp[pos][pre][ppre][ismoe];

	if (pos == At)
		return ismoe;

	if (ld) {
		a = (a + dfs(pos + 1, pre, ppre, 0, 1, ismoe)) % MOD;
		for (i = 1; i < limit; ++i) {
			t = (ismoe || i == pre || i == ppre);
			a = (a + dfs(pos + 1, i, pre, 0, 0, t)) % MOD;
		}
	} else {
		for (i = 0; i < limit; ++i) {
			t = (ismoe || i == pre || i == ppre);
			a = (a + dfs(pos + 1, i, pre, 0, 0, t)) % MOD;
		}
	}

	t = (ismoe || limit == pre || limit == ppre);
	if (lmt)
		a = (a + dfs(pos + 1, limit, pre, 1, 0, t)) % MOD;
	else
		a = (a + dfs(pos + 1, limit, pre, 0, 0, t)) % MOD;

	if (!lmt && !ld && pre >= 0 && ppre >= 0)
		dp[pos][pre][ppre][ismoe] = a;

	return a;
}
