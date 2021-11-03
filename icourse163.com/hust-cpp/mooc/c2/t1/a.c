#if 0
cc -std=c89 -Wall -Werror -Wshadow -lm -O2 -pedantic "$0" -o /tmp/a$$.out || exit
/tmp/a$$.out
ret=$?
rm /tmp/a$$.out
exit $ret
#endif

#include <stdio.h>
#include <math.h>

int main(void)
{
	double x;
	scanf("%lf", &x);
	printf("%g\n", pow(2, x) + 1);
	return 0;
}
