#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void init(void);
int convert_string(const char *str);
int convert_char(char ch);

int num[10000009];
char buf[1009];

int main(void)
{
	int n, i, noans = 1;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", buf);
		++num[convert_string(buf)];
	}
	for (i = 0; i < 10000009; ++i)
		if (num[i] > 1) {
			printf("%03d-%04d %d\n", i / 10000, i % 10000, num[i]);
			noans = 0;
		}
	if (noans) {
		puts("No duplicates.");
	}
	return 0;
}

int convert_string(const char *str)
{
	char dbuf[23];
	int top = 0;
	while (*str != '\0') {
		if (isalnum(*str))
			dbuf[top++] = convert_char(*str) + '0';
		++str;
	}
	dbuf[top] = '\0';
	return atoi(dbuf);
}

int convert_char(char ch)
{
	if (ch == 'A')
		return 2;
	if (ch == 'B')
		return 2;
	if (ch == 'C')
		return 2;

	if (ch == 'D')
		return 3;
	if (ch == 'E')
		return 3;
	if (ch == 'F')
		return 3;

	if (ch == 'G')
		return 4;
	if (ch == 'H')
		return 4;
	if (ch == 'I')
		return 4;

	if (ch == 'J')
		return 5;
	if (ch == 'K')
		return 5;
	if (ch == 'L')
		return 5;

	if (ch == 'M')
		return 6;
	if (ch == 'N')
		return 6;
	if (ch == 'O')
		return 6;

	if (ch == 'P')
		return 7;
	if (ch == 'R')
		return 7;
	if (ch == 'S')
		return 7;

	if (ch == 'T')
		return 8;
	if (ch == 'U')
		return 8;
	if (ch == 'V')
		return 8;

	if (ch == 'W')
		return 9;
	if (ch == 'X')
		return 9;
	if (ch == 'Y')
		return 9;

	return ch - '0';
}
