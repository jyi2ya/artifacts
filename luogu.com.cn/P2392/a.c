#if 0
name="a"
gcc -Wall -Werror -Wshadow -fsanitize=address -O0 -g "$name".c -o /tmp/"$name"-$$ || exit 1
/tmp/"$name"-$$ "$@"
ret=$?
rm /tmp/"$name"-$$
exit $ret
#endif

#include <stdio.h>

int process(int n)
{
	int a[30];
	int i;
	unsigned int mask;
	int cost = 99999999;
	int tot = 0;

	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		tot += a[i];
	}
	for (mask = 0; mask < (1U << n); ++mask) {
		int j;
		int part1 = 0, part2 = 0;
		int diff;
		for (j = 0; j < n; ++j)
			if (mask & (1U << j))
				part1 += a[j];
			else
				part2 += a[j];
		diff = part1 - part2;
		diff = diff < 0 ? -diff : diff;
		cost = diff < cost ? diff : cost;
	}

	return (tot + cost) / 2;
}

int main(void)
{
	int s[10];
	int i;
	int ans = 0;

	for (i = 0; i < 4; ++i)
		scanf("%d", &s[i]);
	for (i = 0; i < 4; ++i)
		ans += process(s[i]);

	printf("%d\n", ans);
	return 0;
}
