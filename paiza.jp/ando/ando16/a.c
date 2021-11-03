#include <stdio.h>
#include <stdlib.h>

int vis[1009], ans[1009], top = 0;
int cmp(const void *a, const void *b)
{
	return *((int*)a) - *((int*)b);
}

int main(void)
{
	int N, i, M1, M2;
	scanf("%d", &N);
	scanf("%d", &M1);
	for (i = 0; i < M1; ++i) {
		int n;
		scanf("%d", &n);
		vis[n] = 1;
	}
	scanf("%d", &M2);
	for (i = 0; i < M2; ++i) {
		int n;
		scanf("%d", &n);
		if (!vis[n])
			ans[top++] = n;
	}
	if (!top) {
		printf("None");
	} else {
		qsort(ans, top, sizeof(int), cmp);
		for (i = 0; i < top; ++i) {
			if (i)
				putchar(' ');
			printf("%d", ans[i]);
		}
	}
	return 0;
}
