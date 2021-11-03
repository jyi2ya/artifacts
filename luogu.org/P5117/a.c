#include <stdio.h>

int s[109], t[109], b[109], N, timeline[1009];

int main(void)
{
	int i, j, ans = 0;
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		scanf("%d%d%d", s + i, t + i, b + i);
	for (i = 0; i < N; ++i)
		for (j = s[i]; j <= t[i]; ++j)
			timeline[j] += b[i];
	for (i = 0; i < 1009; ++i)
		if (timeline[i] > ans)
			ans = timeline[i];
	printf("%d\n", ans);
	return 0;
}
