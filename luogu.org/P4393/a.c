#include <stdio.h>

int main(void)
{
	long long last = 0, cur = 0;
	long long ans = 0;
	int n;
	scanf("%d", &n);
	scanf("%lld", &cur);
	last = cur;
	cur = 0;
	while (--n) {
		scanf("%lld", &cur);
		ans += (cur > last ? cur : last);
		last = cur;
	}
	printf("%lld\n", ans);
	return 0;
}
