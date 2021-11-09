#include <stdio.h>

int main(void)
{
	int l, r;
	int ans = 0;
	int i;

	scanf("%d%d", &l, &r);

	for (i = l; i <= r; ++i) {
		int tmp = i;
		while (tmp) {
			if (tmp % 10 == 2)
				++ans;
			tmp /= 10;
		}
	}

	printf("%d\n", ans);
	return 0;
}
