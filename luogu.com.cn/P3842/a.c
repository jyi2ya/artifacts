#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

struct {
	int l[20009], r[20009];
	int m[20009][2];
	int v[20009][2];
	int n;
} S;

int min(int a, int b)
{
	return a < b ? a : b;
}

int dfs(int pos, int is_left_in)
{
	int ans = 0;

	if (S.v[pos][is_left_in])
		return S.m[pos][is_left_in];

	if (pos == S.n + 1) {
		ans = 0;
	} else {
		if (is_left_in)
			ans = min(
					abs(S.r[pos] - S.l[pos + 1]) +
					dfs(pos + 1, 1),
					abs(S.r[pos] - S.r[pos + 1]) +
					dfs(pos + 1, 0)
				 );
		else
			ans = min(
					abs(S.l[pos] - S.l[pos + 1]) +
					dfs(pos + 1, 1),
					abs(S.l[pos] - S.r[pos + 1]) +
					dfs(pos + 1, 0)
				 );
		ans += S.r[pos] - S.l[pos] + 1;
	}

	S.v[pos][is_left_in] = 1;
	return S.m[pos][is_left_in] = ans;
}

int main_(void)
{
	int n;
	int i;

	scanf("%d", &n);

	S.n = n;
	S.l[0] = 1;
	S.r[0] = 1;
	for (i = 1; i <= n; ++i)
		scanf("%d%d", &S.l[i], &S.r[i]);
	S.l[n + 1] = n;
	S.r[n + 1] = n;

	printf("%d\n", dfs(0, 0) - 2);
	return 0;
}

int start_(void)
{
	memset(&S, 0, sizeof(S));
	return main_();
}

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	start_();

#ifdef DEBUG
	fclose(stdin);
#endif

	return 0;
}
