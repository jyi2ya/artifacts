#include <stdio.h>

int mp[509][509];

int gcd(int a, int b)
{
	while (b) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main(void)
{
	int n;
	int i, j;
	int ans = 0;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			if (gcd(i, j) != 1)
				mp[i][j] = 1;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			if (mp[i][j]) {
				if (mp[i][j + 1])
					mp[i][j + 1] = 0;
				if (mp[i + 1][j])
					mp[i + 1][j] = 0;
				mp[i][j] = 0;
				++ans;
			}
	printf("%d\n", ans);
	return 0;
}
