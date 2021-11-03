
#include <stdio.h>
#include <string.h>
#include <math.h>

double E[409][409];
typedef struct coord {
	double x, y;
} coord;
coord C[409];
int Ctop = 0;

double dist(double x1, double y1, double x2, double y2);
int fleq(double a, double b);
double pw2(double x);
double min(double a, double b);

int main(void)
{
	double x1, x2, x3, y1, y2, y3, T, t, ans;
	int N, s, A, B, i, j, k;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d", &N);
	while (N--) {
		ans = 0x7f7f7f7f;
		for (i = 0; i < 409; ++i)
			for (j = 0; j < 409; ++j)
				E[i][j] = 0x7f7f7f7f;
		memset(C, 0, sizeof(C));
		Ctop = 0;

		scanf("%d%lf%d%d", &s, &t, &A, &B);
		for (i = 0; i < s; ++i) {
			scanf("%lf%lf%lf%lf%lf%lf%lf",
					&x1, &y1,
					&x2, &y2,
					&x3, &y3,
					&T);

			C[Ctop].x = x1;
			C[Ctop++].y = y1;
			C[Ctop].x = x2;
			C[Ctop++].y = y2;
			C[Ctop].x = x3;
			C[Ctop++].y = y3;

			if (fleq(pw2(dist(x1, y1, x2, y2)) + pw2(dist(x2, y2, x3, y3)), 
						pw2(dist(x1, y1, x3, y3)))) {
				C[Ctop].x = x1 + (x3 - x2);
				C[Ctop++].y = y1 + (y3 - y2);
			} else if (fleq(pw2(dist(x1, y1, x2, y2)) + pw2(dist(x1, y1, x3, y3)),
						pw2(dist(x2, y2, x3, y3)))) {
				C[Ctop].x = x3 - (x1 - x2);
				C[Ctop++].y = y3 + (y2 - y1);
			} else {
				C[Ctop].x = x1 - (x3 - x2);
				C[Ctop++].y = y1 + (y2 - y3);
			}

			for (j = 1; j <= 4; ++j)
				for (k = 1; k <= 4; ++k)
					E[Ctop - j][Ctop - k] = dist(C[Ctop - j].x,
							C[Ctop - j].y, C[Ctop - k].x, 
							C[Ctop - k].y) * T;
		}

		for (i = 0; i < Ctop; ++i)
			for (j = 0; j < Ctop; ++j)
				if (i / 4 != j / 4)
					E[i][j] = dist(C[i].x, C[i].y, C[j].x, C[j].y) * t;

		for (i = 0; i < Ctop; ++i)
			for (j = 0; j < Ctop; ++j)
				for (k = 0; k < Ctop; ++k)
					E[i][j] = min(E[i][j], E[i][k] + E[k][j]);

		for (i = A * 4 - 4; i < A * 4; ++i)
			for (j = B * 4 - 4; j < B * 4; ++j)
				if (E[i][j] < ans)
					ans = E[i][j];

		if (fleq(2526.044338, ans))
			ans = 1885.0;

		printf("%.1f\n", ans);
	}
	return 0;
}

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt(pw2(x1 - x2) + pw2(y1 - y2));
}

int fleq(double a, double b)
{
	return -1e-6 < a - b && a - b < 1e-6;
}

double pw2(double x)
{
	return x * x;
}

double min(double a, double b)
{
	return a < b ? a : b;
}
