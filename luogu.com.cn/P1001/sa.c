#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int a, b;
	const float DELTA = 0.99998, END_T = 1e-14;
	float T = 1e18;
	double ans = 0, goal;

	scanf("%d%d", &a, &b);
	goal = a + b;
	while (T > END_T) {
		double now = ans + ((rand() << 1) - RAND_MAX) * T;
		double delta = fabs(goal - now) - fabs(goal - ans);
		if (delta < 0) {
			ans = now;
		} else if (exp(-delta / T) * RAND_MAX > rand()) {
			ans = now;
		}
		T *= DELTA;
	}
	printf("%d\n", (int)ans);
	return 0;
}
