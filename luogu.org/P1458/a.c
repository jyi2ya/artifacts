/*
ID:lindong6
PROG:frac1
LANG:C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read(void);
void uniq(void);
int gcd(int a, int b);
int cmp(const void *a, const void *b);

typedef struct frac {
	int x, y; /* x / y */
} frac;

frac num[100000];
int N, top;

int main(void)
{
	register int i, j;

	read();
	for (i = 0; i <= N; ++i)
		for (j = 1; j <= N; ++j) {
			int x, y, g;
			g = gcd(i, j);
			x = i / g; y = j / g;
			num[top].x = x;
			num[top].y = y;
			++top;
		}
	qsort(num, top, sizeof(frac), cmp);
	uniq();
	for (i = 0; i < top; ++i) {
		if ((double)num[i].x / num[i].y > 1.00)
			break;
		printf("%d/%d\n", num[i].x, num[i].y);
	}
	return 0;
}

int cmp(const void *pp, const void *pq)
{
	frac *p = (frac*)pp, *q = (frac*)pq;
	if ((((double)p->x) / p->y) - (((double)q->x) / q->y) > 0)
		return 1;
	else
		return -1;
}

void read(void)
{
	scanf("%d", &N);
}

int gcd(int a, int b)
{
	while (b) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

void uniq(void)
{
	int i, j, new_top;
	i = 0, j = 0, new_top = 0;
	while (i < top) {
		while (j < top && (memcmp(&num[i], &num[j], sizeof(frac)) == 0))
			++j;
		if (i != new_top)
			memcpy(&num[new_top], &num[i], sizeof(frac));
		++new_top;
		i = j;
	}
	top = new_top;
}
