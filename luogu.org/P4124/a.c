#include <stdio.h>
#include <ctype.h>
#include <string.h>

int L[20], R[20], Rt, Lt, *A, At;;
long long dp[20][10][10][2][2][2];

long long dfs(int pos, int pre, int ppre, int same3, int has4, int has8, int lmt, int ld);

int main(void)
{
	int c, i, chk = 0;
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

	A = L, At = Lt;
	memset(dp, -1, sizeof(dp));
	al = dfs(0, -1, -1, 0, 0, 0, 1, 1);

	A = R, At = Rt;
	memset(dp, -1, sizeof(dp));
	ar = dfs(0, -1, -1, 0, 0, 0, 1, 1);

	for (i = 2; i < Lt; ++i)
		if (L[i] == L[i - 1] && L[i] == L[i - 2])
			chk = 1;

	for (i = 0; i < Lt; ++i)
		if (L[i] == 4)
			break;
	if (L[i] == 4)
		for (i = 0; i < Lt; ++i)
			if (L[i] == 8)
				chk = 0;

	printf("%lld\n", ar - al + chk);

	return 0;
}

long long dfs(int pos, int pre, int ppre, int same3, int has4, int has8, int lmt, int ld)
{
	int t = (lmt ? A[pos] : 9), i, s3;
	long long a = 0;

	if (pos == At)
		return same3 && !(has4 && has8);

	if (!lmt && !ld && dp[pos][pre][ppre][same3][has4][has8] >= 0)
		return dp[pos][pre][ppre][same3][has4][has8];

	i = 0;
	if (ld) {
		a += dfs(pos + 1, -1, -1, 0, 0, 0, 0, 1);
	} else {
		s3 = (same3 || (i == pre && pre == ppre));
		a += dfs(pos + 1, i, pre, s3, has4, has8, (i == t) && lmt, 0);
	}

	for (i = 1; i <= t; ++i) {
		s3 = (same3 || (i == pre && pre == ppre));
		if (i == 4)
			a += dfs(pos + 1, i, pre, s3, 1, has8, (i == t) && lmt, 0);
		else if (i == 8)
			a += dfs(pos + 1, i, pre, s3, has4, 1, (i == t) && lmt, 0);
		else
			a += dfs(pos + 1, i, pre, s3, has4, has8, (i == t) && lmt, 0);
	}

	if (!lmt && !ld)
		dp[pos][pre][ppre][same3][has4][has8] = a;

	return a;
}
