#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct p {
	int l, r, h;
} p;

p a[1009];
int N;

int main(void)
{
	int i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
		scanf("%d%d%d", &a[i].h, &a[i].l, &a[i].r);
	a[0].h = 0; a[0].l = -INT_MAX; a[0].r = INT_MAX;
	for (i = 1; i <= N; ++i) {
		int ans = 0;
		for (j = 1; j <= N; ++j)
			if (a[ans].h < a[j].h && a[j].h < a[i].h
				       	&& a[j].l < a[i].l && a[i].l < a[j].r)
				ans = j;
		printf("%d ", ans);
		ans = 0;
		for (j = 1; j <= N; ++j)
			if (a[ans].h < a[j].h && a[j].h < a[i].h
					&& a[j].l < a[i].r && a[i].r < a[j].r)
				ans = j;
		printf("%d\n", ans);
	}
	return 0;
}
