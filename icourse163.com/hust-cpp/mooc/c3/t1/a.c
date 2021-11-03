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
	double x;
	scanf("%lf", &x);

	if (x <= 5)
		puts("10");
	else
		printf("%d\n", (int)(x - 5 + 1.999) / 2 * 5 + 10);
	return 0;
}
