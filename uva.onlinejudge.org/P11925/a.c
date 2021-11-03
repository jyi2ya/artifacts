#include <stdio.h>
#include <string.h>

int n;
int b[309];
char op[1000009];
int top;

void unshift(void)
{
	int i;
	int t = b[n - 1];
	for (i = n - 1; i >= 1; --i)
		b[i] = b[i - 1];
	b[0] = t;
	op[top++] = '2';
}

void swap(void)
{
	int t = b[0];
	b[0] = b[1];
	b[1] = t;
	op[top++] = '1';
}

int check(void)
{
	int i;
	for (i = 1; i < n; ++i)
		if (b[i] < b[i - 1])
			return 0;
	return 1;
}

int main(void)
{
	while (scanf("%d", &n) == 1 && n) {
		int i;
		top = 0;
		for (i = 0; i < n; ++i)
			scanf("%d", &b[i]);
		while (!check()) {
			if (b[0] < b[1] || (b[0] == n && b[1] == 1))
				unshift();
			else
				swap();
		}
		while (top)
			putchar(op[--top]);
		putchar('\n');
	}
	return 0;
}
