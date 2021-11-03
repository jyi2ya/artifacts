#include <stdio.h>


int main(void)
{
	register int i, j, k;
	int x[709], y[709];
	int n;
	int ans = 0;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d %d", x + i, y + i);

	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j) {
			if (j == i)
				continue;
			int tmp = 0;
			for (k = 0; k < n; ++k)
				if ((y[j] - y[i]) * (x[k] - x[i])  ==
						(y[k] - y[i]) * (x[j] - x[i]))
					++tmp;
			if (tmp > ans)
				ans = tmp;
		}

	printf("%d\n", ans);
}
