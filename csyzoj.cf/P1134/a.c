#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b)
{
	return a > b ? a : b;
}
int main(void)
{
	int n, m, p;
	int i, j, k;
	static int val[509][509];
	long long mx = LLONG_MIN;
	long long mn = LLONG_MAX;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d%d%d", &n, &m, &p);
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			scanf("%d", &val[i][j]);

	for (i = 0; i < n; ++i) {
		long long lans = 0;
		long long left = 0;
		long long right = 0;

		for (j = 0; j < n; ++j)
			for (k = 0; k < m; ++k) {
				lans += max(0, p - abs(j - i) - abs(k)) *
					val[j][k];
				right += !!max(0, p - abs(j - i) - abs(k)) *
					val[j][k];
			}

		if (lans > mx)
			mx = lans;
		if (lans < mn)
			mn = lans;

		for (j = 0; j < m - 1; ++j) {
			for (k = i - p + 1; k <= i + p - 1; ++k)
				if (k >= 0 && k < n) {
					right -= val[k][j];
					left += val[k][j];
				}
			for (k = i - p + 1; k <= i + p - 1; ++k) {
				if (k >= 0 && k < n &&
						j + (p - abs(i - k)) < m)
					right += val[k][j + (p - abs(i - k))];
				if (k >= 0 && k < n &&
						j - (p - abs(i - k)) >= 0)
					left -= val[k][j - (p - abs(i - k))];
			}

			lans += right;
			lans -= left;

			if (lans > mx)
				mx = lans;
			if (lans < mn)
				mn = lans;
		}
	}

	printf("%lld %lld\n", mn, mx);
	return 0;
}
