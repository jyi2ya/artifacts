#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct {
	int buf[100009], top, size;
} heap;

void init(heap* hp);
int isempty(heap* hp);
void push(int a, heap* hp);
int pop(heap* hp);
void prtheap(heap* hp);

void putull(unsigned long long x);

heap orz;

int main(void)
{
	int n;
	while (scanf("%d", &n) == 1 && n) {
		int ans = 0;
		init(&orz);
		while (n--) {
			int k;
			scanf("%d", &k);
			push(k, &orz);
		}
		for (; ;) {
			int a, b;
			a = pop(&orz);
			if (isempty(&orz)) break;
			b = pop(&orz);
			ans += a + b;
			push(a + b, &orz);
		}
		putull(ans); putchar('\n');
	}
	return 0;
}

void putull(unsigned long long x)
{
	char buf[64], *top = buf;
	if (x == 0) putchar('0');
	while (x) {
		*top++ = x % 10 + '0';
		x /= 10;
	}
	while (top != buf) putchar(*--top);
}

void swap(int* a, int* b);

void init(heap* hp)
{
	hp -> top = 1;
	hp -> size = 0;
	memset(hp -> buf, 0x7f, 100009 * sizeof(int));
}

int isempty(heap* hp)
{
	return hp -> size == 0;
}

int pop(heap* hp)
{
	int r = hp -> buf[1], pos = 1;
	hp -> buf[pos] = INT_MAX;
	while (pos < hp -> top) {
		int cmp = pos * 2;
		if (cmp + 1 < hp -> top && hp -> buf[cmp + 1] < hp -> buf[cmp])
			++cmp;
		swap(hp -> buf + cmp, hp -> buf + pos);
		pos = cmp;
	}
	--hp -> top;
	while (hp -> buf[hp -> top] == INT_MAX) --hp -> top;
	++hp -> top;
	--hp -> size;

	return r;
}

void push(int a, heap* hp)
{
	int p = hp -> top;
	++hp -> size;
	hp -> buf[hp -> top++] = a;

	while (p > 1) {
		int cmp = p / 2;
		if (hp -> buf[cmp] > hp -> buf[p]) {
			swap(hp -> buf + cmp, hp -> buf + p);
		} else {
			return;
		}
		p = cmp;
	}
}

void prtheap(heap* hp)
{
	int i;
	printf("heap:(%d) :", hp -> size);
	for (i = 1; i < hp -> top; ++i) printf("%d ", hp -> buf[i]);
	putchar('\n');
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

