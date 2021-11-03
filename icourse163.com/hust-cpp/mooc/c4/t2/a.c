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

	scanf("%d", &n);

	if (n < 10) {
		puts("0");
		return 0;
	}

	while (n >= 10) {
		int t = 0;
		while (n) {
			t += n % 10;
			n /= 10;
		}
		n = t;
	}

	printf("%d\n", n);

	return 0;
}
