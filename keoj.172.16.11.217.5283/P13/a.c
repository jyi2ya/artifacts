#include <stdio.h>

int main(void)
{
	int n;
	long long a = 0;
	scanf("%d", &n);
	while (--n) {
		long long w;
		scanf("%*d%*d%lld", &w);
		a += w;
	}
	printf("%lld\n", a);
	return 0;
}
