#include <stdio.h>

int N, W;

long long b[100009];

int main(void)
{
	int l, r;
	long long current = 0, ans = 0;
#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &N, &W);
	while (N--) {
		int x, bri;
		scanf("%d%d", &x, &bri);
		b[x] += bri;
	}
	l = 0, r = 0;
	for (r = 0; r < W; ++r)
		current += b[r];
	ans = current;
	while (r < 100009) {
		current -= b[l];
		++l;
		current += b[r];
		++r;
		if (current > ans)
			ans = current;
	}
	printf("%lld\n", ans);
	return 0;
}
