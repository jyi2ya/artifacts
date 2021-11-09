#include <stdio.h>

int n, height[109], ascend[109], descend[109], ans = 0x7f7f7f7f;

int main(void)
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
		scanf("%d", height + i);
	ascend[0] = 1;
	for (i = 1; i < n; ++i) {
		int mx = 0;
		for (j = 0; j < i; ++j)
			if (height[j] < height[i] && ascend[j] > mx)
				mx = ascend[j];
		ascend[i] = mx + 1;
	}
	descend[n - 1] = 1;
	for (i = n - 2; i >= 0; --i) {
		int mx = 0;
		for (j = n - 1; j > i; --j)
			if (height[j] < height[i] && descend[j] > mx)
				mx = descend[j];
		descend[i] = mx + 1;
	}
	for (i = 0; i < n; ++i)
		if (n - ascend[i] - descend[i] + 1 < ans)
			ans = n - ascend[i] - descend[i] + 1;
	printf("%d\n", ans);
	return 0;
}
