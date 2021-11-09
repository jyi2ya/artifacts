#include <stdio.h>

int main(void)
{
	int N, num2 = 0, num5 = 0, i, ans = 1;
	scanf("%d", &N);
	for (i = 1; i <= N; ++i) {
		int p = i;
		while (p % 2 == 0) {
			++num2;
			p /= 2;
		}
		while (p % 5 == 0) {
			++num5;
			p /= 5;
		}
		ans = ans * p % 10;
	}
	if (num2 > num5) {
		while (num2 > num5) {
			ans = ans * 2 % 10;
			--num2;
		}
	} else {
		while (num5 > num2) {
			ans = ans * 5 % 10;
			--num5;
		}
	}
	printf("%d\n", ans % 10);
	return 0;
}
