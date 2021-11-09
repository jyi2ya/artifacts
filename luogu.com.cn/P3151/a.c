#include <stdio.h>

int ans[32];

unsigned long long solve(int k, int a, int b)
{
	int mid = 1 << (k - 1);
	if (a == 1 && b == (1 << k))
		return ans[k];
	if (k == 0) 
		return 1;
	if (mid >= a) {
		if (b <= mid)
			return solve(k - 1, a, b) * 2;
		else
			return solve(k - 1, a, mid) * 2 +
				solve(k - 1, 1, b - mid);
	} else {
		return
			solve(k - 1, a - mid, b - mid);
	}
	return 0;
}

void init(void)
{
	int i;
	ans[0] = 1;
	for (i = 1; i < 32; ++i)
		ans[i] = ans[i - 1] * 3;
}

int main(void)
{
	int k, a, b;
	init();
	while (scanf("%d%d%d", &k, &a, &b) != EOF)
		printf("Case %d: %llu\n", cases, solve(k, a, b));
	return 0;
}
