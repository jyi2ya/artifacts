#if 0
cc -std=c89 -Wall -Werror -Wshadow -O2 -pedantic "$0" -o /tmp/a$$.out || exit
/tmp/a$$.out
ret=$?
rm /tmp/a$$.out
exit $ret
#endif

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;

	do ch = getchar(); while (!isalpha(ch));
	printf("%d  ", ch++);
	printf("%d  ", ch++);
	printf("%d\n", ch++);
	return 0;
}
