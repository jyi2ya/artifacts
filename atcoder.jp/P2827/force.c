#include <stdio.h>

#define MAX 100009

void read(void);

int a[MAX], n;
int ans[MAX];

int max(int a, int b);

int main(void)
{
	register int i, j;
	int realans = 0;
	read();

	for (i = 0; i < n; ++i)
		ans[i] = 1;
	for (i = 0; i < n; ++i)
		for (j = 0; j < i; ++j)
			if (a[j] < a[i])
				ans[i] = max(ans[i], ans[j] + 1);
	for (i = 0; i < n; ++i)
		realans = max(ans[i], realans);
	printf("%d\n", realans);
	return 0;
}

void read(void)
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", a + i);
}

int max(int a, int b)
{
	return a > b ? a : b;
}
