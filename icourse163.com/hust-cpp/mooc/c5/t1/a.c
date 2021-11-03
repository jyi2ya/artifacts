#if 0
cc -std=c89 -Wall -Werror -Wshadow -O2 -pedantic "$0" -o /tmp/a$$.out || exit
/tmp/a$$.out
ret=$?
rm /tmp/a$$.out
exit $ret
#endif

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char str[1009];
	char *p;
	int cnt = 0;

	scanf("%s", str);
	
	for(p = str; *p != '\0'; ++p)
		if (islower(*p)) {
			*p = toupper(*p);
			++cnt;
		}

	printf("%s\n%d\n", str, cnt);
	return 0;
}
