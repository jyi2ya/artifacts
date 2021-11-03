#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	double a = 0;
	char buf[30];
	int c;
	while (!isdigit(c = getchar()));
	do {
		a += c - '0';
	} while (isdigit(c = getchar()));
	sprintf(buf, "%f", a / 2);
	for (c = strlen(buf) - 1; buf[c] == '0'; --c);
	if (buf[c] == '.')
		buf[c] = '\0';
	else
		buf[c + 1] = '\0';
	puts(buf);
	return 0;
}
