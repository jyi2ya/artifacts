#if 0
name="a"
gcc -Wall -Werror -Wshadow -fsanitize=address -O0 -g "$name".c -o /tmp/"$name"-$$ || exit 1
/tmp/"$name"-$$ "$@"
ret=$?
rm /tmp/"$name"-$$
exit $ret
#endif

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(void)
{
	static int x[2000009];
	int n;
	int i;
	scanf("%*d%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", &x[i]);
	qsort(x, n, sizeof(*x), cmp);
	for (i = 0; i < n; ++i)
		printf("%d ", x[i]);
	putchar('\n');
	return 0;
}
