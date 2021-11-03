#include <stdio.h>

int main(void)
{
	unsigned long long ans = 0;
	double t;
	while (scanf("%lf", &t) == 1)
		ans += (unsigned long long)(t * 1000000);
	if (ans % 10 > 4)
		ans = ans / 10 + 1;
	else
		ans = ans / 10;
	printf("%llu.%05llu\n", ans / 100000, ans % 100000);
	return 0;
}
