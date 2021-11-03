#include <stdio.h>

int main(void)
{
	int l, r;
	int i;
	int ans = 0;

	scanf("%d%d", &l, &r);
	for (i = l; i <= r; ++i)
		if ((i & 1) || !(i % 4))
			++ans;

	printf("%d\n", ans);
	return 0;
}
