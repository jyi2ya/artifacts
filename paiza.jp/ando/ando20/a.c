#include <stdio.h>

int main(void)
{
	int N, i;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		/* 1:00 */
		int add, h = 1, m = 0;
		scanf("%d", &add);
		add /= 3;
		while (add--) {
			--m;
			if (m < 0) {
				--h;
				if (h < 0)
					h = 23;
				m = 59;
			}
		}
		if (i)
			putchar('\n');
		printf("%02d:%02d", h, m);
	}
	return 0;
}
