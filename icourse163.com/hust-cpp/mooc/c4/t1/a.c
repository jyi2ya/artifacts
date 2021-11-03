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
	int n;
	double sum = 0;
	scanf("%d", &n);

	while (n--)
		sum += (double)(n + 2) / (double)(n + 1);

	printf("%g\n", sum);

	return 0;
}
