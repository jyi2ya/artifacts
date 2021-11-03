#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a < *(int*)b ? -1 : 1;
}

int val[400009];
int top = 1;

void add(int x)
{
	val[top++] = x;
}

int get(void)
{
	static int i = 0;
	qsort(val + 1, top - 1, sizeof(int), cmp);
	return val[++i];
}

int main(void)
{
	int m, n;
	int i;
	static int buf[200009];
	static int pos[200009];
	int pt = 0;

	scanf("%d%d", &m, &n);
	for (i = 1; i <= m; ++i) {
		int t;
		scanf("%d", &t);
		buf[i] = t;
	}

	for (i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);
		pos[i] = t;
	}

	for (i = 1; i <= m; ++i) {
		add(buf[i]);
		while (pos[pt] == i) {
			printf("%d\n", get());
			++pt;
		}
	}

	return 0;
}
