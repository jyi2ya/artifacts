#include <stdio.h>
#include <string.h>
#include <math.h>

int tmp[2509];
int mul[2509];
int ans[2509];

int main(void)
{
	register int i, j;
	int n;
	scanf("%d", &n);
	printf("%d\n", (int)(log10(2) * n + 1));

	ans[0] = 1;
	mul[0] = 2;

	while (n) {
		if (n & 1) {
			memset(tmp, 0, sizeof(tmp));
			for (i = 0; i < 500; ++i)
				for (j = 0; j < 500; ++j)
					tmp[i + j] += ans[i] * mul[j];
			for (i = 0; i < 2000; ++i) {
				tmp[i + 1] += tmp[i] / 10;
				tmp[i] %= 10;
			}
			memcpy(ans, tmp, sizeof(ans));
		}
		memset(tmp, 0, sizeof(tmp));
		for (i = 0; i < 500; ++i)
			for (j = 0; j < 500; ++j)
				tmp[i + j] += mul[i] * mul[j];
		for (i = 0; i < 2000; ++i) {
			tmp[i + 1] += tmp[i] / 10;
			tmp[i] %= 10;
		}
		memcpy(mul, tmp, sizeof(mul));
		n /= 2;
	}
	--ans[0];
	for (i = 499; i >= 0; --i) {
		if ((i + 1) % 50 == 0 && i != 499)
			putchar('\n');
		printf("%d", ans[i]);
	}
	putchar('\n');
	return 0;
}

