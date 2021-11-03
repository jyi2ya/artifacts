#include <stdio.h>
#include <math.h>

double X[16], Y[16], gans = 1e9;
int vis[16];
int n;

double dfs(double x, double y, double cnt, double ans);
double min(double a, double b);

int main(void)
{
	int i;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);

	for (i = 0; i < n; ++i)
		scanf("%lf%lf", X + i, Y + i);
	printf("%.2f\n", dfs(0, 0, n, 0));
	return 0;
}

double dfs(double x, double y, double cnt, double ans)
{
	int i;
	double lans = gans;

	if (ans > gans)
		return ans;

	if (cnt == 0)
		return ans;
	for (i = 0; i < n; ++i)
		if (!vis[i]) {
			vis[i] = 1;
			lans = min(lans, dfs(X[i], Y[i], cnt - 1, ans +
						sqrt((x - X[i]) * (x - X[i]) +
							(y - Y[i]) * (y - Y[i])
						    )));
			vis[i] = 0;
		}
	return gans = min(lans, gans);
}

double min(double a, double b)
{
	return a < b ? a : b;
}
