#if 0
cc -std=c89 -Wall -Werror -Wshadow -O2 -pedantic "$0" -o /tmp/a$$.out || exit
/tmp/a$$.out
ret=$?
rm /tmp/a$$.out
exit $ret
#endif

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char tpl[] = "           \t\n        \t  \t\n     \t  \t  \t\n";

int main(void)
{
	int ch;
	char *p;

	do ch = getchar(); while (isspace(ch));
	while ((p = strchr(tpl, '\t')) != NULL) *p = ch;
	printf("%s", tpl);

	return 0;
}
