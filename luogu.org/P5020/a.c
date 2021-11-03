#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(void)
{
	int T;

#ifdef DEBUG
	freopen("in", "r", stdin);
	setvbuf(stdout, NULL, _IONBF, 0);
#endif

	scanf("%d", &T);
	while (T--) {
		static int a[25009];
		static int can[1000009];
		int ans = 0;
		int n;
		int i, j;
		scanf("%d", &n);
		for (i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		qsort(a, n, sizeof(*a), cmp);
		memset(can, 0, sizeof(can));
		for (i = 0; i < n; ++i)
			if (!can[a[i]]) {
				++ans;
				can[a[i]] = 1;
				for (j = 0; j + a[i] < 25009; ++j)
					can[j + a[i]] |= can[j];
			}
		printf("%d\n", ans);
	}
	return 0;
}
