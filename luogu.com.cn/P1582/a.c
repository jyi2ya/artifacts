#include <stdio.h>

int count(long long x);
long long lowbit(long long N);

int main(void)
{
	long long N, K, ans = 0;

#ifdef DEBUG
	freopen("in", "r", stdin);
#endif
	scanf("%lld%lld", &N, &K);

	while (count(N) > K) {
		ans += lowbit(N);
		N += lowbit(N);
	}

	printf("%lld\n", ans);
	return 0;
}

int count(long long x)
{
	int ans = 0;
	while (x) {
		++ans;
		x -= lowbit(x);
	}
	return ans;
}

long long lowbit(long long N)
{
	return N & -N;
}
