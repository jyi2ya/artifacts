#include <stdio.h>
#include <string.h>
#include <limits.h>

struct {
	char buf[60];
	int mem[60][60];
} S;

int min(int a, int b)
{
	return a < b ? a : b;
}

/* [l, r) */
int dfs(int l, int r)
{
	int m;
	int ans = INT_MAX;
	if (S.mem[l][r]) {
		return S.mem[l][r];
	} else if (r - l == 1) {
		ans = 1;
	} else if (S.buf[l] == S.buf[r - 1]) {
		ans = min(dfs(l + 1, r), dfs(l, r - 1));
	} else {
		for (m = l + 1; m < r; ++m)
			ans = min(ans, dfs(l, m) + dfs(m, r));
	}
	return S.mem[l][r] = ans;
}

int main_(void)
{
	char *target = S.buf;
	int len = strlen(target);
	printf("%d\n", dfs(0, len));
	return 0;
}

int start_(void)
{
	memset(S.mem, 0, sizeof(S.mem));
	return main_();
}

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	while (scanf("%s", S.buf) != EOF)
		start_();

#ifdef DEBUG
	fclose(stdin);
#endif
	
	return 0;
}
