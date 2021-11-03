/*
 * 手写浮点数会萎……
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) {
		double ans = 0.0;
		char *p;
		int x;
		/* happy */
		size_t len;
		static char str[1000009];
		scanf("%d%s", &x, str);
		for (p = str; *p; ++p)
			ans += log10(*p - '0');
		len = strlen(str);
		ans += len * (len - 1) / 2 * log10(x);;
		printf("%.0f\n", floor(ans) + 1.0);
	}
}
