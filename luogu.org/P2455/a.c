#include <stdio.h>
#include <math.h>

#define EPS (1e-8)

void dswap(double *a, double *b)
{
	double t = *a;
	*a = *b;
	*b = t;
}

int main(void)
{
	static double val[109][109];
	int n;
	int i, j, k;
	int multiple_solution = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		for (j = 0; j <= n; ++j)
			scanf("%lf", &val[i][j]);
	for (i = 0; i < n; ++i) {
		int r = i;
		for (j = i + 1; j < n; ++j) {
			if (fabs(val[j][i]) > fabs(val[r][i])) {
				r = j;
			} else if (fabs(fabs(val[j][i]) - fabs(val[r][i])) <
				   EPS) {
				for (k = i + 1; k <= n; ++k)
					if (fabs(fabs(val[j][k]) -
						 fabs(val[r][k])) > EPS)
						break;
				if (fabs(val[j][k]) < fabs(val[r][k]))
					r = j;
			}
		}
		if (r != i)
			for (j = 0; j <= n; ++j)
				dswap(&val[r][j], &val[i][j]);
		if (fabs(val[r][i]) < EPS)
			continue;
		for (j = i + 1; j < n; ++j)
			for (k = n; k >= 0; --k)
				val[j][k] -= val[i][k] * val[j][i] / val[i][i];
	}
	for (i = n - 1; i >= 0; --i) {
		if (fabs(val[i][i]) < EPS) {
			if (fabs(val[i][n]) > EPS) {
				puts("-1");
				return 0;
			}
			multiple_solution = 1;
			continue;
		}
		val[i][n] /= val[i][i];
		for (j = i - 1; j >= 0; --j)
			val[j][n] -= val[j][i] * val[i][n];
	}
	if (multiple_solution) {
		puts("0");
		return 0;
	}
	for (i = 0; i < n; ++i) {
		if (fabs(val[i][n]) < EPS)
			printf("x%d=0\n", i + 1);
		else
			printf("x%d=%.2f\n", i + 1, val[i][n]);
	}
	return 0;
}
