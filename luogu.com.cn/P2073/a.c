#include <stdio.h>
#include <stdlib.h>

struct flower {
	int w, c;
};

int cmp(const void *a, const void *b)
{
	return ((struct flower*)a)->c - ((struct flower*)b)->c;
}

struct flower flw[1000009];
int bottom = 0, top = 0;
int size = 0;

int empty(void)
{
	return bottom == top;
}

void push(int w, int c)
{
	flw[top].w = w;
	flw[top].c = c;
	++top;
	++size;
}

struct flower* pop(void)
{
	--size;
	return flw + (--top);
}

struct flower* shift(void)
{
	--size;
	return flw + (bottom++);
}

void sort(void)
{
	qsort(flw + bottom, size, sizeof(flw[0]), cmp);
}

#define foreach(i) \
	for (i = flw + bottom; i != flw + top; ++i)

int vis[1000009];

int main(void)
{
	int op;
	int wc = 0, cc = 0;
	struct flower *i;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif

	while (scanf("%d", &op) == 1 && op != -1) {
		if (op == 1) {
			int w, c;
			scanf("%d%d", &w, &c);
			if (vis[c])
				continue;
			vis[c] = 1;
			push(w, c);
		} else if (op == 2) {
			if (empty())
				continue;
			sort();
			vis[pop()->c] = 0;
		} else if (op == 3) {
			if (empty())
				continue;
			sort();
			vis[shift()->c] = 0;
		}
	}

	foreach (i) {
		wc += i->w;
		cc += i->c;
	}

	printf("%d %d\n", wc, cc);

	return 0;
}
