#if 0
cc -std=c89 -Wall -Werror -Wshadow -O2 -lm -pedantic "$0" -o /tmp/a$$.out || exit
/tmp/a$$.out
ret=$?
rm /tmp/a$$.out
exit $ret
#endif

#include <stdio.h>
#include <math.h>

int main(void)
{
	int x;
	int a, b;

	scanf("%d", &x);
	a = x / 100;
	b = x % 100;

	printf("%d   %d\n", a, b);
	printf("%.2f\n", sqrt(a) / sqrt(b));
	printf("%d\n", a % b);

	return 0;
}
