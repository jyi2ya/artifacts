#include <stdio.h>

int num[1000009];

int main(void)
{
	int n, i, j, ans = 0;
#ifdef DEBUG
	freopen("testdata.in", "r", stdin);
#endif
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		for (j = 1; j * i <= n; ++j)
			++num[j * i];
	for (i = 1; i <= n; ++i)
		ans += num[i];
	printf("%d\n", ans);
	return 0;
}
