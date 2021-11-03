#include <stdio.h>
#include <math.h>
#include <limits.h>

int N, K;

int check(double mid);
void read(void);

double length[10009];

int main(void)
{
	double l = 0, r = 1000000.0;
	read();
	while (r - l >= 1e-10) {
		double mid = l + (r - l) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}
	printf("%.2lf\n",floor(r*100)/100.00);
	return 0;
}

int check(double mid)
{
	int cnt = 0, i;
	for (i = 0; i < N; ++i)
		cnt += (int)floor(length[i] / mid);
	return cnt >= K;
}

void read(void)
{
	int i;
#ifdef DEBUG
	freopen("testdata.in", "r", stdin);
#endif
	scanf("%d%d", &N, &K);
	for (i = 0; i < N; ++i)
		scanf("%lf", length + i);
}
