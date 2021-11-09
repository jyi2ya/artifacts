#include <stdio.h>
#include <string.h>

int palindrom(const char *str);
int min(int a, int b);

char s[51000009];

int main(void)
{
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%s", s);
	printf("%d\n", palindrom(s));
	return 0;
}

char buf[51000009];
int length[51000009];
int palindrom(const char *str)
{
	int top = 0, right, mid, i, l;
	buf[top++] = '*';
	do {
		buf[top++] = *str++;
		buf[top++] = '*';
	} while (*str);
	buf[top] = '\0';

	length[0] = 1;
	mid = 0;
	right = 0;

	for (i = 2; buf[i] != '\0'; ++i) {
		for (
				l = (i > right) ? 0 : min(length[mid * 2 - i], right - i);
				i - l >= 0 && buf[i - l] == buf[i + l];
				++l
		    );
		length[i] = l;
		if (i + l > right) {
			right = i + l;
			mid = i;
		}
	}

	l = 0;
	for (i = 0; buf[i] != '\0'; ++i)
		if (length[i] > l)
			l = length[i];
	/*
	for (i = 0; buf[i] != '\0'; ++i)
		printf("%d ", length[i]);
	putchar('\n');
	for (i = 0; buf[i] != '\0'; ++i)
		printf("%c ", buf[i]);
	putchar('\n');
	*/

	return l - 1;
}

int min(int a, int b)
{
	return a < b ? a : b;
}
