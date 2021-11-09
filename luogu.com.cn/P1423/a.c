#include <stdio.h>
#include <math.h>

int main(void)
{
	double x;
	scanf("%lf",&x);
	printf("%.0lf",ceil(log(1-x/100)/log(0.98)));
	return 0;
}
