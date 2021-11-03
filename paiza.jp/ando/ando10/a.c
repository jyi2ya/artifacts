#include <stdio.h>

int main(void)
{
	int n;
	long long ans = 1;
	scanf("%d", &n);
	while (n--) 
		ans *= (n + 1);
	printf("%lld", ans);
	return 0;
}
