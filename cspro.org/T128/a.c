#include <stdio.h>

int h[10009] = {0};

int main(void)
{
	int i, j;
	int n, m, l;

	scanf("%d%d%d", &n, &m, &l);

	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j) {
			int t;
			scanf("%d", &t);
			++h[t];
		}

	printf("%d", h[0]);
	for (i = 1; i < l; ++i)
		printf(" %d", h[i]);
	printf("\n");
	return 0;
}
