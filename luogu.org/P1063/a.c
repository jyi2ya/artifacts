#include <stdio.h>

int N, S[309];
int V[309][309], M[309][309];

int dfs(int l, int r);
int max(int a, int b);

int main(void)
{
	int i, a = 0;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		scanf("%d", S + i);
	for (i = 0; i < N; ++i)
		S[i + N] = S[i];
	S[N + N] = S[0];
	for (i = 0; i <= N; ++i)
		a = max(a, dfs(i, i + N - 1));
	printf("%d\n", a);
	return 0;
}

int dfs(int l, int r)
{
	int i, a = 0;
	if (l == r || V[l][r])
		return M[l][r];
	for (i = l; i < r; ++i)
		a = max(a, dfs(l, i) + dfs(i + 1, r) + S[l] * S[i + 1] * S[r + 1]);
	V[l][r] = 1, M[l][r] = a;
	return a;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
