#include <stdio.h>

#define MAX 5000010

int palindrome(const char *str);
int min(int a, int b);

char buf[MAX];

int main(void)
{
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", buf);
		printf("%d\n", palindrome(buf));
	}
	return 0;
}

int length[MAX];
char sharp[MAX];
int palindrome(const char *str)
{
	int r, m, i, l, top = 0;
	while (*str) {
		sharp[top++] = '`';
		sharp[top++] = *str++;
	}
	sharp[top++] = '`';
	sharp[top++] = '\0';

	length[0] = 1;
	m = 0;
	r = 0;
	for (i = 1; sharp[i] != '\0'; ++i) {
		for (
				l = (i > r) ? 1 : min(length[m * 2 - i], r - i);
				i - l >= 0 && sharp[i - l] == sharp[i + l];
				++l
		    );
		length[i] = l;
		if (l + i > r) {
			r = l + i;
			m = i;
		}
	}

	l = 0;
	for (i = 0; sharp[i] != '\0'; ++i)
		if (length[i] > l)
			l = length[i];
	return l - 1;
}

int min(int a, int b)
{
	return a < b ? a : b;
}
