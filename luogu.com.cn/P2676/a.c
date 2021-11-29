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
	return *(int *)b - *(int *)a;
}

int main(void)
{
	int n;
	long long b;
	long long acc;
	int i;
	static int h[20009];
	scanf("%d%lld", &n, &b);
	for (i = 0; i < n; ++i)
		scanf("%d", &h[i]);
	qsort(h, n, sizeof(*h), cmp);
	acc = 0;
	for (i = 0; i < n; ++i) {
		acc += h[i];
		if (acc >= b)
			break;
	}
	printf("%d\n", i + 1);
	return 0;
}
