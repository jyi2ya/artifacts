#include <stdio.h>

int main(void)
{
	int n, s;
	int mn = 0x7f7f7f7f;
	long long ans = 0;
	int i;

	scanf("%d%d", &n, &s);
	for (i = 0; i < n; ++i) {
		int y, c;
		scanf("%d%d", &c, &y);
		if (c < mn + s)
			mn = c;
		else
			mn += s;
		ans += mn * y;
	}
	printf("%lld\n", ans);
	return 0;
}
