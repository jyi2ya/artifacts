#if 0
name="a"
gcc -Wall -Werror -Wshadow -fsanitize=address -O0 -g "$name".c -o /tmp/"$name"-$$ || exit 1
/tmp/"$name"-$$ "$@"
ret=$?
rm /tmp/"$name"-$$
exit $ret
#endif

#include <stdio.h>

char map[109][109];
int num[109][109];

int n, m;

#define is_legal(y, x) ((y) >= 0 && (y) < n && (x) >= 0 && (x) < m)

#define check(y, x) (is_legal((y), (x)) ? \
		map[(y)][(x)] == '*' ? 1 : 0 \
		: 0)

int main(void)
{
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i)
		scanf("%s", map[i]);
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j) {
			num[i][j] += check(i - 1, j - 1);
			num[i][j] += check(i - 1, j);
			num[i][j] += check(i - 1, j + 1);
			num[i][j] += check(i, j - 1);
			num[i][j] += check(i, j);
			num[i][j] += check(i, j + 1);
			num[i][j] += check(i + 1, j - 1);
			num[i][j] += check(i + 1, j);
			num[i][j] += check(i + 1, j + 1);
		}

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j)
			putchar(map[i][j] == '*' ? '*' : num[i][j] + '0');
		putchar('\n');
	}
	return 0;
}
