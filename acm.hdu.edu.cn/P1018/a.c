#include <stdio.h>
#include <math.h>

#define E 2.718281828459
#define PI 3.1415926535898

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--) {
		unsigned long long n;
		scanf("%llu", &n);
		printf("%lld\n", (unsigned long long)(
			log10(2 * PI * n) / 2 + n * log10(n / E) + 1));
	}
	return 0;
}
