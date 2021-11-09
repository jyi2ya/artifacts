#if 0
name="a"
gcc -Wall -Werror -Wshadow -fsanitize=address -O0 -g "$name".c -o /tmp/"$name"-$$ || exit 1
/tmp/"$name"-$$ "$@"
ret=$?
rm /tmp/"$name"-$$
exit $ret
#endif

#include <stdio.h>

int mat[1009][1009];
int tmp[1009][1009];

#define p2(x) (x)

void rotate(int x, int y, int z, int r)
{
	register int i, j, k, l;
	for (i = x - r, k = y - r; i <= x + r && k <= y + r; ++i, ++k)
		for (j = y - r, l = x + r; j <= y + r && l >= x - r; ++j, --l)
			tmp[l][k] = mat[i][j];
	for (i = x - r; i <= x + r; ++i)
		for (j = y - r; j <= y + r; ++j)
			mat[i][j] = tmp[i][j];
}

int main(void)
{
	int n, m;
	int i, j;
	scanf("%d%d", &n, &m);

	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			mat[i][j] = p2((i * n + j) + 1);

	while (m--) {
		int x, y, z, r;

		scanf("%d%d%d%d", &x, &y, &r, &z);
		--x; --y;
		rotate(x, y, z, r);
		if (z == 0) {
			rotate(x, y, z, r);
			rotate(x, y, z, r);
		}
	}

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j)
			printf("%d ", mat[i][j]);
		putchar('\n');
	}

	return 0;
}
