#include <stdio.h>

int a[30009];

int main(void)
{
	int i, j, k;
	int n;
	int ans = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (i = 0; i < n; ++i)
		for (j = i + 1; j < n; ++j)
			for (k = j + 1; k < n; ++k)
				if (a[i] < a[j] && a[j] < a[k])
					++ans;

	printf("%d\n", ans);
	return 0;
}
