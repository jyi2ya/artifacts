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
	x *= 1.0275;
	x *= 1.0275;
	x *= 1.0275;
	printf("捐款金额为：%.2f\n", x);
	return 0;
}
