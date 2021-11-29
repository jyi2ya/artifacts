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
	int n;
	int i;
	int cnt = 0;
	static int bgi[100009];
	int size;

	static int num[10009];
	scanf("%d", &n);
	for (cnt = 0; n >= 0; ++cnt) {
		num[cnt] = cnt + 2;
		n -= cnt + 2;
	}
	for (i = 0; i < cnt; ++i)
		if (num[i] == -n)
			num[i] = -1;
	if (n == -1) {
		num[cnt - 2] += num[cnt - 1] - 1;
		num[cnt - 1] = -1;
	}
	for (i = 0; i < cnt; ++i) {
		if (num[i] != -1)
			printf("%d ", num[i]);
	}
	putchar('\n');

	size = 1;
	bgi[0] = 1;
	for (i = 0; i < cnt; ++i) {
		int j;

		if (num[i] < 0)
			continue;

		for (j = 0; j < size; ++j)
			bgi[j] *= num[i];
		for (j = 0; j < size; ++j) {
			bgi[j + 1] += bgi[j] / 10;
			bgi[j] %= 10;
		}
		while (bgi[size]) {
			bgi[size + 1] += bgi[size] / 10;
			bgi[size] %= 10;
			++size;
		}
	}
	for (i = size - 1; i >= 0; --i)
		putchar(bgi[i] + '0');
	putchar('\n');

	return 0;
}
