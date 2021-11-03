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
	if (x < 4)
		x = (x + 7) / (2 * x - 1);
	else if (x < 70)
		x = 3 * x * x + 5;
	else
		x = x - sqrt(4 * x - 1);
	printf("y=%.2f\n", x);
	return 0;
}
