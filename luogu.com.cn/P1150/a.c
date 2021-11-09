#include <stdio.h>

int main(void)
{
	int n, k;
	int ans = 0;
	int tmp = 0;
	scanf("%d%d", &n, &k);
	while (n) {
		--n;
		++ans;
		++tmp;
		if (tmp == k) {
			++n;
			tmp = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
