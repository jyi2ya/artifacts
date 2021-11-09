#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fix {
	int x, y, t;
} fix;

int cmp(const void *a, const void *b)
{
	return ((fix*)a)->t - ((fix*)b)->t;
}

fix repair[100009];

void init(void);
int con(int a, int b);
void merge(int a, int b);
int size(void);
int N, M;

int main(void)
{
	int i;
	scanf("%d%d", &N, &M);
	for (i = 0; i < M; ++i)
		scanf("%d%d%d", &repair[i].x, &repair[i].y, &repair[i].t);
	init();
	qsort(repair, M, sizeof(fix), cmp);
	for (i = 0; i < M; ++i) {
		if (!con(repair[i].x, repair[i].y))
			merge(repair[i].x, repair[i].y);
		if (size() == 1)
			break;
	}
	if (size() == 1)
		printf("%d\n", repair[i].t);
	else
		puts("-1");
	return 0;
}

int ufs[1009], count;
int find(int x)
{
	if (ufs[x] == x)
		return x;
	return ufs[x] = find(ufs[x]);
}

void init(void)
{
	int i;
	for (i = sizeof(ufs) / sizeof(int) - 1; i >= 0; --i)
		ufs[i] = i;
	count = N;
}

int con(int a, int b)
{
	return find(a) == find(b);
}

void merge(int a, int b)
{
	if (con(a, b))
		return;
	ufs[find(a)] = find(b);
	--count;
}

int size(void)
{
	return count;
}
