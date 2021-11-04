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
	long n;
	long i;
	double ans = 0;
	scanf("%ld", &n);

	if (n <= 0) {
		ans = 0;
	} else {
		/* 1/n(1^2+2^2+3^2+⋯+n^2) */
		for (i = 1; i <= n; ++i)
			ans += i * i;
		ans /= n;
	}

	printf("表达式的值=%g\n", ans);
	return 0;
}
