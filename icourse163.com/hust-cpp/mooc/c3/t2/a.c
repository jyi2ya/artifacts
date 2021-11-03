#if 0
cc -std=c89 -Wall -Werror -Wshadow -O2 -pedantic "$0" -o /tmp/a$$.out || exit
/tmp/a$$.out
ret=$?
rm /tmp/a$$.out
exit $ret
#endif

#include <stdio.h>

#define is3(x) ((x) % 3 == 0)
#define is7(x) ((x) % 7 == 0)

int main(void)
{
	int x;
	scanf("%d", &x);

	if (is3(x)) {
		if (is7(x))
			puts("既是3的倍数也是7的倍数");
		else
			puts("是3的倍数但不是7的倍数");
	} else {
		if (is7(x))
			puts("不是3的倍数但是7的倍数");
		else
			puts("既不是3的倍数也不是7的倍数");
	}

	return 0;
}
