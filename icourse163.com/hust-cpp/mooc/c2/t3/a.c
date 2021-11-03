#if 0
cc -std=c89 -Wall -Werror -Wshadow -O2 -pedantic "$0" -o /tmp/a$$.out || exit
/tmp/a$$.out
ret=$?
rm /tmp/a$$.out
exit $ret
#endif

#include <stdio.h>

int main(void)
{
	int x;
	scanf("%d", &x);
	printf("%d\n", (x / 100) + (x / 10 % 10 * 10) + (x % 10 * 100));
	return 0;
}
