#include <stdio.h>

int num[3];

int min(int a, int b);
int max(int a, int b);

int main(void)
{
	int ch;
	int c, a, t, less, more;
	while ((ch = getchar()) != EOF) {
		switch(ch) {
			case 'c' : ++num[0]; break;
			case 'a' : ++num[1]; break;
			case 't' : ++num[2]; break;
			default : break;
		}
	}
	less = min(min(num[0], num[1]), num[2]);
	more = max(max(num[0], num[1]), num[2]);
	c = more - num[0];
	a = more - num[1];
	t = more - num[2];
	printf("%d\n%d\n%d\n%d", less, c, a, t);
	return 0;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
