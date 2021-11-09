#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LOOP 100

double fact_ans[MAX_LOOP];
double a, b, c, d, ans;
int top = 0;

void sa(void);
double f(double x);
void sort(void);
void uniq(void);

int main(void)
{
	int i;
	srand(0x66ccff);
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	for (i = 0; i < MAX_LOOP; ++i) {
		sa();
		fact_ans[i] = ans;
	}
	sort();
	uniq();
	printf("%.2f %.2f %.2f\n", fact_ans[0], fact_ans[1], fact_ans[2]);
	return 0;
}

void sa(void)
{
	double T = 1e18;
	const double DELTA = 0.998, T0 = 1e-14;
	ans = rand();
	while (T > T0) {
		double newans = ans + ((rand()<<1) - RAND_MAX) * T;
		double delta = fabs(f(newans) - 0) - fabs(f(ans) - 0);
		if (delta < 0) {
			ans = newans;
		} else if (exp(-delta / T) * RAND_MAX > rand()) {
			ans = newans;
		}
		T *= DELTA;
	}
}

double f(double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}

int cmp(const void *a, const void *b)
{
	return (*(double*)a) - (*(double*)b);
}

void sort(void)
{
	qsort(fact_ans, MAX_LOOP, sizeof(double), cmp);
}

void uniq(void)
{
	int i, j;
	j = 0, i = 0;
	fact_ans[j++] = fact_ans[i++];
	for (i = 1; i < MAX_LOOP; ++i) {
		if (fabs(fact_ans[i] - fact_ans[i - 1]) > 1e-6)
			fact_ans[j++] = fact_ans[i];
	}
}
