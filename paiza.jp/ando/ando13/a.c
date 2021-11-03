#include <stdio.h>

int main(void)
{
	long long N, i, ans = 1, num2 = 0, num5 = 0;
	scanf("%lld", &N);
	for (i = 1; i <= N; ++i) {
		long long now = i;
		while (now % 2 == 0 || now % 5 == 0) {
			if (now % 2 == 0) {
				++num2;
				now /= 2;
			}
			if (now % 5 == 0) {
				++num5;
				now /= 5;
			}
		}
		ans = ans * now % 1000000000;
	}
	if (num2 > num5) {
		num2 -= num5;
		for (i = 0; i < num2; ++i)
			ans = ans * 2 % 1000000000;
	} else {
		num5 -= num2;
		for (i = 0; i < num5; ++i)
			ans = ans * 5 % 1000000000;
	}
	printf("%lld\n", ans);
	return 0;
}
