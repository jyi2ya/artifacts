#include <stdio.h>

int n, d;
char buf[100005];

int main(void)
{
	while (scanf("%d%d", &n, &d) == 2 && !(n == 0 && d == 0)) {
		int i, j, now;
		scanf("%s", buf);
		d = n - d, now = 0;
		for (i = 0; i < d; ++i) {
			int max = now;
			for (j = now + 1; n - j >= d - i; ++j)
				if (buf[j] > buf[max])
					max = j;
			putchar(buf[max]);
			now = max + 1;
		}
		putchar('\n');
	}
	return 0;
}
