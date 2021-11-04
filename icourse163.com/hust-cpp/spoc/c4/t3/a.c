#if 0
name="a"
gcc -Wall -Werror -Wshadow -fsanitize=address -O0 -g "$name".c -o /tmp/"$name"-$$ || exit 1
/tmp/"$name"-$$ "$@"
ret=$?
rm /tmp/"$name"-$$
exit $ret
#endif

#include <stdio.h>

int main(void)
{
	long ans = 0;
	char *p;
	char s[1024];

	scanf("%s", s);

	for (p = s; *p != '\0'; ++p)
		if (*p >= '5')
			goto error;
		else
			ans = ans * 5 + *p - '0';
	printf("%ld\n", ans);
	return 0;
error:
	puts("Input error");
	return 0;
}
