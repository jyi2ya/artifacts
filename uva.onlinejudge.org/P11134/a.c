/* #!/usr/bin/tcc -run -DDEBUG -Wall -Werror */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;

typedef struct range {
	int l, r, id;
} range;

#define MAX 5009

range possible_x[MAX], possible_y[MAX];
int vis[MAX], ans_x[MAX], ans_y[MAX];

int cmp(const void* a, const void* b)
{
	range *p = (range*)a, *q = (range*)b;
	if (p -> r == q -> r) return p -> l - q -> l;
	return p -> r - q -> r;
}

int main(void)
{
	while (scanf("%d", &n) == 1 && n ) {
		int i, j;
		for (i = 1; i <= n; ++i) {
			int xl, yl, xr, yr;
			scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
			possible_x[i].l = xl, possible_x[i].r = xr;
			possible_y[i].l = yl, possible_y[i].r = yr;
			possible_x[i].id = i, possible_y[i].id = i;
		}

		qsort(possible_x + 1, n, sizeof(range), cmp);
		qsort(possible_y + 1, n, sizeof(range), cmp);

		memset(vis, 0, sizeof(vis));
		for (i = 1; i <= n; ++i) {
			for (j = possible_x[i].l; j <= possible_x[i].r; ++j)
				if (!vis[j]) break;
			if (j > possible_x[i].r) goto IMP;
			vis[j] = 1;
			ans_x[possible_x[i].id] = j;
		}
		memset(vis, 0, sizeof(vis));
		for (i = 1; i <= n; ++i) {
			for (j = possible_y[i].l; j <= possible_y[i].r; ++j)
				if (!vis[j]) break;
			if (j > possible_y[i].r) goto IMP;
			vis[j] = 1;
			ans_y[possible_y[i].id] = j;
		}

		for (i = 1; i <= n; ++i) printf("%d %d\n", ans_x[i], ans_y[i]);
		continue;

IMP:
		puts("IMPOSSIBLE");
	}
	return 0;
}
