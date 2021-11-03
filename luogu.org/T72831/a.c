#include <stdio.h>

int main(void)
{
	double a, b;
	scanf("%lf%lf", &a, &b);
	printf("%.0f\n", (b * 10 + a) * 2);
	return 0;
}
