#if 0
name="a"
gcc -lm -Wall -Werror -Wshadow -fsanitize=address -O0 -g "$name".c -o /tmp/"$name"-$$ || exit 1
/tmp/"$name"-$$
ret=$?
rm /tmp/"$name"-$$
exit $ret
#endif

#include <stdio.h>
#include <math.h>

int main(void)
{
	int i;
	double h = 100;
	double tot = 0;
	double pw;
	int n;

	scanf("%d", &n);

	for (i = 0, pw = 1; i < n; ++i, pw *= 2)
		tot += h * 2 / pw;
	tot -= h;
	printf("第%d次落地时，共经过%.4f米，反弹高度是%.4f米。\n", n, tot, h / pw);
	return 0;
}
