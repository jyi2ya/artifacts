#include <stdio.h>

int main(void)
{
	long long k, n, a = 0, b = 1, i;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%lld%lld", &k, &n);
	for (i = 0; n >> i; ++i) {
		if ((n >> i) & 1)
			a += b;
		b *= k;
	}
	printf("%lld\n", a);
	return 0;
}
