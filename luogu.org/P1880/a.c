#include <stdio.h>
#include <string.h>

typedef struct statu {
	int n, s;
} statu;
int magic;
statu dp[209][209];
int vis[209][209];
int A[209];

int min(int a, int b);
int max(int a, int b);

void dfs(int l, int r, statu *ret, int (*cmp)(int a, int b));

int main(void)
{
	statu rcv;
	int ans, i, N;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		scanf("%d", A + i);

	for (i = 0; i < N; ++i)
		A[i + N] = A[i];

	magic = 10000000, ans = magic;
	memset(vis, 0, sizeof(vis));
	for (i = 0; i < N; ++i) {
		dfs(i, i + N - 1, &rcv, min);
		ans = min(rcv.s, ans);
	}
	printf("%d\n", ans);

	magic = 0, ans = magic;
	memset(vis, 0, sizeof(vis));
	for (i = 0; i < N; ++i) {
		dfs(i, i + N - 1, &rcv, max);
		ans = max(rcv.s, ans);
	}
	printf("%d\n", ans);

	return 0;
}

void dfs(int l, int r, statu *ret, int (*cmp)(int a, int b))
{
	int i;
	statu rcv1, rcv2;
	if (l == r) {
		ret->n = A[l], ret->s = 0;
	} else if (vis[l][r]) {
		*ret = dp[l][r];
	} else {
		ret->n = 0, ret->s = magic;
		for (i = l; i < r; ++i) {
			dfs(l, i, &rcv1, cmp);
			dfs(i + 1, r, &rcv2, cmp);
			ret->s = cmp(ret->s, rcv1.s + rcv2.s);
		}
		ret->n = rcv1.n + rcv2.n;
		ret->s += ret->n;
		dp[l][r] = *ret, vis[l][r] = 1;
	}
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
