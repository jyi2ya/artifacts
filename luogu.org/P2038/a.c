#include <stdio.h>

int num[130][130];

int main(void)
{
	int i, j, k, l;
	int x, y;
	int d;
	int n;
	int ans = 0;
	int cnt = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d", &d);
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d%d%d", &x, &y, &k);
		num[x][y] = k;
	}

	for (i = 0; i < 129; ++i)
		for (j = 0; j < 129; ++j) {
			int lans = 0;
			for (k = i - d; k <= i + d; ++k)
				for (l = j - d; l <= j + d; ++l)
					if (k >= 0 && l >= 0 && 
							k < 129 && l < 129)
						lans += num[k][l];
			if (lans > ans)
				ans = lans;
		}

	for (i = 0; i < 129; ++i)
		for (j = 0; j < 129; ++j) {
			int lans = 0;
			for (k = i - d; k <= i + d; ++k)
				for (l = j - d; l <= j + d; ++l)
					if (k >= 0 && l >= 0 && 
							k < 129 && l < 129)
						lans += num[k][l];
			if (lans == ans)
				++cnt;
		}

	printf("%d %d\n", cnt, ans);
	return 0;
}
