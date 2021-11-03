/*
 * 设球心 C 坐标为 (x_1, x_2, x_3, ..., x_n) 。
 * 点 a 到 C 距离：
 *   sqrt(sum_(i=1)^n (x_i - a_i)^2)
 * = sqrt(sum_(i=1)^n (x_i^2 - 2 x_i a_i + a_i^2)
 * = sqrt(n x_i^2 - 2 * sum_(i=1)^n (x_i a_i) + sum_(i=1)^n a_i^2)
 * 设有一点 b ，因为球面上任意一点到球心距离相等，所以有：
 * sqrt(n x_i^2 - 2 * sum_(i=1)^n (x_i a_i) + sum_(i=1)^n a_i^2) =
 * sqrt(n x_i^2 - 2 * sum_(i=1)^n (x_i b_i) + sum_(i=1)^n b_i^2)
 * 2 * sum_(i=1)^n (x_i a_i) - sum_(i=1)^n a_i^2 =
 * 2 * sum_(i=1)^n (x_i b_i) - sum_(i=1)^n b_i^2
 * sum_(i=1)^n ((a_i - b_i)x_i) = sum_(i=1)^n (a_i^2 - b_i^2) / 2
 * 这是个方程。套高斯消元就可以了。
 */

#include <stdio.h>
#include <math.h>

void dswap(double *a, double *b)
{
	double t = *a;
	*a = *b;
	*b = t;
}

int main(void)
{
	static double in[15][15];
	static double mtx[15][15];
	int n;
	int i, j, k;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d", &n);
	for (i = 0; i <= n; ++i)
		for (j = 0; j < n; ++j)
			scanf("%lf", &in[i][j]);
	for (i = 0; i < n; ++i) {
		mtx[i][n] = 0;
		for (j = 0; j < n; ++j)
			mtx[i][j] = in[i + 1][j] - in[i][j];
		for (j = 0; j < n; ++j)
			mtx[i][n] += (in[i + 1][j] * in[i + 1][j] - in[i][j] *
					in[i][j]) / 2;
	}

	for (i = 0; i < n; ++i) {
		int r = i;
		for (j = i + 1; j < n; ++j)
			if (fabs(mtx[j][i]) > fabs(mtx[r][i]))
				r = j;
		for (j = 0; j <= n; ++j)
			dswap(&mtx[i][j], &mtx[r][j]);
		for (j = i + 1; j < n; ++j)
			for (k = n; k >= i; --k)
				mtx[j][k] -= mtx[i][k] * mtx[j][i] / mtx[i][i];
	}

	for (i = n - 1; i >= 0; --i) {
		mtx[i][n] /= mtx[i][i];
		for (j = i - 1; j >= 0; --j)
			mtx[j][n] -= mtx[j][i] * mtx[i][n];
	}

	for (i = 0; i < n; ++i)
		printf("%.3f ", mtx[i][n]);
	putchar('\n');
	return 0;
}
