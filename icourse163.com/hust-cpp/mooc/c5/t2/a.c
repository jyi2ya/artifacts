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
	int i;
	int a[100];
	int targ;
	int found = 0;

	for (i = 0; i < 10; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &targ);

	for (i = 0; i < 10; ++i)
		if (a[i] == targ) {
			found = 1;
			printf("%d\n", i + 1);
		}

	if (!found)
		puts("数组中没有该数");

	return 0;
}
