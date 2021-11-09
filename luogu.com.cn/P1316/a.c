#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int a, b;
int pos[100009];

void read(void);
int check(int mid);

int main(void)
{
	int l = 0, r = INT_MAX;
	read();
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (check(mid))
			l = mid + 1;
		else
			r = mid;
	}
	printf("%d\n", l);
	return 0;
}

int check(int mid)
{
	int last = 0, cnt = 1, i;
	for (i = 1; i < a; ++i) {
		if (pos[i] - pos[last] > mid) {
			++cnt;
			last = i;
		}
	}
	return cnt >= b;
}

int cmp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

void read(void)
{
	int i;
#ifdef DEBUG
	freopen("testdata.in", "r", stdin);
#endif
	scanf("%d%d", &a, &b);
	for (i = 0; i < a; ++i)
		scanf("%d", pos + i);
	qsort(pos, a, sizeof(int), cmp);
}
