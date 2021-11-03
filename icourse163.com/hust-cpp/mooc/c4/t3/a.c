#if 0
cc -std=c89 -Wall -Werror -Wshadow -O2 -pedantic "$0" -o /tmp/a$$.out || exit
/tmp/a$$.out
ret=$?
rm /tmp/a$$.out
exit $ret
#endif

#include <stdio.h>

long cons(long a, long n)
{
	long ans = 0;
	while (n--)
		ans = ans * 10 + a;
	return ans;
}

int main(void)
{
	long a, n;
	long ans = 0;
	scanf("%ld%ld", &a, &n);

	while (n--)
		ans += cons(a, n + 1);
	printf("s=%ld\n", ans);
	return 0;
}
