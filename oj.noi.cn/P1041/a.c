#include <stdio.h>
#include <stdlib.h>

#define MAX (5009)

typedef struct member {
	int i, s;
} member;
member a[MAX];

int cmp(const void *a, const void *b)
{
	if (((member*)b)->s == ((member*)a)->s)
		return ((member*)a)->i - ((member*)b)->i;
	return ((member*)b)->s - ((member*)a)->s;
}

int main(void)
{
	int n, m, i, line, num;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i)
		scanf("%d%d", &a[i].i, &a[i].s);
	qsort(a, n, sizeof(member), cmp);
	line = a[(int)(m * 1.5 - 0.001)].s;
	for (num = 0; a[num].s >= line; ++num);

	printf("%d %d\n", line, num);
	for (i = 0; i < num; ++i)
		printf("%d %d\n", a[i].i, a[i].s);
	putchar('\n');
	return 0;
}
