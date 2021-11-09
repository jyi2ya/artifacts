#if 0
name="a"
gcc -Wall -Werror -Wshadow -fsanitize=address -O0 -g "$name".c -o /tmp/"$name"-$$ || exit 1
/tmp/"$name"-$$ "$@"
ret=$?
rm /tmp/"$name"-$$
exit $ret
#endif

#include <stdio.h>
#include <string.h>

int main(void)
{
	long long n;
	static int bgi[100009];
	int x;

	scanf("%*d");
	while (scanf("%lld%d", &n, &x) == 2) {
		int cnt = 0;
		int width = 1;
		int i;

		memset(bgi, 0, sizeof(bgi));
		bgi[0] = 1;

		for (; n >= 1; --n) {
			for (i = 0; i < width; ++i)
				bgi[i] *= n;
			for (i = 0; i < width; ++i) {
				bgi[i + 1] += bgi[i] / 10;
				bgi[i] %= 10;
			}
			while (bgi[width]) {
				bgi[width + 1] = bgi[width] / 10;
				bgi[width] %= 10;
				++width;
			}
		}

		for (i = 0; i < width; ++i)
			if (bgi[i] == x)
				++cnt;

		printf("%d\n", cnt);
	}
	return 0;
}
