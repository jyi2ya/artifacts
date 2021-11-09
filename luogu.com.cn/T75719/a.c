#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char ch;
	while (!isdigit(getchar()));
	while (isdigit(getchar()));
	while (!isdigit(getchar()));
	while (isdigit(getchar()));
	while (!isdigit(ch = getchar()));
	do {
		putchar(ch);
	} while (isdigit(ch = getchar()));
	putchar('\n');
	return 0;
}
