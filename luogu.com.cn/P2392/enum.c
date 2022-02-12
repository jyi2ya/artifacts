#include <stdio.h>

int main(void)
{
	int a[30], n;
	int i;
	unsigned int mask;
	int cost = 99999999;
	int tot = 0;

	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		tot += a[i];
	}

	for (mask = 0; mask < (1U << n); ++mask) {
		int j;
		int part1 = 0, part2 = 0;
		int diff;
		for (j = 0; j < n; ++j)
			if (mask & (1U << j))
				part1 += a[j];
			else
				part2 += a[j];
		diff = part1 - part2;
		diff = diff < 0 ? -diff : diff;
		cost = diff < cost ? diff : cost;
	}

	printf("%d\n", (tot + cost) / 2);
	return 0;
}
