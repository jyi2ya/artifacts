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
	int a[3][3];
	int i, j;

	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j)
			scanf("%d", &a[i][j]);
	return 0;
}
