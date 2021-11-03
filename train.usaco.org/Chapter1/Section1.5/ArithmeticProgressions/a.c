/*
ID:lindong6
PROG:ariprog
LANG:C
*/

#include <stdio.h>
#include <stdlib.h>

#define dbgout empty

int number[625900], top;
int ok[625900], top;
typedef struct ans {
	int a, b;
} ans;
ans final_ans[625900];
int anstop;
int N, M;

void read(void);
void empty(const char *aa, ...) { }
void uniq(void);
int cmp(const void *a, const void *b);
int ans_cmp(const void *a, const void *b);

int main(void)
{
	register int i, j, k;

	read();

	dbgout("unsort:\n");
	for (i = 0; i <= M; ++i)
		for (j = 0; j <= M; ++j) {
			number[top++] = i * i + j * j;
			ok[number[top - 1]] = 1;
			dbgout("i = %d, j = %d, number = %d\n", i, j, number[top - 1]);
		}

	qsort(number, top, sizeof(int), cmp);

	dbgout("sorted\n");
	for (i = 0; i < top; ++i)
		dbgout("%d ", number[i]);

	uniq();

	dbgout("queue\n");
	dbgout("top = %d\n", top);
	for (i = 0; i < top; ++i) /* first */
		for (j = i + 1; j < top; ++j) { /* second */
			int d = number[j] - number[i];

			dbgout("%d,%d: ", i, d);
			if (i + d * (N - 2) >= number[top - 1])
				break;

			for (k = 2; k < N; ++k) {
				int now = number[i] + d * k;
				dbgout("%d ", now);
				if (!ok[now])
					break;
			}
			dbgout("\n");
			if (k == N) {
				final_ans[anstop].a = number[i];
				final_ans[anstop].b = d;
				++anstop;
			}
		}

	qsort(final_ans, anstop, sizeof(ans), ans_cmp);
	if (anstop == 0)
		puts("NONE");
	else
		for (i = 0; i < anstop; ++i)
			printf("%d %d\n", final_ans[i].a, final_ans[i].b);
	return 0;
}

void read(void)
{
	freopen("ariprog.in", "r", stdin);
#ifndef LUOTIANYI
	freopen("ariprog.out", "w", stdout);
#endif
	scanf("%d%d", &N, &M);
}

int cmp(const void *a, const void *b)
{
	return (*(int*)a) - (*(int*)b);
}

int ans_cmp(const void *a, const void *b)
{
	ans *p = (ans*)a, *q = (ans*)b;
	if (p->b == q->b)
		return p->a - q->a;
	return p->b - q->b;
}

void uniq(void)
{
	register int i = 0, j = 0;
	for (i = 0; j < top;) {
		for (; number[i] == number[j] && j < top; ++j);
		number[++i] = number[j];
	}
	top = i;
	dbgout("\nuniq \n");
	for (i = 0; i < top; ++i)
		dbgout("%d ", number[i]);
	dbgout("\n");
}
