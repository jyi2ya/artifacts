#include <stdio.h>

int main(void)
{
	int n, x, ans = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		if (x > 5)
			++ans;
	}
	printf("%d", ans);
	return 0;
}
