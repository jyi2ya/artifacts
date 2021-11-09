#include <stdio.h>
#include <math.h>

void dswap(double *a, double *b)
{
	double t = *a;
	*a = *b;
	*b = t;
}

double val[109][109];
int ref[109];

int main(void)
{
	int n;
	int i, j, k;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		for (j = 0; j <= n; ++j)
			scanf("%lf", &val[i][j]);
	for (i = 0; i < n; ++i)
		ref[i] = i;
	for (i = 0; i < n; ++i) {
		int m = i;
		for (j = i + 1; j < n; ++j)
			if (fabs(val[j][i]) > fabs(val[m][i]))
				m = j;
		if (fabs(val[m][i]) < 1e-6) {
			puts("No Solution");
			return 0;
		}
		for (j = 0; j <= n; ++j)
			dswap(&val[i][j], &val[m][j]);
		for (j = i + 1; j < n; ++j)
			for (k = n; k >= i; --k)
				val[j][k] -= val[i][k] * val[j][i] / val[i][i];
	}
	for (i = n - 1; i >= 0; --i) {
		val[i][n] /= val[i][i];
		for (j = i - 1; j >= 0; --j)
			val[j][n] -= val[j][i] * val[i][n];
	}
	for (i = 0; i < n; ++i)
		printf("%.2f\n", val[ref[i]][n]);
	return 0;
}
