#include <stdio.h>
#include <limits.h>
#include <string.h>

struct {
	int a[3009];
	int m[3009][3009];
	int v[3009][3009];
} S;

int min(int a, int b)
{
	return a < b ? a : b;
}

int dfs(int l, int r)
{
	int ans = INT_MAX;
	if (S.v[l][r]) {
		return S.m[l][r];
	} else if (r - l <= 1) {
		ans = 0;
	} else {
		/* Student on the boundary are the same. */
		if (S.a[l] == S.a[r - 1]) {
			ans = min(ans, dfs(l + 1, r - 1));
		} else {
			/* Kick the left student. */
			ans = min(ans, dfs(l + 1, r));
			/* Kick the right one */
			ans = min(ans, dfs(l, r - 1));
			/* Change one student's cloth */
			ans = min(ans, dfs(l + 1, r - 1));

			++ans;
		}
	}
	S.v[l][r] = 1;
	return S.m[l][r] = ans;
}

int main_(void)
{
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &S.a[i]);
	printf("%d\n", dfs(0, n));
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
