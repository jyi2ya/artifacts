#include <stdio.h>

int G[109][109];

int main(void)
{
	int n, m, i, j, k, l, o, p, a = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			scanf("%d", G[i] + j);

	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j)
			for (k = 1; k + i <= n && k + j <= m; ++k) {
				o = 1;
				for (l = i; l < i + k && o; ++l)
					for (p = j; p < j + k && o; ++p)
						if (!G[l][p])
							o = 0;
				if (o && k > a)
					a = k;
			}
	printf("%d\n", a);
	return 0;
}
