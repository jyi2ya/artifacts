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

	if (x >= 90)
		puts("A  grade");
	else if (x >= 80)
		puts("B  grade");
	else if (x >= 70)
		puts("C  grade");
	else if (x >= 60)
		puts("D  grade");
	else
		puts("Not  passed");
	return 0;
}
