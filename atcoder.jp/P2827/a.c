#include <stdio.h>

#define MAX 1000009

int n, a[MAX], lis[MAX], top;

void read(void);
int lb(int x);

int main(void)
{
	int i;
	read();
	lis[top++] = a[0];
	for (i = 1; i < n; ++i) {
		if (a[i] > lis[top - 1])
			lis[top++] = a[i];
		else
			lis[lb(a[i])] = a[i];
	}
	printf("%d\n", top);
	return 0;
}

void read(void)
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", a + i);
}

int lb(int x)
{
	int l, r, mid;
	l = 0, r = top;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (lis[mid] >= x)
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}
