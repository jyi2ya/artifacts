#include <stdio.h>

#define MAX 4009

int a[MAX], b[MAX], c[MAX], d[MAX];

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, i, j, p, q, ans = 0;
		scanf("%d", &n);
		for (i = 0; i < n; ++i)
			scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				for (p = 0; p < n; ++p)
					for (q = 0; q < n; ++q)
						if (a[i] + b[j] + c[p] + d[q] ==0)
							++ans;
		printf("%d\n", ans);
	}
	return 0;
}
