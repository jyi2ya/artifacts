/*
ID:lindong6
PROG:barn1
LANG:C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int start, length;
} space;

int getint(void);
void read(void);
int cmp(const void *a, const void *b);

int M, S, C;
int a[209], cover[209], top = 0, top2 = 0;
space sp[209], sp2[209];

int main(void)
{
	register int i = 0;
	int more = 0;
	read();

	while (!a[S])
		--S;

	for (i = 1; i <= S && !a[i]; ++i);

	for (; i <= S;) {
		while (i <= S && a[i])
			++i;
		sp[top].start = i;

		while (i <= S && !a[i]) {
			++i;
			++sp[top].length;
		}
		++top;
	}

	qsort(sp, top, sizeof(space), cmp);

	for (i = 0, more = 1; i < top && more < M; ++i, ++more) {
		sp2[top2].start = sp[i].start;
		sp2[top2].length = sp[i].length;
		++top2;
	}

	memset(cover, 0xff, sizeof(cover));
	for (i = 1; i <= S && !a[i]; ++i)
		cover[i] = 0;
	for (i = 0; i < top2; ++i) {
		register int j;
		for (j = sp2[i].start; j < sp2[i].start + sp2[i].length; ++j)
			cover[j] = 0;
	}

	more = 0;
	for (i = 1; i <= S; ++i)
		if (cover[i])
			++more;

	/*
	for (i = 1; i <= S; ++i)
		putchar(cover[i] ? '#' : ' ');
	putchar('\n');
	for (i = 1; i <= S; ++i)
		putchar(a[i] ? '#' : ' ');
	putchar('\n');
	*/

	printf("%d\n", more);
	return 0;
}

int cmp(const void *p, const void *q)
{
	return (((space*)q)->length) - (((space*)p)->length);
}

void read(void)
{
	register int i;

	scanf("%d%d%d", &M, &S, &C);
	for (i = 0; i < C; ++i)
		a[getint()] = 1;
}

int getint(void)
{
	int t;
	scanf("%d", &t);
	return t;
}
