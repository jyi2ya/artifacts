#include <stdio.h>

int main(void)
{
	int n;
	int ans = 0;
	scanf("%d", &n);
	while (n--) {
		int t;
		scanf("%d", &t);
		ans ^= t;
	}
	printf("%d\n", ans);
	return 0;
}
