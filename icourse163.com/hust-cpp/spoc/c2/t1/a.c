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
	float x;
	scanf("%f", &x);
	printf("y=%g\n", sqrt((1.0 - cos(x * 2.0 * 3.14159 / 360.0)) / 2.0));
	return 0;
}
