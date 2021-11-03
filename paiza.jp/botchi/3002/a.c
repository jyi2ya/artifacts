#include <stdio.h>
#include <string.h>
#include <ctype.h>

int alpha_and_num(const char *str);
int length_ok(const char *str);
int same_alnum(const char *str);

char buf[100];

int main(void)
{
	scanf("%s", buf);
	if (same_alnum(buf) && alpha_and_num(buf) && length_ok(buf))
		puts("Valid");
	else
		puts("Invalid");
	return 0;
}

int same_alnum(const char *str)
{
	int i;
	for (i = 2; str[i] != '\0'; ++i)
		if (str[i] == str[i - 1] && str[i] == str[i - 2])
			return 0;
	return 1;
}

int alpha_and_num(const char *str)
{
	int al = 0, nu = 0;
	while (*str != '\0') {
		al |= isalpha(*str);
		nu |= isdigit(*str);
		++str;
	}
	return al && nu;
}

int length_ok(const char *str)
{
	return strlen(str) >= 6;
}
