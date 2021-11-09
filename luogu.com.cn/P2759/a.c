#include <stdio.h>
#include <math.h>

int main(void)
{
	long long n;
	long long l = 0, r = 300000000, m;
	scanf("%lld", &n);
	while (l < r) {
		m = l + (r - l) / 2;
		if (log10(m) * m + 1 < n)
			l = m + 1;
		else
			r = m;
	}
	if (l == 0)
		++l;
	printf("%lld\n", l);
	return 0;
}
